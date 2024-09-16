#pragma once

#include "../../utils/ecr/Sale.h"

class DllExport SaleCommand {
private:
    Sale* sale = NULL;

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