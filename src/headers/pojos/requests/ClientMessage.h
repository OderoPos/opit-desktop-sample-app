#pragma once

#include <winrt/Windows.Data.Json.h>
#include "../../dll.h"

using namespace winrt::Windows::Data::Json;

class DllExport ClientMessage {
private:
    char* type;
    char* message;

public:
    ClientMessage();

    explicit ClientMessage(
        const char* type_,
        const char* message_
    );

    ~ClientMessage();

    const char* getType();
    void setType(const char* type_);
    const char* getMessage();
    void setMessage(const char* message_);
    bool operator==(const ClientMessage& rhs);
    const char* toJson();
    static ClientMessage fromJson(const char*& json);
    void toString();
};