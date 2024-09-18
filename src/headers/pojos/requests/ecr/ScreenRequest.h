#pragma once

#include "../Request.h"

class ScreenRequest : public Request {
private:
    char* value = nullptr;

public:
    ScreenRequest();

    explicit ScreenRequest(
        const char* value_,
        const char* uniqueId_
    );

    ~ScreenRequest();

    const char* getValue();
    void setValue(const char* value_);

    bool operator==(const ScreenRequest& rhs);
    const char* toJson();
    static ScreenRequest fromJson(const char* json);
    void toString();
};