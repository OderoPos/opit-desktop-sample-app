#pragma once

#include "Result.h"

class DllExport SettlementResult : public Result {
private:
    char* result;
    char* uniqueId;

public:
    SettlementResult();

    explicit SettlementResult(
        const char* result_,
        const char* uniqueId_
    );

    ~SettlementResult();

    const char* getResult();
    void setResult(const char* result_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const SettlementResult& rhs);
    const char* toJson();
    static SettlementResult fromJson(const char* json);
    void toString();
};
