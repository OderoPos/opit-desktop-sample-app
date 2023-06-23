#pragma once

#include <winrt/Windows.Data.Json.h>
#include "../../dll.h"

using namespace winrt::Windows::Data::Json;

class DllExport HostMessage {
private:
    char* pairCode;
    char* operationType;
    char* message;

public:
    HostMessage();

    explicit HostMessage(
        const char* pairCode_,
        const char* operationType_,
        const char* message_
    );

    ~HostMessage();

    const char* getPairCode();
    void setPairCode(const char* pairCode_);
    const char* getOperationType();
    void setOperationType(const char* operationType_);
    const char* getMessage();
    void setMessage(const char* message_);
    bool operator==(const HostMessage& rhs);
    const char* toJson();
    static HostMessage fromJson(const char*& json);
    void toString();
};