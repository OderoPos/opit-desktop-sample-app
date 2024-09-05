#pragma once

#include "../Result.h"
#include "ScreenResponseValue.h"

class DllExport ScreenResult : public Result {
private:
    ScreenResponseValue* screenResponseValue;

public:
    ScreenResult();

    explicit ScreenResult(
        ScreenResponseValue* screenResponseValue,
        const char* uniqueId_
    );

    ~ScreenResult();

    const ScreenResponseValue* getScreenResponseValue();
    void setScreenResponseValue(ScreenResponseValue* screenResponseValue_);

    bool operator==(const ScreenResult& rhs);
    const char* toJson();
    static ScreenResult fromJson(const char* json);
    void toString();
};