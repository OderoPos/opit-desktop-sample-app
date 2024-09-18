#pragma once

#include "Sale.h"

class SaleCommand {
private:
    Sale* sale = nullptr;

public:
    SaleCommand();

    explicit SaleCommand(
        Sale* sale_
    );

    ~SaleCommand();

    const Sale* getSale();
    void setSale(Sale* sale_);

    bool operator==(const SaleCommand& rhs);
    const char* toJson();
    static SaleCommand fromJson(const char* json);
    void toString();
};