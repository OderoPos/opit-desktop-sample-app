#pragma once

#include "DateAndTime.h"

class DateTimeCommand {
private:
    DateAndTime* dateTime = nullptr;

public:
    DateTimeCommand();

    explicit DateTimeCommand(
        DateAndTime* dateTime_
    );

    ~DateTimeCommand();

    const DateAndTime* getDateTime();
    void setDateTime(DateAndTime* dateTime_);

    bool operator==(const DateTimeCommand& rhs);
    const char* toJson();
    static DateTimeCommand fromJson(const char* json);
    void toString();
};