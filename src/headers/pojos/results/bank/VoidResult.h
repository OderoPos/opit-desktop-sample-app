#pragma once

#include "../Result.h"

class VoidResult : public Result {
private:
    char* result;
    char* receiptNo;

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

    bool operator==(const VoidResult& rhs);
    const char* toJson();
    static VoidResult fromJson(const char* json);
    void toString();
};
