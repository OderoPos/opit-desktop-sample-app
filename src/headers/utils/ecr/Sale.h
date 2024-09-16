#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include "CustomerInfo.h"
#include "FreeTextInfo.h"
#include "PaymentsInfo.h"
#include "ProductsInfo.h"
#include "SaleInfo.h"
#include "TotalAdjustments.h"
#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport Sale {
private:
    SaleInfo* saleInfo = NULL;
    CustomerInfo* customerInfo = NULL;
    ProductsInfo* products = NULL;
    PaymentsInfo* payments = NULL;
    FreeTextInfo* freeTexts = NULL;
    TotalAdjustments* discounts = NULL;
    int productSize;
    int paymentSize;
    int freeTextSize;
    int discountSize;

public:
    Sale();

    explicit Sale(
        SaleInfo* saleInfo_,
        CustomerInfo* customerInfo_,
        ProductsInfo* products_,
        int productSize_,
        PaymentsInfo* payments_,
        int paymentSize_,
        FreeTextInfo* freeTexts_,
        int freeTextSize_,
        TotalAdjustments* discounts_,
        int discountSize_
    );

    ~Sale();

    const SaleInfo* getSaleInfo();
    void setSaleInfo(SaleInfo* saleInfo_);

    const CustomerInfo* getCustomerInfo();
    void setCustomerInfo(CustomerInfo* customerInfo_);

    const ProductsInfo* getProductsInfo();
    void setProductsInfo(ProductsInfo* products_, int productSize_);

    const PaymentsInfo* getPaymentsInfo();
    void setPaymentsInfo(PaymentsInfo* payments_, int paymentSize_);

    const FreeTextInfo* getFreeTextInfo();
    void setFreeTextInfo(FreeTextInfo* freeTexts_, int freeTextSize_);

    const TotalAdjustments* getTotalAdjustments();
    void setTotalAdjustments(TotalAdjustments* discounts_, int discountSize_);

    bool operator==(const Sale& rhs);
    const char* toJson();
    static Sale fromJson(const char* json);
    void toString();
};