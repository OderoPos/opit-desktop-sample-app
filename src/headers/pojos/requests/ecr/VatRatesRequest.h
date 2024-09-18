#pragma once

#include "../Request.h"
#include "../../../utils/ecr/VatRatesCommand.h"

class VatRatesRequest : public Request {
private:
    VatRatesCommand* command = nullptr;

public:
    VatRatesRequest();

    explicit VatRatesRequest(
        VatRatesCommand* command_,
        const char* uniqueId_
    );

    ~VatRatesRequest();

    const VatRatesCommand* getVatRatesCommand();
    void setVatRatesCommand(VatRatesCommand* command_);

    bool operator==(const VatRatesRequest& rhs);
    const char* toJson();
    static VatRatesRequest fromJson(const char* json);
    void toString();
};