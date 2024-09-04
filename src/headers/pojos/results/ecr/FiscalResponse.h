#pragma once

#include "../Result.h"
#include "FiscalResponseValue.h"

class DllExport FiscalResponse : public Result {
private:
    FiscalResponseValue* fiscalResponseValue;

public:
    FiscalResponse();

    explicit FiscalResponse(
        FiscalResponseValue* fiscalResponseValue
    );

    ~FiscalResponse();

    const FiscalResponseValue* getFiscalResponseValue();
    void setFiscalResponseValue(FiscalResponseValue* fiscalResponseValue_);

    bool operator==(const FiscalResponse& rhs);
    const char* toJson();
    static FiscalResponse fromJson(const char* json);
    void toString();
};