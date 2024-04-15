#pragma once

#include "Request.h"

class DllExport CurrencyRequest : public Request {
private:
    char* currency;
    char* currencyCode;
    char* uniqueId;

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
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const CurrencyRequest& rhs);
    const char* toJson();
    static CurrencyRequest fromJson(const char* json);
    void toString();
};
