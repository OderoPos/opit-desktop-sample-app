#pragma once

#include <winrt/Windows.Data.Json.h>
#include "Result.h"

using namespace winrt::Windows::Data::Json;

class DllExport DetailedXResult : public Result {
private:
    char* result;
    char* currency;
    char* uniqueId;

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
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const DetailedXResult& rhs);
    const char* toJson();
    static DetailedXResult fromJson(const char*& json);
    void toString();
};