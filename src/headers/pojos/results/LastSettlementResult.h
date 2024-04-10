#pragma once

#include "Result.h"

class LastSettlementResult : public Result {
public:
    LastSettlementResult();

    explicit LastSettlementResult(
        const char* result_,
        const char* currency_,
        const char* uniqueId_
    );

    ~LastSettlementResult();

    bool operator==(const LastSettlementResult& rhs);
    const std::string toJson();
    static LastSettlementResult fromJson(const char* json);
    void toString();
};
