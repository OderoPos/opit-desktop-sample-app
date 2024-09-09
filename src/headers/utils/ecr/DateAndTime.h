#pragma once

#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport DateAndTime {
private:
    char* value = NULL;

public:
    DateAndTime();

    explicit DateAndTime(
        const char* value_
    );

    ~DateAndTime();

    const char* getValue();
    void setValue(const char* value_);

    bool operator==(const DateAndTime& rhs);
    const char* toJson();
    static DateAndTime fromJson(const char* json);
    void toString();
};