#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <windows.h>
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

#define DEFAULT_BUFLEN 512 * 50
#define ONE_SECOND 1 * 1000

#define IP "192.168.1.1"
#define PORT "5051"

class DllExport OpitClient : ClientServiceContract {
public:
    explicit OpitClient(
        OpitResultListener& resultListener_
    );

    ~OpitClient();

    bool start();
    bool isConnected();
    void sendPaymentRequest(double amount, const char* currency, const char* uniqueId);
    void printSettlement(const char* uniqueId);
    void printLastSettlement(const char* currency, const char* uniqueId);
    void reprintReceiptNo(const char* receiptNo, const char* uniqueId);
    void reprintLastReceipt(const char* uniqueId);
    void getSimpleXReport(const char* currency, const char* uniqueId);
    void getDetailedXReport(const char* currency, const char* uniqueId);
    void voidReceipt(const char* receiptNo, const char* uniqueId);

    void ecrCommandRequest(const CmdCode cmdCode, const char* param1, const char* param2);
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
        int discountSize
    );

    void ecrTechnicalReport();
    void ecrZReport();
    void ecrXReport();
    void ecrInitJournal();
    void ecrJournal(const char* startDate, const char* stopDate);
    void ecrXJournal();
    void ecrCustomerData();
    void ecrPeriodicReportByDate(const char* startDate, const char* stopDate);
    void ecrPeriodicReportByZ(int* startZ, int* stopZ);
    void ecrScreenRequest(const char* value);
    void ecrSetCompanyRequest(
        const char* name,
        const char* address,
        const char* cui,
        const char* fiscalSeries);

    void ecrSetDateTimeRequest(const char* value);
    void ecrVatRatesRequest(const VatRate vatId, const char* vatRate);
    void destroy();
};