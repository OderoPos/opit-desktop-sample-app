#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <windows.h>
#include "InternalOpitResultListener.h"
#include "ClientServiceExtendedContract.h"
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

class DllExport ClientThread : ClientServiceExtendedContract {
public:
    explicit ClientThread(
        OpitResultListener& resultListener_
    );

    ~ClientThread();

    bool start();
    bool getIsConnected();
    void sendPaymentRequest(double amount, const char* currency, const char* uniqueId);
    void printSettlement(const char* uniqueId);
    void printLastSettlement(const char* currency, const char* uniqueId);
    void reprintReceiptNo(const char* receiptNo, const char* uniqueId);
    void reprintLastReceipt(const char* uniqueId);
    void getSimpleXReport(const char* currency, const char* uniqueId);
    void getDetailedXReport(const char* currency, const char* uniqueId);
    void voidReceipt(const char* receiptNo, const char* uniqueId);
    void destroy();

private:
    volatile bool isThreadActive = true;
    volatile bool isSocketConnected = false;
    InternalOpitResultListener* internalOpitResultListener;
    SOCKET connectSocket = INVALID_SOCKET;

    bool openSocket();
    //will create a new thread and run the startReadLoop method
    void startReadThread(SOCKET* connectSocket);
    DWORD WINAPI startReadLoop(LPVOID lpParam);
    void processResponse(const char* str);
    void doSuccess(const char* message);
    template <typename T> void sendResult(const char* message);
    template <typename T> void sendToHost(const char* json, T& request);
};