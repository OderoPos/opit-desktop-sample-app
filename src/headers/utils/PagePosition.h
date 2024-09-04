#pragma once

#include "../dll.h"
#include <stdexcept>
#include <cstring>

class DllExport PagePosition {
public:
    enum Value : size_t {
        Head,
        Foot
    };

    PagePosition();

    explicit PagePosition(
        Value value_
    );

    const char* getName();
    Value* getValue();
    static Value getEnum(const char* name);
    bool operator==(const PagePosition& rhs);

private:
    Value* value;
};