#pragma once

#include "../Request.h"

class DllExport SaleInfo {
private:
    int posNo;
    char* cashier;

public:
    SaleInfo();

    explicit SaleInfo(
        const int posNo_,
        const char* cashier_
    );

    ~SaleInfo();

    const int getPosNo();
    void setPosNo(const int posNo_);
    const char* getCashier();
    void setCashier(const char* cashier_);
    bool operator==(const SaleInfo& rhs);
    const char* toJson();
    static SaleInfo fromJson(const char* json);
    void toString();
};