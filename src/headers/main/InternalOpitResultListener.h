#pragma once

#include <typeinfo>
#include "OpitResultListener.h"
#include "../dll.h"

class DllExport 
InternalOpitResultListener {
    OpitResultListener resultListener;

public:
    InternalOpitResultListener(OpitResultListener resultListener_);
    void onSuccess(Result& result);
    void onError(const char* msg);
    void onDisconnected();
    void onConnected();
    void onReceivePairKey(const char* pairKey);
};
