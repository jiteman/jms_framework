#include "StandaloneFakeit.h"


namespace fakeit {

	VerificationException::~VerificationException() NO_THROWS
	{}

	VerificationException::VerificationException(std::string format) : //
		_format(format) { //
	}

	// friend
	std::ostream &operator <<(std::ostream &os, const VerificationException &val) {
		os << val.what();
		return os;
	}

	void VerificationException::setFileInfo(std::string aFile, int aLine, std::string aCallingMethod) {
		_file = aFile;
		_callingMethod = aCallingMethod;
		_line = aLine;
	}

	const std::string& VerificationException::file() const {
		return _file;
	}
	int VerificationException::line() const {
		return _line;
	}
	const std::string& VerificationException::callingMethod() const {
		return _callingMethod;
	}

	const char* VerificationException::what() const NO_THROWS {
		return _format.c_str();
	}


	NoMoreInvocationsVerificationException::NoMoreInvocationsVerificationException(std::string format) : //
		VerificationException(format) { //
	}


	SequenceVerificationException::SequenceVerificationException(std::string format) : //
		VerificationException(format) { //
	}


	std::string StandaloneAdapter::formatLineNumner(std::string file, int num){
#ifndef __GNUG__
		return file + std::string("(") + fakeit::to_string(num) + std::string(")");
#else
		return file + std::string(":") + fakeit::to_string(num);
#endif
	}

	StandaloneAdapter::StandaloneAdapter(EventFormatter &formatter)
		: _formatter(formatter) {
	}

	void StandaloneAdapter::handle(const UnexpectedMethodCallEvent &evt) {
		std::string format = _formatter.format(evt);
		UnexpectedMethodCallException ex(format);
		throw ex;
	}

	void StandaloneAdapter::handle(const SequenceVerificationEvent &evt) {
		std::string format(formatLineNumner(evt.file(), evt.line()) + ": " + _formatter.format(evt));
		SequenceVerificationException e(format);
		e.setFileInfo(evt.file(), evt.line(), evt.callingMethod());
		throw e;
	}

	void StandaloneAdapter::handle(const NoMoreInvocationsVerificationEvent &evt) {
		std::string format(formatLineNumner(evt.file(), evt.line()) + ": " + _formatter.format(evt));
		NoMoreInvocationsVerificationException e(format);
		e.setFileInfo(evt.file(), evt.line(), evt.callingMethod());
		throw e;
	}


	StandaloneFakeit::StandaloneFakeit() : _standaloneAdapter(*this) {
	}

	// static
	StandaloneFakeit &StandaloneFakeit::getInstance() {
		static StandaloneFakeit instance;
		return instance;
	}

	fakeit::EventHandler &StandaloneFakeit::accessTestingFrameworkAdapter() {
		return _standaloneAdapter;
	}
}
