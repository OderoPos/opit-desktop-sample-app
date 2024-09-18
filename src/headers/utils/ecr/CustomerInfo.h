#pragma once

class CustomerInfo {
private:
    char* cui = nullptr;

public:
    CustomerInfo();

    explicit CustomerInfo(
        const char* cui_
    );

    ~CustomerInfo();

    const char* getCui();
    void setCui(const char* cui_);

    bool operator==(const CustomerInfo& rhs);
    const char* toJson();
    static CustomerInfo fromJson(const char* json);
    void toString();
};