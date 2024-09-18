#pragma once

#include "../../utils/ecr/PagePosition.h"

class FreeTextInfo {
private:
    char* freeText = nullptr;
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