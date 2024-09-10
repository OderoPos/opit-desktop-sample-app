#pragma once

#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport Company {
private:
    char* name = NULL;
    char* address = NULL;
    char* cui = NULL;
    char* fiscalSeries = NULL;

public:
    Company();

    explicit Company(
        const char* name_,
        const char* address_,
        const char* cui_,
        const char* fiscalSeries_
    );

    ~Company();

    const char* getName();
    void setName(const char* name_);

    const char* getAddress();
    void setAddress(const char* address_);

    const char* getCui();
    void setCui(const char* cui_);

    const char* getFiscalSeries();
    void setFiscalSeries(const char* fiscalSeries_);

    bool operator==(const Company& rhs);
    const char* toJson();
    static Company fromJson(const char* json);
    void toString();
};