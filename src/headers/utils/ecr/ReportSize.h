#pragma once

#include <cstring>
#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport ReportSize {
public:
    enum Value : size_t {
        Compressed,
        Extended,
        Null
    };

    ReportSize();

    explicit ReportSize(
        Value value_
    );

    const char* getName();
    Value getValue();
    static Value getEnum(const char* name);
    bool operator==(const ReportSize& rhs);

private:
    Value value;
};