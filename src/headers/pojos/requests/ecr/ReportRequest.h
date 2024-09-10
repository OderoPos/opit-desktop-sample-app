#pragma once

#include "../Request.h"
#include "../../../utils/ecr/Report.h"

class DllExport ReportRequest : public Request {
private:
    Report* report = NULL;

public:
    ReportRequest();

    explicit ReportRequest(
        Report* report_,
        const char* uniqueId_
    );

    ~ReportRequest();

    const Report* getReport();
    void setReport(Report* report_);

    bool operator==(const ReportRequest& rhs);
    const char* toJson();
    static ReportRequest fromJson(const char* json);
    void toString();
};