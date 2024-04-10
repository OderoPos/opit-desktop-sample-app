#pragma once

#include "Request.h"

class CurrencyRequest : public Request {
public:
    CurrencyRequest();

    explicit CurrencyRequest(
        const char* currency_,
        const char* currencyCode_,
        const char* uniqueId_
    );

    ~CurrencyRequest();

    bool operator==(const CurrencyRequest& rhs);
    const std::string toJson();
    static CurrencyRequest fromJson(const char* json);
    void toString();
};
