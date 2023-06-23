#pragma once

#include <iostream>
#include <map>
#include <any>
#include <winrt/Windows.Data.Json.h>
#include <winrt/Windows.Foundation.Collections.h>
#include "../dll.h"

using namespace winrt::Windows::Data::Json;

const char* jsonToString(JsonObject& jsonObject);
std::map<std::string, std::any> toMap(const std::string& json);