#pragma once

#include "../Request.h"
#include "../../../utils/ecr/ReportCommand.h"

class ReportRequest : public Request {
private:
    ReportCommand* command = nullptr;

public:
    ReportRequest();

    explicit ReportRequest(
        ReportCommand* command_,
        const char* uniqueId_
    );

    ~ReportRequest();

    const ReportCommand* getReportCommand();
    void setReportCommand(ReportCommand* command_);

    bool operator==(const ReportRequest& rhs);
    const char* toJson();
    static ReportRequest fromJson(const char* json);
    void toString();
};