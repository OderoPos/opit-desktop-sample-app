#pragma once

#include "../Request.h"

class DllExport SetCompanyRequest : public Request {
private:
    char* name = NULL;
    char* address = NULL;
    char* cui = NULL;
    char* fiscalSeries = NULL;

public:
    SetCompanyRequest();

    explicit SetCompanyRequest(
        const char* name_,
        const char* address_,
        const char* cui_,
        const char* fiscalSeries_,
        const char* uniqueId_
    );

    ~SetCompanyRequest();

    const char* getName();
    void setName(const char* name_);

    const char* getAddress();
    void setAddress(const char* address_);

    const char* getCui();
    void setCui(const char* cui_);

    const char* getFiscalSeries();
    void setFiscalSeries(const char* fiscalSeries_);

    bool operator==(const SetCompanyRequest& rhs);
    const char* toJson();
    static SetCompanyRequest fromJson(const char* json);
    void toString();
};