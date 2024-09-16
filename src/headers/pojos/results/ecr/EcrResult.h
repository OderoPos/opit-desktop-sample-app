#pragma once

#include "../Result.h"

class DllExport EcrResult : public Result {
private:
    char* result;

public:
    EcrResult();

    explicit EcrResult(
        const char* result_,
        const char* uniqueId_
    );

    ~EcrResult();

    const char* getResult();
    void setResult(const char* result_);

    bool operator==(const EcrResult& rhs);
    const char* toJson();
    static EcrResult fromJson(const char* json);
    void toString();
};