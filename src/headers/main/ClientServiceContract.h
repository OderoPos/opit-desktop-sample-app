#pragma once

#include "../utils/ecr/CmdCode.h"
#include "../utils/ecr/VatRateType.h"
#include "../utils/ecr/Report.h"
#include "../utils/ecr/ReportSize.h"
#include "../utils/ecr/FreeTextInfo.h"
#include "../utils/ecr/PaymentsInfo.h"
#include "../utils/ecr/ProductsInfo.h"
#include "../utils/ecr/SaleInfo.h"
#include "../utils/ecr/TotalAdjustments.h"
#include "../utils/ecr/CustomerInfo.h"
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

    virtual void ecrCommandRequest(
        const CmdCode::Value cmdCode,
        const char* param1,
        const char* param2,
        const char* uniqueId
    );

    virtual void ecrReportRequest(
        const ReportType::Value type,
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
        const char* uniqueId);

    virtual void ecrSetDateTimeRequest(const char* value, const char* uniqueId);

    virtual void ecrVatRatesRequest(const VatRateType::Value vatId, const char* vatRate, const char* uniqueId);
};
