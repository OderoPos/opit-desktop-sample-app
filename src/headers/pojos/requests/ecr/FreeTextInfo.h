#pragma once

#include "../Request.h"

class DllExport FreeTextInfo {
private:
    char* freeText;
    char* position;

public:
    FreeTextInfo();

    explicit FreeTextInfo(
        const char* freeText_,
        const char* position_
    );

    ~FreeTextInfo();

    const char* getFreeText();
    void setFreeText(const char* freeText_);
    const char* getPosition();
    void setPosition(const char* position_);
    bool operator==(const FreeTextInfo& rhs);
    const char* toJson();
    static FreeTextInfo fromJson(const char* json);
    void toString();
};