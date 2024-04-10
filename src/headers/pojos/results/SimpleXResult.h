#pragma once

#include "Result.h"

class SimpleXResult : public Result {
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
