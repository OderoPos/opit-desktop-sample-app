#pragma once

#include "Result.h"

class VoidResult : public Result {
public:
    VoidResult();

    explicit VoidResult(
        const char* result_,
        const char* receiptNo_,
        const char* uniqueId_
    );

    ~VoidResult();

    bool operator==(const VoidResult& rhs);
    const std::string toJson();
    static VoidResult fromJson(const char* json);
    void toString();
};
