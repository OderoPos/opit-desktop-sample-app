#pragma once

#include "../Request.h"
#include "../../../utils/ecr/DateAndTime.h"

class DllExport DateTimeRequest : public Request {
private:
    DateAndTime* dateTime = NULL;

public:
    DateTimeRequest();

    explicit DateTimeRequest(
        DateAndTime* dateTime_,
        const char* uniqueId_
    );

    ~DateTimeRequest();

    const DateAndTime* getDateTime();
    void setDateTime(DateAndTime* dateTime_);

    bool operator==(const DateTimeRequest& rhs);
    const char* toJson();
    static DateTimeRequest fromJson(const char* json);
    void toString();
};