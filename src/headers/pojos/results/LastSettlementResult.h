#pragma once

#include "Result.h"

class DllExport LastSettlementResult : public Result {
private:
    char* result;
    char* currency;
    char* uniqueId;

public:
    LastSettlementResult();

    explicit LastSettlementResult(
        const char* result_,
        const char* currency_,
        const char* uniqueId_
    );

    ~LastSettlementResult();

    const char* getResult();
    void setResult(const char* result_);
    const char* getCurrency();
    void setCurrency(const char* currency_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const LastSettlementResult& rhs);
    const char* toJson();
    static LastSettlementResult fromJson(const char* json);
    void toString();
};
