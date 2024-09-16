#pragma once

#include "../Result.h"
#include "EcrResult.h"
#include "FailedCommand.h"

class DllExport FiscalResult : public Result {
private:
    EcrResult* fiscalResponse;
    FailedCommand* failedCommand;

public:
    FiscalResult();

    explicit FiscalResult(
        EcrResult* fiscalResponse_,
        FailedCommand* failedCommand_,
        const char* uniqueId_
    );

    ~FiscalResult();

    const EcrResult* getFiscalResponse();
    void setFiscalResponse(EcrResult* fiscalResponse_);

    const FailedCommand* getFailedCommand();
    void setFailedCommand(FailedCommand* failedCommand_);

    bool operator==(const FiscalResult& rhs);
    const char* toJson();
    static FiscalResult fromJson(const char* json);
    void toString();
};