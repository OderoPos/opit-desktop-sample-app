#pragma once

#include "../Request.h"
#include "../../../utils/ecr/Company.h"

class DllExport CompanyRequest : public Request {
private:
    Company* company = NULL;

public:
    CompanyRequest();

    explicit CompanyRequest(
        Company* company_,
        const char* uniqueId_
    );

    ~CompanyRequest();

    const Company* getCompany();
    void setCompany(Company* company_);

    bool operator==(const CompanyRequest& rhs);
    const char* toJson();
    static CompanyRequest fromJson(const char* json);
    void toString();
};