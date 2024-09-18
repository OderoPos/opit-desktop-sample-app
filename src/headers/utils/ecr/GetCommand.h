#pragma once

#include "CodeCommand.h"

class GetCommand {
private:
    CodeCommand* command = nullptr;

public:
    GetCommand();

    explicit GetCommand(
        CodeCommand* command_
    );

    ~GetCommand();

    const CodeCommand* getCommand();
    void setCommand(CodeCommand* command_);

    bool operator==(const GetCommand& rhs);
    const char* toJson();
    static GetCommand fromJson(const char* json);
    void toString();
};