#pragma once

#include "Result.h"

class DetailedXResult : public Result {
private:
    std::string result;
    std::string currency;
    std::string uniqueId;

public:
    DetailedXResult();

    explicit DetailedXResult(
        const char* result_,
        const char* currency_,
        const char* uniqueId_
    );

    ~DetailedXResult();

    bool operator==(const DetailedXResult& rhs);
    const std::string toJson();
    static DetailedXResult fromJson(const char* json);
    void toString();
};
