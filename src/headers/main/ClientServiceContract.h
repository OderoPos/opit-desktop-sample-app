#pragma once

#include "../dll.h"

class DllExport ClientServiceContract {
public:
    virtual void sendPaymentRequest(double amount, const char* currency, const char* uniqueId);
    virtual void printSettlement(const char* uniqueId);
    virtual void printLastSettlement(const char* currency, const char* uniqueId);
    virtual void reprintReceiptNo(const char* receiptNo, const char* uniqueId);
    virtual void reprintLastReceipt(const char* uniqueId);
    virtual void getSimpleXReport(const char* currency, const char* uniqueId);
    virtual void getDetailedXReport(const char* currency, const char* uniqueId);
    virtual void voidReceipt(const char* receiptNo, const char* uniqueId);
};