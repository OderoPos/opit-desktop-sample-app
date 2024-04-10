#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "../../utils/Constants.h"
#include "../../dll.h"

class ClientMessage {
public:
    ClientMessage();

    explicit ClientMessage(
        const char* type_,
        const char* message_
    );

    ~ClientMessage();

    std::string getType();
    void setType(std::string type_);
    std::string getMessage();
    void setMessage(std::string message_);
    bool operator==(const ClientMessage& rhs);
    const std::string toJson();
    static ClientMessage fromJson(const char* json);
    void toString();
};
