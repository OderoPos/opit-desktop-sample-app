#pragma once

#include "OpitResultListener.h"
#include "ClientServiceContract.h"
#include "../utils/Constants.h"
#include "../utils/ClientUtils.h"
#include "../utils/Debug.h"
#include "../utils/JsonUtils.h"
#include "../pojos/requests/ClientMessage.h"
#include "../pojos/requests/HostMessage.h"
#include "../pojos/requests/bank/ReceiptRequest.h"
#include "../pojos/requests/bank/PaymentRequest.h"
#include "../pojos/requests/bank/SimpleRequest.h"
#include "../pojos/requests/bank/CurrencyRequest.h"
#include "../pojos/requests/Request.h"
#include "../pojos/requests/ecr/FreeTextInfo.h"
#include "../pojos/requests/ecr/PaymentsInfo.h"
#include "../pojos/requests/ecr/ProductsInfo.h"
#include "../pojos/requests/ecr/ReportRequest.h"
#include "../pojos/requests/ecr/ScreenRequest.h"
#include "../pojos/requests/ecr/SaleInfo.h"
#include "../pojos/requests/ecr/SaleRequest.h"
#include "../pojos/requests/ecr/SetCompanyRequest.h"
#include "../pojos/requests/ecr/SetDateTimeRequest.h"
#include "../pojos/requests/ecr/TotalAdjustments.h"
#include "../pojos/requests/ecr/VatRatesRequest.h"
#include "../pojos/requests/ecr/CommandRequest.h"
#include "../pojos/requests/ecr/CustomerInfo.h"
#include "../dll.h"

#define ONE_SECOND 1 * 1000
#define TWO_SECOND 2 * 1000

class DllExport 
OpitClient : ClientServiceContract {
public:
    explicit OpitClient(
        OpitResultListener& resultListener_
    );

    ~OpitClient();

    void start();
    bool isConnected();
    void sendPaymentRequest(double amount, const char* currency, const char* uniqueId);
    void printSettlement(const char* uniqueId);
    void printLastSettlement(const char* currency, const char* uniqueId);
    void reprintReceiptNo(const char* receiptNo, const char* uniqueId);
    void reprintLastReceipt(const char* uniqueId);
    void getSimpleXReport(const char* currency, const char* uniqueId);
    void getDetailedXReport(const char* currency, const char* uniqueId);
    void voidReceipt(const char* receiptNo, const char* uniqueId);

    void ecrCommandRequest(
        const CmdCode::Value cmdCode,
        const char* param1,
        const char* param2,
        const char* uniqueId
    );

    void ecrSaleRequest(
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

    void ecrTechnicalReport(const char* uniqueId);
    void ecrZReport(const char* uniqueId);
    void ecrXReport(const char* uniqueId);
    void ecrInitJournal(const char* uniqueId);
    void ecrJournal(const char* startDate, const char* stopDate, const char* uniqueId);
    void ecrXJournal(const char* uniqueId);
    void ecrCustomerData(const char* uniqueId);
    void ecrPeriodicReportByDate(const char* startDate, const char* stopDate, const char* uniqueId);
    void ecrPeriodicReportByZ(int* startZ, int* stopZ, const char* uniqueId);
    void ecrScreenRequest(const char* value, const char* uniqueId);

    void ecrSetCompanyRequest(
        const char* name,
        const char* address,
        const char* cui,
        const char* fiscalSeries,
        const char* uniqueId);

    void ecrSetDateTimeRequest(const char* value, const char* uniqueId);
    void ecrVatRatesRequest(const VatRate::Value vatId, const char* vatRate, const char* uniqueId);

    void destroy();
};