#pragma once

#include <winrt/Windows.Data.Json.h>
#include "Request.h"

using namespace winrt::Windows::Data::Json;

class DllExport ReceiptRequest : public Request {
private:
    char* receiptNo;
    char* uniqueId;

public:
    ReceiptRequest();

    explicit ReceiptRequest(
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~ReceiptRequest();

    const char* getReceiptNo();
    void setReceiptNo(const char* receiptNo_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const ReceiptRequest& rhs);
    const char* toJson();
    static ReceiptRequest fromJson(const char*& json);
    void toString();
};