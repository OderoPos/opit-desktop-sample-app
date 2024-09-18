#pragma once

#include "../Result.h"

class PaymentResult : public Result {
private:
    double amount;
    char* currency;
    bool paymentStatus = false;
    char* receiptNo;

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

    double getAmount();
    void setAmount(double amount_);

    const char* getCurrency();
    void setCurrency(const char* currency_);

    bool getPaymentStatus();
    void setPaymentStatus(bool paymentStatus_);

    const char* getReceiptNo();
    void setReceiptNo(const char* receiptNo_);

    bool operator==(const PaymentResult& rhs);
    const char* toJson();
    static PaymentResult fromJson(const char* json);
    void toString();
};
