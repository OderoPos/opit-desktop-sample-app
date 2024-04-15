#pragma once

#include "Result.h"

class DllExport SimpleXResult : public Result {
private:
    char* result;
    char* currency;
    char* uniqueId;

public:
    SimpleXResult();

    explicit SimpleXResult(
        const char* result_,
        const char* currency_,
        const char* uniqueId_
    );

    ~SimpleXResult();

    const char* getResult();
    void setResult(const char* result_);
    const char* getCurrency();
    void setCurrency(const char* currency_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const SimpleXResult& rhs);
    const char* toJson();
    static SimpleXResult fromJson(const char* json);
    void toString();
};
