#pragma once

#include <cstring>

class CmdCode {
public:
    enum Value : size_t {
        Fiscalise,
        JournalInit,
        GetDateTime,
        GetVatRates,
        GetCompanyData,
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