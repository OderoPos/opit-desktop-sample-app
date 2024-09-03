#pragma once

#include "../Request.h"
#include "../../../utils/CmdCode.h"

class DllExport CommandRequest : public Request {
private:
    CmdCode cmdCode;
    char* param1;
    char* param2;

public:
    CommandRequest();

    explicit CommandRequest(
        const CmdCode cmdCode_,
        const char* param1_,
        const char* param2_
    );

    ~CommandRequest();

    const CmdCode getCmdCode();
    void setCmdCode(const CmdCode cmdCode_);
    const char* getParam1();
    void setParam1(const char* param1_);
    const char* getParam2();
    void setParam2(const char* param2_);
    bool operator==(const CommandRequest& rhs);
    const char* toJson();
    static CommandRequest fromJson(const char* json);
    void toString();
};