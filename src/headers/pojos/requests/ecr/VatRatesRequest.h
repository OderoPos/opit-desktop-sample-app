#pragma once

#include "../Request.h"
#include "../../../utils/VatRate.h"

class DllExport VatRatesRequest : public Request {
private:
    VatRate vatId;
    char* vatRate;

public:
    VatRatesRequest();

    explicit VatRatesRequest(
        const VatRate::Value vatId_,
        const char* vatRate_
    );

    ~VatRatesRequest();

    const VatRate getVatId();
    void setVatId(const VatRate vatId_);
    const char* getVatRate();
    void setVatRate(const char* vatRate_);

    bool operator==(const VatRatesRequest& rhs);
    const char* toJson();
    static VatRatesRequest fromJson(const char* json);
    void toString();
};