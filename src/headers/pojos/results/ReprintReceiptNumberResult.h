#pragma once

#include <winrt/Windows.Data.Json.h>
#include "Result.h"

using namespace winrt::Windows::Data::Json;

class DllExport ReprintReceiptNumberResult : public Result {
private:
    char* result;
    char* receiptNo;
    char* uniqueId;

public:
    ReprintReceiptNumberResult();

    explicit ReprintReceiptNumberResult(
        const char* result_,
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~ReprintReceiptNumberResult();

    const char* getResult();
    void setResult(const char* result_);
    const char* getReceiptNo();
    void setReceiptNo(const char* receiptNo_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const ReprintReceiptNumberResult& rhs);
    const char* toJson();
    static ReprintReceiptNumberResult fromJson(const char*& json);
    void toString();
};