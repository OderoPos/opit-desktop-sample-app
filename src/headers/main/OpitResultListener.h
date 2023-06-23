#pragma once

#include <iostream>
#include "../pojos/results/PaymentResult.h"
#include "../pojos/results/VoidResult.h"
#include "../pojos/results/ReprintReceiptLastResult.h"
#include "../pojos/results/ReprintReceiptNumberResult.h"
#include "../pojos/results/DetailedXResult.h"
#include "../pojos/results/SimpleXResult.h"
#include "../pojos/results/LastSettlementResult.h"
#include "../pojos/results/SettlementResult.h"
#include "../dll.h"

class DllExport OpitResultListener {
public:
    void onPaymentResult(Result& result);
    void onVoidResult(Result& result);
    void onReprintLastResult(Result& result);
    void onReprintReceiptNoResult(Result& result);
    void onDetailedXReportResult(Result& result);
    void onSimpleXReportResult(Result& result);
    void onLastSettlementResult(Result& result);
    void onSettlementResult(Result& result);
    void onPairingDone(bool isPaired);
    void onError(std::string msg);
    void onDisconnected();
    void onConnected();
};