#pragma once

#include "../Request.h"

class DllExport SimpleRequest : public Request {

public:
    SimpleRequest();

    explicit SimpleRequest(
        const char* uniqueId_
    );

    ~SimpleRequest();

    bool operator==(const SimpleRequest& rhs);
    const char* toJson();
    static SimpleRequest fromJson(const char* json);
    void toString();
};
