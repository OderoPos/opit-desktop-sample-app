#pragma once

#include "../../utils/StringUtils.h"
#include "../../utils/ecr/ReportType.h"
#include "../../utils/ecr/ReportSize.h"
#include "../../dll.h"

class DllExport Report {
private:
    ReportType* type = NULL;
    ReportSize* size = NULL;
    char* startDate = NULL;
    char* stopDate = NULL;
    int* startZ = NULL;
    int* stopZ = NULL;
    char* media = NULL;

public:
    Report();

    explicit Report(
        ReportType::Value* type_,
        ReportSize::Value * size_,
        const char* startDate_,
        const char* stopDate_,
        int* startZ_,
        int* stopZ_,
        const char* media_
    );

    ~Report();

    const ReportType* getType();
    void setType(ReportType* type_);

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

    bool operator==(const Report& rhs);
    const char* toJson();
    static Report fromJson(const char* json);
    void toString();
};