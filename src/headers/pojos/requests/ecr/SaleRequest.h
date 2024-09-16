#pragma once

#include "../../../utils/ecr/SaleCommand.h"
#include "../Request.h"

class DllExport SaleRequest : public Request {
private:
    SaleCommand* command = NULL;

public:
    SaleRequest();

    explicit SaleRequest(
        SaleCommand* command_,
        const char* uniqueId_
    );

    ~SaleRequest();

    const SaleCommand* getCommand();
    void setCommand(SaleCommand* command_);

    bool operator==(const SaleRequest& rhs);
    const char* toJson();
    static SaleRequest fromJson(const char* json);
    void toString();
};