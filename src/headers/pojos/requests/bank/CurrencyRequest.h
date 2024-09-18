#pragma once

#include "../Request.h"

class CurrencyRequest : public Request {
private:
    char* currency = nullptr;
    char* currencyCode = nullptr;

public:
    CurrencyRequest();

    explicit CurrencyRequest(
        const char* currency_,
        const char* currencyCode_,
        const char* uniqueId_
    );

    ~CurrencyRequest();

    const char* getCurrency();
    void setCurrency(const char* currency_);

    const char* getCurrencyCode();
    void setCurrencyCode(const char* currencyCode_);

    bool operator==(const CurrencyRequest& rhs);
    const char* toJson();
    static CurrencyRequest fromJson(const char* json);
    void toString();
};
