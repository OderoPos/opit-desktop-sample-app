#pragma once

#include "Result.h"

class DllExport ReprintReceiptLastResult : public Result {
private:
    char* result;
    char* uniqueId;

public:
    ReprintReceiptLastResult();

    explicit ReprintReceiptLastResult(
        const char* result_,
        const char* uniqueId_
    );

    ~ReprintReceiptLastResult();

    const char* getResult();
    void setResult(const char* result_);
    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const ReprintReceiptLastResult& rhs);
    const char* toJson();
    static ReprintReceiptLastResult fromJson(const char* json);
    void toString();
};
