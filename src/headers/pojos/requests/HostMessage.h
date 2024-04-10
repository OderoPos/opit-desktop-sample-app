#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "../../utils/Constants.h"
#include "../../dll.h"

class HostMessage {
public:
    HostMessage();

    explicit HostMessage(
        const char* pairCode_,
        const char* operationType_,
        const char* message_
    );

    ~HostMessage();

    bool operator==(const HostMessage& rhs);
    const std::string toJson();
    static HostMessage fromJson(const char* json);
    void toString();
};
