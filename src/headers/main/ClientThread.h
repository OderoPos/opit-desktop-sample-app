#pragma once

#include "InternalOpitResultListener.h"
#include "ClientServiceExtendedContract.h"
#include "../utils/Constants.h"
#include "../utils/ClientUtils.h"
#include "../utils/JsonUtils.h"
#include "../pojos/requests/ClientMessage.h"
#include "../pojos/requests/HostMessage.h"
#include "../pojos/requests/ReceiptRequest.h"
#include "../pojos/requests/PaymentRequest.h"
#include "../pojos/requests/SimpleRequest.h"
#include "../pojos/requests/CurrencyRequest.h"
#include "../pojos/requests/Request.h"
#include "../dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>

#define ONE_SECOND 1 * 1000
#define TWO_SECOND 2 * 1000

class DllExport 
ClientThread : ClientServiceExtendedContract {
public:
    explicit ClientThread(
        OpitResultListener& resultListener_
    );

    ~ClientThread();

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
    void destroy();
};