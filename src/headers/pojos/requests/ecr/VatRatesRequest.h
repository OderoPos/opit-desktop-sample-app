#pragma once

#include "../Request.h"
#include "../../../utils/ecr/VatRates.h"

class DllExport VatRatesRequest : public Request {
private:
    VatRates* vatRates = NULL;
    int vatRatesSize;

public:
    VatRatesRequest();

    explicit VatRatesRequest(
        VatRates* vatRates_,
        int vatRatesSize_,
        const char* uniqueId_
    );

    ~VatRatesRequest();

    const VatRates* getVatRates();
    void setVatRates(VatRates* vatRates_, int vatRatesSize_);

    bool operator==(const VatRatesRequest& rhs);
    const char* toJson();
    static VatRatesRequest fromJson(const char* json);
    void toString();
};