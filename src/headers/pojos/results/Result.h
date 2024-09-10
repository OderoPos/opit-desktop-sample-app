#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <cstring>
#include "../../dll.h"
#include "../../utils/StringUtils.h"

class DllExport Result {
protected:
	char* uniqueId;

	const char* getUniqueId();
	void setUniqueId(const char* uniqueId_);

public:
	virtual void toString() {
		assert(1 == 0); //force child classes to override this method
	}
};
