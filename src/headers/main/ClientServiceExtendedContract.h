#pragma once

#include "ClientServiceContract.h"
#include "OpitResultListener.h"
#include "../dll.h"

class DllExport ClientServiceExtendedContract : public ClientServiceContract {
    virtual bool isPairingComplete();
    virtual void setOpitResultListener(OpitResultListener& resultListener);
};