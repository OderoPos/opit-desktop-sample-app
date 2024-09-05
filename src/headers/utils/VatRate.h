#pragma once

#include "../dll.h"
#include <stdexcept>
#include <cstring>

class DllExport VatRate {
public:
    enum Value : size_t {
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H
    };

    VatRate();

    explicit VatRate(
        const Value value_
    );

    const char* getName();
    static Value getEnum(const char* name);
    bool operator==(const VatRate& rhs);

private:
    Value value;
};