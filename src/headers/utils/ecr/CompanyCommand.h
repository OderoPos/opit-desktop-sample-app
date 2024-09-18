#pragma once

#include "Company.h"

class CompanyCommand {
private:
    Company* company = nullptr;

public:
    CompanyCommand();

    explicit CompanyCommand(
        Company* company_
    );

    ~CompanyCommand();

    const Company* getCompany();
    void setCompany(Company* company_);

    bool operator==(const CompanyCommand& rhs);
    const char* toJson();
    static CompanyCommand fromJson(const char* json);
    void toString();
};