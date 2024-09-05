#pragma once

#include "../Request.h"
#include "../../../utils/PagePosition.h"

class DllExport FreeTextInfo {
private:
    char* freeText = NULL;
    PagePosition position;

public:
    FreeTextInfo();

    explicit FreeTextInfo(
        const char* freeText_,
        const PagePosition::Value position_
    );

    ~FreeTextInfo();

    const char* getFreeText();
    void setFreeText(const char* freeText_);

    const PagePosition getPosition();
    void setPosition(const PagePosition position_);

    bool operator==(const FreeTextInfo& rhs);
    const char* toJson();
    static FreeTextInfo fromJson(const char* json);
    void toString();
};