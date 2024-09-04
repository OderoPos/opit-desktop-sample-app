#pragma once

#include "../Result.h"
#include "FiscalResponse.h"
#include "FailedCommand.h"

class DllExport FiscalResult : public Result {
private:
    FiscalResponse* fiscalResponse;
    FailedCommand* failedCommand;

public:
    FiscalResult();

    explicit FiscalResult(
        FiscalResponse* fiscalResponse_,
        FailedCommand* failedCommand_
    );

    ~FiscalResult();

    const FiscalResponse* getFiscalResponse();
    void setFiscalResponse(FiscalResponse* fiscalResponse_);

    const FailedCommand* getFailedCommand();
    void setFailedCommand(FailedCommand* failedCommand_);

    bool operator==(const FiscalResult& rhs);
    const char* toJson();
    static FiscalResult fromJson(const char* json);
    void toString();
};