#pragma once

#include "../Result.h"

class DllExport EcrResult : public Result {
private:
    int code;
    char* description;
    char* level;
    char* status;
    char* source;

public:
    EcrResult();

    explicit EcrResult(
        const int code_,
        const char* description_,
        const char* level_,
        const char* status_,
        const char* source_
    );

    ~EcrResult();

    const int getCode();
    void setCode(const int code_);
    const char* getDescription();
    void setDescription(const char* description_);
    const char* getLevel();
    void setLevel(const char* level_);
    const char* getStatus();
    void setStatus(const char* status_);
    const char* getSource();
    void setSource(const char* source_);
    bool operator==(const EcrResult& rhs);
    const char* toJson();
    static EcrResult fromJson(const char* json);
    void toString();
};