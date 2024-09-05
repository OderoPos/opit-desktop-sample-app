#pragma once

#include "../dll.h"
#include <stdexcept>
#include <cstring>

class DllExport ReportSize {
public:
    enum Value : size_t {
        Compressed,
        Extended
    };

    ReportSize();

    explicit ReportSize(
        Value value_
    );

    const char* getName();
    Value* getValue();
    static Value getEnum(const char* name);
    bool operator==(const ReportSize& rhs);

private:
    Value* value;
};