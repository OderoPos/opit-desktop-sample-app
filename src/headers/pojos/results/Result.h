#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <cstring>

class Result {
protected:
	char* uniqueId = nullptr;

	const char* getUniqueId();
	void setUniqueId(const char* uniqueId_);

public:
	virtual void toString() {
		assert(1 == 0); //force child classes to override this method
	}
};
