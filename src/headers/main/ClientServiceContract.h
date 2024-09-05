#pragma once

#include "../utils/CmdCode.h"
#include "../utils/VatRate.h"
#include "../utils/Report.h"
#include "../utils/ReportSize.h"
#include "../pojos/requests/ecr/FreeTextInfo.h"
#include "../pojos/requests/ecr/PaymentsInfo.h"
#include "../pojos/requests/ecr/ProductsInfo.h"
#include "../pojos/requests/ecr/SaleInfo.h"
#include "../pojos/requests/ecr/TotalAdjustments.h"
#include "../pojos/requests/ecr/CustomerInfo.h"
#include "../dll.h"

class DllExport
ClientServiceContract {
public:
    virtual void sendPaymentRequest(double amount, const char* currency, const char* uniqueId);
    virtual void printSettlement(const char* uniqueId);
    virtual void printLastSettlement(const char* currency, const char* uniqueId);
    virtual void reprintReceiptNo(const char* receiptNo, const char* uniqueId);
    virtual void reprintLastReceipt(const char* uniqueId);
    virtual void getSimpleXReport(const char* currency, const char* uniqueId);
    virtual void getDetailedXReport(const char* currency, const char* uniqueId);
    virtual void voidReceipt(const char* receiptNo, const char* uniqueId);

    virtual void ecrCommandRequest(const CmdCode::Value cmdCode, const char* param1, const char* param2, const char* uniqueId);
    virtual void ecrReportRequest(
        const Report::Value type,
        const ReportSize::Value size,
        const char* startDate,
        const char* stopDate,
        const int startZ,
        const int stopZ,
        const char* media,
        const char* uniqueId);

    virtual void ecrScreenRequest(const char* value, const char* uniqueId);
    virtual void ecrSetCompanyRequest(
        const char* name,
        const char* address,
        const char* cui,
        const char* fiscalSeries,
        const char* uniqueId);

    virtual void ecrSaleRequest(
        SaleInfo* saleInfo,
        CustomerInfo* customerInfo,
        ProductsInfo* products,
        int productSize,
        PaymentsInfo* payments,
        int paymentSize,
        FreeTextInfo* freeTexts,
        int freeTextSize,
        TotalAdjustments* discounts,
        int discountSize,
        const char* uniqueId
    );

    virtual void ecrSetDateTimeRequest(const char* value, const char* uniqueId);
    virtual void ecrVatRatesRequest(const VatRate::Value vatId, const char* vatRate, const char* uniqueId);
};
