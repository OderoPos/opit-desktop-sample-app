#pragma once

#include "../Request.h"
#include "../../../utils/ecr/DateTimeCommand.h"

class DateTimeRequest : public Request {
private:
    DateTimeCommand* command = nullptr;

public:
    DateTimeRequest();

    explicit DateTimeRequest(
        DateTimeCommand* command_,
        const char* uniqueId_
    );

    ~DateTimeRequest();

    const DateTimeCommand* getDateTimeCommand();
    void setDateTimeCommand(DateTimeCommand* command_);

    bool operator==(const DateTimeRequest& rhs);
    const char* toJson();
    static DateTimeRequest fromJson(const char* json);
    void toString();
};