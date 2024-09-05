#pragma once

#include "../Request.h"
#include "../../../utils/Report.h"
#include "../../../utils/ReportSize.h"

class DllExport ReportRequest : public Request {
private:
    Report* type = NULL;
    ReportSize* size = NULL;
    char* startDate = NULL;
    char* stopDate = NULL;
    int* startZ = NULL;
    int* stopZ = NULL;
    char* media = NULL;

public:
    ReportRequest();

    explicit ReportRequest(
        Report::Value* type_,
        ReportSize::Value * size_,
        const char* startDate_,
        const char* stopDate_,
        int* startZ_,
        int* stopZ_,
        const char* media_,
        const char* uniqueId_
    );

    ~ReportRequest();

    const Report* getType();
    void setType(Report* type_);

    const ReportSize* getSize();
    void setSize(ReportSize* size_);

    const char* getStartDate();
    void setStartDate(const char* startDate_);

    const char* getStopDate();
    void setStopDate(const char* stopDate_);

    const int* getStartZ();
    void setStartZ(int* startZ_);

    const int* getStopZ();
    void setStopZ(int* stopZ_);

    const char* getMedia();
    void setMedia(const char* media_);

    bool operator==(const ReportRequest& rhs);
    const char* toJson();
    static ReportRequest fromJson(const char* json);
    void toString();
};