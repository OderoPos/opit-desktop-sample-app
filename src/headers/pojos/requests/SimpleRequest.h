#pragma once

#include "Request.h"

class DllExport SimpleRequest : public Request {
private:
    char* uniqueId;

public:
    SimpleRequest();

    explicit SimpleRequest(
        const char* uniqueId_
    );

    ~SimpleRequest();

    const char* getUniqueId();
    void setUniqueId(const char* uniqueId_);
    bool operator==(const SimpleRequest& rhs);
    const char* toJson();
    static SimpleRequest fromJson(const char* json);
    void toString();
};
