#pragma once

class PaymentsInfo {
private:
    int paymentMethodId = 0;
    char* value = nullptr;

public:
    PaymentsInfo();

    explicit PaymentsInfo(
        const int paymentMethodId_,
        const char* value_
    );

    ~PaymentsInfo();

    const int getPaymentMethodId();
    void setPaymentMethodId(const int paymentMethodId_);

    const char* getValue();
    void setValue(const char* value_);

    bool operator==(const PaymentsInfo& rhs);
    const char* toJson();
    static PaymentsInfo fromJson(const char* json);
    void toString();
};