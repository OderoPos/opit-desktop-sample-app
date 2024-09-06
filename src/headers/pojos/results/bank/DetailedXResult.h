#pragma once

#include "../Result.h"

class DllExport DetailedXResult : public Result {
private:
    char* result;
    char* currency;

public:
    DetailedXResult();

    explicit DetailedXResult(
        const char* result_,
        const char* currency_,
        const char* uniqueId_
    );

    ~DetailedXResult();

    const char* getResult();
    void setResult(const char* result_);

    const char* getCurrency();
    void setCurrency(const char* currency_);

    bool operator==(const DetailedXResult& rhs);
    const char* toJson();
    static DetailedXResult fromJson(const char* json);
    void toString();
};
