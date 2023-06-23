#pragma once

#include <winrt/Windows.Data.Json.h>
#include "Request.h"

using namespace winrt::Windows::Data::Json;

class DllExport PaymentRequest : Request {
private:
    double amount = 0;
    char* currency;
    char* currencyCode;
    char* uniqueId;

public:
    PaymentRequest();

    explicit PaymentRequest(
        double amount_,
        const char* currency_,
        const char* currencyCode_,
        const char* uniqueId_
    );

    ~PaymentRequest();

    double getAmount();
    void setAmount(double amount_);
    const char* getCurrency();
    void setCurrency(const char* currency_);
    const char* getCurrencyCode();
    void setCurrencyCode(const char* currencyCode_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const PaymentRequest& rhs);
    const char* toJson();
    static PaymentRequest fromJson(const char*& json);
    void toString();
};