#pragma once

#include "Request.h"

class ReceiptRequest : public Request {
private:
    std::string receiptNo;
    std::string uniqueId;

public:
    ReceiptRequest();

    explicit ReceiptRequest(
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~ReceiptRequest();

    bool operator==(const ReceiptRequest& rhs);
    const std::string toJson();
    static ReceiptRequest fromJson(const char* json);
    void toString();
};
