#pragma once

#include "../../utils/ecr/VatRateType.h"
#include "../../utils/ecr/VatRateType.h"
#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport VatRates {
private:
    VatRateType vatId;
    char* vatRate = NULL;

public:
    VatRates();

    explicit VatRates(
        const VatRateType::Value vatId_,
        const char* vatRate_
    );

    ~VatRates();

    const VatRateType getVatId();
    void setVatId(const VatRateType vatId_);

    const char* getVatRate();
    void setVatRate(const char* vatRate_);

    bool operator==(const VatRates& rhs);
    const char* toJson();
    static VatRates fromJson(const char* json);
    void toString();
};