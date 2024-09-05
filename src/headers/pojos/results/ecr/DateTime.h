#pragma once

#include "../Result.h"

class DllExport DateTime {
private:
    char* value;

public:
    DateTime();

    explicit DateTime(
        const char* value_
    );

    ~DateTime();

    const char* getValue();
    void setValue(const char* value_);

    bool operator==(const DateTime& rhs);
    const char* toJson();
    static DateTime fromJson(const char* json);
    void toString();
};