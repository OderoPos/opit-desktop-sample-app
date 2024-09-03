#pragma once

#include "Result.h"

class DllExport BasicResult : public Result {
private:
    char* result;

public:
    BasicResult();

    explicit BasicResult(
        const char* result_
    );

    ~BasicResult();

    const char* getResult();
    void setResult(const char* result_);
    bool operator==(const BasicResult& rhs);
    const char* toJson();
    static BasicResult fromJson(const char* json);
    void toString();
};
