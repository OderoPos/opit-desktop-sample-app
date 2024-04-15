#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "../../utils/Constants.h"
#include "../../dll.h"

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
    static ClientMessage fromJson(const char* json);
    void toString();
};
