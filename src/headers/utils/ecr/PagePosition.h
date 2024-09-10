#pragma once

#include <stdexcept>
#include <cstring>
#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport PagePosition {
public:
    enum Value : size_t {
        Head,
        Foot,
        Null
    };

    PagePosition();

    explicit PagePosition(
        Value value_
    );

    const char* getName();
    Value getValue();
    static Value getEnum(const char* name);
    bool operator==(const PagePosition& rhs);

private:
    Value value;
};