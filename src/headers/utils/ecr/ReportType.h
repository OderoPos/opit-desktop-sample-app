#pragma once

#include <stdexcept>
#include <cstring>
#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport ReportType {
public:
    enum Value : size_t {
        Z,
        X,
        Technical,
        Periodic,
        Journal,
        JournalInit,
        CustomerData,
        XJournal,
        XML,
        JournalCopy,
        Null
    };

    ReportType();

    explicit ReportType(
        Value value_
    );

    const char* getName();
    Value* getValue();
    static Value getEnum(const char* name);
    bool operator==(const ReportType& rhs);

private:
    Value* value;
};