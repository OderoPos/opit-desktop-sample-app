#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <cstring>
#include "../../dll.h"

class DllExport Request {
public:
	virtual void toString() {
		assert(1 == 0); //force child classes to override this method
	}
};
