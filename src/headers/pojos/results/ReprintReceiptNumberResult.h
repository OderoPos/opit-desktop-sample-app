#pragma once

#include "Result.h"

class ReprintReceiptNumberResult : public Result {
public:
    ReprintReceiptNumberResult();

    explicit ReprintReceiptNumberResult(
        const char* result_,
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~ReprintReceiptNumberResult();

    bool operator==(const ReprintReceiptNumberResult& rhs);
    const std::string toJson();
    static ReprintReceiptNumberResult fromJson(const char* json);
    void toString();
};
