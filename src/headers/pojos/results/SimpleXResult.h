#pragma once

#include "Result.h"

class SimpleXResult : public Result {
private:
    std::string result;
    std::string currency;
    std::string uniqueId;

public:
    SimpleXResult();

    explicit SimpleXResult(
        const char* result_,
        const char* currency_,
        const char* uniqueId_
    );

    ~SimpleXResult();

    bool operator==(const SimpleXResult& rhs);
    const std::string toJson();
    static SimpleXResult fromJson(const char* json);
    void toString();
};
