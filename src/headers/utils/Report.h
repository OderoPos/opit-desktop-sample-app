#pragma once

#include "../dll.h"
#include <stdexcept>
#include <cstring>

class DllExport Report {
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
        JournalCopy
    };

    Report();

    explicit Report(
        Value value_
    );

    const char* getName();
    static Value getEnum(const char* name);
    bool operator==(const Report& rhs);

private:
    Value* value;
};