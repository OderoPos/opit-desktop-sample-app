#pragma once

#include "../../utils/ecr/VatRateType.h"

class VatRateType {
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