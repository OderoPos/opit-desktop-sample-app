#pragma once

#include "../Request.h"

class DllExport SetDateTimeRequest : public Request {
private:
    char* value = NULL;

public:
    SetDateTimeRequest();

    explicit SetDateTimeRequest(
        const char* value_,
        const char* uniqueId_
    );

    ~SetDateTimeRequest();

    const char* getValue();
    void setValue(const char* value_);

    bool operator==(const SetDateTimeRequest& rhs);
    const char* toJson();
    static SetDateTimeRequest fromJson(const char* json);
    void toString();
};