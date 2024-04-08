#pragma once

#include "Result.h"

class ReprintReceiptLastResult : public Result {
private:
    std::string result;
    std::string uniqueId;

public:
    ReprintReceiptLastResult();

    explicit ReprintReceiptLastResult(
        const char* result_,
        const char* uniqueId_
    );

    ~ReprintReceiptLastResult();

    bool operator==(const ReprintReceiptLastResult& rhs);
    const std::string toJson();
    static ReprintReceiptLastResult fromJson(const char* json);
    void toString();
};
