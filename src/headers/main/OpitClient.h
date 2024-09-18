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
#include "../pojos/requests/ClientMessage.h"
#include "../pojos/requests/HostMessage.h"
#include "../pojos/requests/bank/ReceiptRequest.h"
#include "../pojos/requests/bank/PaymentRequest.h"
#include "../pojos/requests/bank/SimpleRequest.h"
#include "../pojos/requests/bank/CurrencyRequest.h"
#include "../pojos/requests/Request.h"
#include "../utils/ecr/FreeTextInfo.h"
#include "../utils/ecr/PaymentsInfo.h"
#include "../utils/ecr/ProductsInfo.h"
#include "../pojos/requests/ecr/ReportRequest.h"
#include "../pojos/requests/ecr/ScreenRequest.h"
#include "../utils/ecr/SaleInfo.h"
#include "../pojos/requests/ecr/SaleRequest.h"
#include "../pojos/requests/ecr/CompanyRequest.h"
#include "../pojos/requests/ecr/DateTimeRequest.h"
#include "../utils/ecr/TotalAdjustments.h"
#include "../pojos/requests/ecr/VatRatesRequest.h"
#include "../pojos/requests/ecr/CommandRequest.h"
#include "../utils/ecr/CustomerInfo.h"

#define DEFAULT_BUFLEN 512 * 50
#define ONE_SECOND 1 * 1000

#define IP "192.168.1.1"
#define PORT "5051"

class OpitClient : ClientServiceContract {
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
    void ecrInitJournalReport(const char* uniqueId);
    void ecrJournalReport(const char* startDate, const char* stopDate, const char* uniqueId);
    void ecrXJournalReport(const char* uniqueId);
    void ecrCustomerDataReport(const char* uniqueId);
    void ecrPeriodicReportByDate(const char* startDate, const char* stopDate, const char* uniqueId);
    void ecrPeriodicReportByZ(int* startZ, int* stopZ, const char* uniqueId);

    void ecrFiscaliseCmd(const char* uniqueId);
    void ecrInitElectronicJournalCmd(const char* uniqueId);
    void ecrGetDateTimeCmd(const char* uniqueId);
    void ecrGetVATRatesCmd(const char* uniqueId);
    void ecrGetCompanyDataCmd(const char* uniqueId);
    void ecrGetStatusCmd(const char* uniqueId);
    void ecrGetDailyTotalsCmd(const char* uniqueId);
    void ecrGetZreportCmd(const char* uniqueId);
    void ecrGetSoftwareVersionCmd(const char* uniqueId);

    void ecrScreenRequest(const char* value, const char* uniqueId);
    void ecrSetCompanyRequest(
        const char* name,
        const char* address,
        const char* cui,
        const char* fiscalSeries,
        const char* uniqueId);

    void ecrSetDateTimeRequest(const char* value, const char* uniqueId);
    void ecrVatRatesRequest(VatRates* vatRates, int size, const char* uniqueId);

    void destroy();
};