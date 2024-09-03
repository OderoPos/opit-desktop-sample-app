#pragma once

#include "../dll.h"
#include <stdexcept>
#include <cstring>

class DllExport CmdCode{
public:
    enum Value : size_t {
        Fiscalise,
        JournalInit,
        GetDateTime,
        GetVatRates,
        GetStatus,
        GetDailyTotals,
        GetZreport,
        GetSoftwareVersion
    };

    CmdCode();

    explicit CmdCode(
        const Value value_
    );

    const char* getName();
    static Value getEnum(const char* name);
    bool operator==(const CmdCode& rhs);

private:
    Value value;
};