#pragma once

#include "../Request.h"

class DllExport ScreenRequest : public Request {
private:
    char* value;

public:
    ScreenRequest();

    explicit ScreenRequest(
        const char* value_
    );

    ~ScreenRequest();

    const char* getValue();
    void setValue(const char* value_);
    bool operator==(const ScreenRequest& rhs);
    const char* toJson();
    static ScreenRequest fromJson(const char* json);
    void toString();
};