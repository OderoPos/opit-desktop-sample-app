#pragma once

#include "Request.h"

class PaymentRequest : Request {
private:
    double amount = 0;
    std::string currency;
    std::string currencyCode;
    std::string uniqueId;

public:
    PaymentRequest();

    explicit PaymentRequest(
        double amount_,
        const char* currency_,
        const char* currencyCode_,
        const char* uniqueId_
    );

    ~PaymentRequest();

    bool operator==(const PaymentRequest& rhs);
    const std::string toJson();
    static PaymentRequest fromJson(const char* json);
    void toString();
};