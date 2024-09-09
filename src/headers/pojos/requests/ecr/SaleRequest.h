#pragma once

#include "../../../utils/ecr/CustomerInfo.h"
#include "../../../utils/ecr/FreeTextInfo.h"
#include "../../../utils/ecr/PaymentsInfo.h"
#include "../../../utils/ecr/ProductsInfo.h"
#include "../../../utils/ecr/SaleInfo.h"
#include "../../../utils/ecr/TotalAdjustments.h"
#include "../Request.h"

class DllExport SaleRequest : public Request {
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
    SaleRequest();

    explicit SaleRequest(
        SaleInfo* saleInfo_,
        CustomerInfo* customerInfo_,
        ProductsInfo* products_,
        int productSize_,
        PaymentsInfo* payments_,
        int paymentSize_,
        FreeTextInfo* freeTexts_,
        int freeTextSize_,
        TotalAdjustments* discounts_,
        int discountSize_,
        const char* uniqueId_
    );

    ~SaleRequest();

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

    bool operator==(const SaleRequest& rhs);
    const char* toJson();
    static SaleRequest fromJson(const char* json);
    void toString();
};