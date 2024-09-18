#pragma once

#include "CmdCode.h"

class CodeCommand {
private:
    CmdCode cmdCode;
    char* param1 = nullptr;
    char* param2 = nullptr;

public:
    CodeCommand();

    explicit CodeCommand(
        const CmdCode::Value cmdCode_,
        const char* param1_,
        const char* param2_
    );

    ~CodeCommand();

    const CmdCode getCmdCode();
    void setCmdCode(const CmdCode cmdCode_);

    const char* getParam1();
    void setParam1(const char* param1_);

    const char* getParam2();
    void setParam2(const char* param2_);

    bool operator==(const CodeCommand& rhs);
    const char* toJson();
    static CodeCommand fromJson(const char* json);
    void toString();
};