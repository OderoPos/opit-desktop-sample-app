#pragma once

#include "../Result.h"

class DllExport FiscalResponseValue {
private:
    int code;
    char* description;
    char* location;
    char* nativeCode;

public:
    FiscalResponseValue();

    explicit FiscalResponseValue(
        const int code_,
        const char* description_,
        const char* location_,
        const char* nativeCode_
    );

    ~FiscalResponseValue();

    const int getCode();
    void setCode(const int code_);
    const char* getDescription();
    void setDescription(const char* description_);
    const char* getLocation();
    void setLocation(const char* location_);
    const char* getNativeCode();
    void setNativeCode(const char* nativeCode_);
    bool operator==(const FiscalResponseValue& rhs);
    const char* toJson();
    static FiscalResponseValue fromJson(const char* json);
    void toString();
};