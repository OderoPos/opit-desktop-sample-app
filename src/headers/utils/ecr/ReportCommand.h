#pragma once

#include "Report.h"

class ReportCommand {
private:
    Report* report = nullptr;

public:
    ReportCommand();

    explicit ReportCommand(
        Report* report_
    );

    ~ReportCommand();

    const Report* getReport();
    void setReport(Report* report_);

    bool operator==(const ReportCommand& rhs);
    const char* toJson();
    static ReportCommand fromJson(const char* json);
    void toString();
};