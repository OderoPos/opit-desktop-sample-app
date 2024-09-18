#pragma once

#include "VatRates.h"

class VatRatesCommand {
private:
    VatRates* vatRates = nullptr;
    int vatRatesSize = 0;

public:
    VatRatesCommand();

    explicit VatRatesCommand(
        VatRates* vatRates_,
        int vatRatesSize_
    );

    ~VatRatesCommand();

    const VatRates* getVatRates();
    void setVatRates(VatRates* vatRates_, int vatRatesSize_);

    bool operator==(const VatRatesCommand& rhs);
    const char* toJson();
    static VatRatesCommand fromJson(const char* json);
    void toString();
};