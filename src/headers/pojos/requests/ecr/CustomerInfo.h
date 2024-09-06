#pragma once

#include "../Request.h"

class DllExport CustomerInfo {
private:
    char* cui = NULL;

public:
    CustomerInfo();

    explicit CustomerInfo(
        const char* cui_
    );

    ~CustomerInfo();

    const char* getCui();
    void setCui(const char* cui_);

    bool operator==(const CustomerInfo& rhs);
    const char* toJson();
    static CustomerInfo fromJson(const char* json);
    void toString();
};