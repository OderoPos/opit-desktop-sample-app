#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <map>
#include <any>
#include "../dll.h"

std::map<std::string, std::any> toMap(const std::string& json);