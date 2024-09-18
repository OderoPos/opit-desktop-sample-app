#pragma once

#include "../../utils/ecr/VatRateType.h"

class ProductsInfo {
private:
    char* name = nullptr;
    char* um = nullptr;
    char* quantity = nullptr;
    char* price = nullptr;
    VatRateType vatId;
    int discountSign = 0;
    int discountType = 0;
    char* discountValue = nullptr;

public:
    ProductsInfo();

    explicit ProductsInfo(
        const char* name_,
        const char* um_,
        const char* quantity_,
        const char* price_,
        const VatRateType::Value vatId_,
        const int discountSign_,
        const int discountType_,
        const char* discountValue_
    );

    ~ProductsInfo();

    const char* getName();
    void setName(const char* name_);

    const char* getUm();
    void setUm(const char* um_);

    const char* getQuantity();
    void setQuantity(const char* quantity_);

    const char* getPrice();
    void setPrice(const char* price_);

    const VatRateType getVatId();
    void setVatId(const VatRateType vatId_);

    const int getDiscountSign();
    void setDiscountSign(const int discountSign_);

    const int getDiscountType();
    void setDiscountType(const int discountType_);

    const char* getDiscountValue();
    void setDiscountValue(const char* discountValue_);

    ProductsInfo& operator=(const ProductsInfo& other);
    bool operator==(const ProductsInfo& rhs);
    const char* toJson();
    static ProductsInfo fromJson(const char* json);
    void toString();
};