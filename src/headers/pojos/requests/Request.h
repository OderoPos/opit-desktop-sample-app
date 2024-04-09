#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <cstring>
#include "../../dll.h"

class Request {
public:
	virtual void toString() {
		assert(1 == 0); //force child classes to override this method
	}
};
