#pragma once

#include "../Request.h"
#include "../../../utils/VatRate.h"

class DllExport ProductsInfo {
private:
    char* name = NULL;
    char* um = NULL;
    char* quantity = NULL;
    VatRate vatId;
    int discountSign;
    int discountType;
    char* discountValue = NULL;

public:
    ProductsInfo();

    explicit ProductsInfo(
        const char* name_,
        const char* um_,
        const char* quantity_,
        const VatRate::Value vatId_,
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

    const VatRate getVatId();
    void setVatId(const VatRate vatId_);

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