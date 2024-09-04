#pragma once

#include "../Request.h"
#include "../../../utils/VatRate.h"

class DllExport TotalAdjustments {
private:
    VatRate vatId;
    int discountSign;
    int discountType;
    char* discountValue;

public:
    TotalAdjustments();

    explicit TotalAdjustments(
        const VatRate::Value vatId_,
        const int discountSign_,
        const int discountType_,
        const char* discountValue_
    );

    ~TotalAdjustments();

    const VatRate getVatId();
    void setVatId(const VatRate vatId_);
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