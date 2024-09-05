#pragma once

#include "../Result.h"

class DllExport ScreenResponseValue {
private:
    bool successful;
    char* failedText;

public:
    ScreenResponseValue();

    explicit ScreenResponseValue(
        const bool successful_,
        const char* failedText_
    );

    ~ScreenResponseValue();

    const bool getSuccessful();
    void setSuccessful(const bool successful_);
    const char* getFailedText();
    void setFailedText(const char* failedText_);

    bool operator==(const ScreenResponseValue& rhs);
    const char* toJson();
    static ScreenResponseValue fromJson(const char* json);
    void toString();
};