#pragma once

#include "../ecr/CustomerInfo.h"
#include "../ecr/FreeTextInfo.h"
#include "../ecr/PaymentsInfo.h"
#include "../ecr/ProductsInfo.h"
#include "../ecr/SaleInfo.h"
#include "../ecr/TotalAdjustments.h"
#include "../Request.h"

class DllExport SaleRequest : public Request {
private:
    SaleInfo* saleInfo;
    CustomerInfo* customerInfo;
    ProductsInfo* products;
    PaymentsInfo* payments;
    FreeTextInfo* freeTexts;
    TotalAdjustments* discounts;
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
        int discountSize_
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
    static SaleRequest* fromJson(const char* json);
    void toString();
};