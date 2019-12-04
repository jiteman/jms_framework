#pragma once

#include "fakeit/DefaultFakeit.h"
#include "mockutils/to_string.hpp"


#include "mockutils/Macros.hpp"


namespace fakeit {

    struct VerificationException : public std::exception {
        virtual ~VerificationException() NO_THROWS;

        VerificationException(std::string format);

        friend std::ostream &operator <<(std::ostream &os, const VerificationException &val);

        void setFileInfo(std::string aFile, int aLine, std::string aCallingMethod);

        const std::string& file() const;
        int line() const;
        const std::string& callingMethod() const;

        const char* what() const NO_THROWS override;
    private:
        std::string _file;
        int _line;
        std::string _callingMethod;
        std::string _format;
    };

    struct NoMoreInvocationsVerificationException : public VerificationException {
        NoMoreInvocationsVerificationException(std::string format);
    };

    struct SequenceVerificationException : public VerificationException {
        SequenceVerificationException(std::string format);
    };

    struct StandaloneAdapter : public EventHandler {

        std::string formatLineNumner(std::string file, int num);

        virtual ~StandaloneAdapter() = default;

        StandaloneAdapter(EventFormatter &formatter);

        virtual void handle(const UnexpectedMethodCallEvent &evt) override;

        virtual void handle(const SequenceVerificationEvent &evt) override;

        virtual void handle(const NoMoreInvocationsVerificationEvent &evt) override;

    private:
        EventFormatter &_formatter;
    };

    class StandaloneFakeit : public DefaultFakeit {

    public:
        virtual ~StandaloneFakeit() = default;

        StandaloneFakeit();

        static StandaloneFakeit &getInstance();

    protected:

        fakeit::EventHandler &accessTestingFrameworkAdapter() override;

    private:

        StandaloneAdapter _standaloneAdapter;
    };
}
