#pragma once

#include <winrt/Windows.Data.Json.h>
#include "Result.h"

using namespace winrt::Windows::Data::Json;

class DllExport SimpleXResult : public Result {
private:
    char* result;
    char* currency;
    char* uniqueId;

public:
    SimpleXResult();

    explicit SimpleXResult(
        char* result_,
        char* currency_,
        char* uniqueId_
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
    static SimpleXResult fromJson(const char*& json);
    void toString();
};