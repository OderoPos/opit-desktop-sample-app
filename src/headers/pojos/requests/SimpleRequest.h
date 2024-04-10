#pragma once

#include "Request.h"

class SimpleRequest : public Request {
public:
    SimpleRequest();

    explicit SimpleRequest(
        const char* uniqueId_
    );

    ~SimpleRequest();

    bool operator==(const SimpleRequest& rhs);
    const std::string toJson();
    static SimpleRequest fromJson(const char* json);
    void toString();
};
