#pragma once

#include "../pojos/results/bank/PaymentResult.h"
#include "../pojos/results/bank/VoidResult.h"
#include "../pojos/results/bank/ReprintReceiptLastResult.h"
#include "../pojos/results/bank/ReprintReceiptNumberResult.h"
#include "../pojos/results/bank/DetailedXResult.h"
#include "../pojos/results/bank/SimpleXResult.h"
#include "../pojos/results/bank/LastSettlementResult.h"
#include "../pojos/results/bank/SettlementResult.h"
#include "../pojos/results/ecr/EcrResult.h"

class OpitResultListener {
public:
    void onPaymentResult(Result& result);
    void onVoidResult(Result& result);
    void onReprintLastResult(Result& result);
    void onReprintReceiptNoResult(Result& result);
    void onDetailedXReportResult(Result& result);
    void onSimpleXReportResult(Result& result);
    void onLastSettlementResult(Result& result);
    void onSettlementResult(Result& result);
    void onEcrCommandResult(Result& result);
    void onPairingDone(bool isPaired);
    void onError(const char* msg);
    void onDisconnected();
    void onConnected();
};
