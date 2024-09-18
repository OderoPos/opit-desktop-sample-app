#pragma once

#include "../Request.h"

class ReceiptRequest : public Request {
private:
    char* receiptNo = nullptr;

public:
    ReceiptRequest();

    explicit ReceiptRequest(
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~ReceiptRequest();

    const char* getReceiptNo();
    void setReceiptNo(const char* receiptNo_);

    bool operator==(const ReceiptRequest& rhs);
    const char* toJson();
    static ReceiptRequest fromJson(const char* json);
    void toString();
};
