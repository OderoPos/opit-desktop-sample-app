#pragma once

#include "Result.h"

class PaymentResult : public Result {
private:
    double amount = 0;
    std::string currency;
    bool paymentStatus = false;
    std::string receiptNo;
    std::string uniqueId;

public:
    PaymentResult();

    explicit PaymentResult(
        double amount_,
        const char* currency_,
        bool paymentStatus_,
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~PaymentResult();

    bool operator==(const PaymentResult& rhs);
    const std::string toJson();
    static PaymentResult fromJson(const char* json);
    void toString();
};
