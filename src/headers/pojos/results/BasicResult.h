#pragma once

#include "Result.h"

class BasicResult : public Result {
public:
    BasicResult();

    explicit BasicResult(
        const char* result_
    );

    ~BasicResult();

    bool operator==(const BasicResult& rhs);
    const std::string toJson();
    static BasicResult fromJson(const char* json);
    void toString();
};
