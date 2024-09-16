#pragma once

#include <cstring>
#include "../../utils/StringUtils.h"
#include "../../dll.h"

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
        GetSoftwareVersion,
        Null
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