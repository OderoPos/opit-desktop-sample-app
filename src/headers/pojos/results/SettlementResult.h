#pragma once

#include "Result.h"

class SettlementResult : public Result {
public:
    SettlementResult();

    explicit SettlementResult(
        const char* result_,
        const char* uniqueId_
    );

    ~SettlementResult();

    bool operator==(const SettlementResult& rhs);
    const std::string toJson();
    static SettlementResult fromJson(const char* json);
    void toString();
};
