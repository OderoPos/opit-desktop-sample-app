#pragma once

#include "../Result.h"
#include "DateTime.h"

class DllExport FailedCommand : public Result {
private:
    DateTime* dateTime;

public:
    FailedCommand();

    explicit FailedCommand(
        DateTime* dateTime_
    );

    ~FailedCommand();

    const DateTime* getDateTime();
    void setDateTime(DateTime* dateTime_);

    bool operator==(const FailedCommand& rhs);
    const char* toJson();
    static FailedCommand fromJson(const char* json);
    void toString();
};