#pragma once

#include <stdexcept>
#include <cstring>
#include "../../utils/ecr/VatRateType.h"
#include "../../dll.h"

class DllExport VatRateType {
public:
    enum Value : size_t {
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        Null
    };

    VatRateType();

    explicit VatRateType(
        const Value value_
    );

    const char* getName();
    static Value getEnum(const char* name);
    bool operator==(const VatRateType& rhs);

private:
    Value value;
};