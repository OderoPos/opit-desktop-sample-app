#pragma once

#include <cassert>
#include <string>
//#include <sstream>
#include <iostream>
#include <cstring>
#include "../../dll.h"

class Result {
public:
	virtual void toString() {
		assert(1 == 0); //force child classes to override this method
	}
};
