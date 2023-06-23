#pragma once

#include <typeinfo>
#include "OpitResultListener.h"
#include "../pojos/results/PaymentResult.h"
#include "../dll.h"

class DllExport InternalOpitResultListener {
    OpitResultListener resultListener;

public:
    InternalOpitResultListener(OpitResultListener resultListener_);
    void onSuccess(Result& result);
    void onError(std::string msg);
    void onDisconnected();
    void onConnected();
    void onReceivePairKey(std::string pairKey);
};