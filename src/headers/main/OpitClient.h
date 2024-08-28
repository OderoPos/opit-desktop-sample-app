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
#include "../pojos/requests/ReceiptRequest.h"
#include "../pojos/requests/PaymentRequest.h"
#include "../pojos/requests/SimpleRequest.h"
#include "../pojos/requests/CurrencyRequest.h"
#include "../pojos/requests/Request.h"
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
    void destroy();
};