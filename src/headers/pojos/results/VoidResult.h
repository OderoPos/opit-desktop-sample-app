#pragma once

#include <winrt/Windows.Data.Json.h>
#include "Result.h"

using namespace winrt::Windows::Data::Json;

class DllExport VoidResult : public Result {
private:
    char* result;
    char* receiptNo;
    char* uniqueId;

public:
    VoidResult();

    explicit VoidResult(
        const char* result_,
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~VoidResult();

    const char* getResult();
    void setResult(const char* result_);
    const char* getReceiptNo();
    void setReceiptNo(const char* receiptNo_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const VoidResult& rhs);
    const char* toJson();
    static VoidResult fromJson(const char*& json);
    void toString();
};