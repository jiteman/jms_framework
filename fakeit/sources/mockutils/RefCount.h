#pragma once


namespace fakeit {


class RefCount {
private:
	int count;

public:
	void AddRef();

	int Release();
};


} // namespace fakeit
