#pragma once

#include "../../utils/StringUtils.h"
#include "../../dll.h"

class DllExport SaleInfo {
private:
    int posNo = 0;
    char* cashier = NULL;

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