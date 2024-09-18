#pragma once

#include "../Request.h"
#include "../../../utils/ecr/CompanyCommand.h"

class CompanyRequest : public Request {
private:
    CompanyCommand* command = nullptr;

public:
    CompanyRequest();

    explicit CompanyRequest(
        CompanyCommand* command_,
        const char* uniqueId_
    );

    ~CompanyRequest();

    const CompanyCommand* getCompanyCommand();
    void setCompanyCommand(CompanyCommand* command_);

    bool operator==(const CompanyRequest& rhs);
    const char* toJson();
    static CompanyRequest fromJson(const char* json);
    void toString();
};