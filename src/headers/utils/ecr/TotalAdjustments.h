#pragma once

#include "../../utils/ecr/VatRateType.h"

class TotalAdjustments {
private:
    VatRateType vatId;
    int discountSign = 0;
    int discountType = 0;
    char* discountValue = nullptr;

public:
    TotalAdjustments();

    explicit TotalAdjustments(
        const VatRateType::Value vatId_,
        const int discountSign_,
        const int discountType_,
        const char* discountValue_
    );

    ~TotalAdjustments();

    const VatRateType getVatId();
    void setVatId(const VatRateType vatId_);

    const int getDiscountSign();
    void setDiscountSign(const int discountSign_);

    const int getDiscountType();
    void setDiscountType(const int discountType_);

    const char* getDiscountValue();
    void setDiscountValue(const char* discountValue_);

    bool operator==(const TotalAdjustments& rhs);
    const char* toJson();
    static TotalAdjustments fromJson(const char* json);
    void toString();
};