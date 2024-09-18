#pragma once

#include "../Request.h"
#include "../../../utils/ecr/GetCommand.h"

class CommandRequest : public Request {
private:
    GetCommand* command = nullptr;

public:
    CommandRequest();

    explicit CommandRequest(
        GetCommand* command_,
        const char* uniqueId_
    );

    ~CommandRequest();

    const GetCommand* getCommand();
    void setCommand(GetCommand* command_);

    bool operator==(const CommandRequest& rhs);
    const char* toJson();
    static CommandRequest fromJson(const char* json);
    void toString();
};