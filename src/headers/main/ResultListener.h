#pragma once

#include "OpitResultListener.h"

class ResultListener : public OpitResultListener {
	void onPaymentResult(Result& result);
	void onVoidResult(Result& result);
	void onReprintLastResult(Result& result);
	void onReprintReceiptNoResult(Result& result);
	void onDetailedXReportResult(Result& result);
	void onSimpleXReportResult(Result& result);
	void onLastSettlementResult(Result& result);
	void onSettlementResult(Result& result);
	void onFiscalCommandResult(Result& result);
	void onScreenCommandResult(Result& result);
	void onPairingDone(bool isPaired);
	void onError(const char* msg);
	void onDisconnected();
	void onConnected();
};