#pragma once

#include <map>
#include "../dll.h"

template<class Arg1, class Arg2, class Result>
struct binary_function
{
	using first_argument_type = Arg1;
	using second_argument_type = Arg2;
	using result_type = Result;
};

struct StrCompare : public binary_function<const char*, const char*, bool> {
public:
	bool operator() (const char* str1, const char* str2) const {
		return std::strcmp(str1, str2) < 0;
	}
};

static std::map<const char*, const char*, StrCompare> currencyCode {
	{ "RON", "946" },
	{ "EUR", "978" },
	{ "USD", "840" }
};

static const char* getCurrencyCode(const char* currency) {
	return currencyCode[currency];
}

static bool isEmpty(const char* text) {
	return (text != NULL) && (text[0] == '\0');
}
