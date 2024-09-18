#include <iostream>
#include "headers/main/ResultListener.h"

void ResultListener::onPaymentResult(Result& result) {
    std::cout << "ResultListener onPaymentResult: ";
    result.toString();
}

void ResultListener::onVoidResult(Result& result) {
    std::cout << "ResultListener onVoidResult: ";
    result.toString();
}

void ResultListener::onReprintLastResult(Result& result) {
    std::cout << "ResultListener onReprintLastResult: ";
    result.toString();
}

void ResultListener::onReprintReceiptNoResult(Result& result) {
    std::cout << "ResultListener onReprintReceiptNoResult: ";
    result.toString();
}

void ResultListener::onDetailedXReportResult(Result& result) {
    std::cout << "ResultListener onDetailedXReportResult: ";
    result.toString();
}

void ResultListener::onSimpleXReportResult(Result& result) {
    std::cout << "ResultListener onSimpleXReportResult: ";
    result.toString();
}

void ResultListener::onLastSettlementResult(Result& result) {
    std::cout << "ResultListener onLastSettlementResult: ";
    result.toString();
}

void ResultListener::onSettlementResult(Result& result) {
    std::cout << "ResultListener onSettlementResult: ";
    result.toString();
}

void ResultListener::onEcrCommandResult(Result& result) {
    std::cout << "ResultListener onEcrCommandResult: ";
    result.toString();
}

void ResultListener::onPairingDone(bool isPaired) {
    std::cout << "ResultListener onPairingDone: " << isPaired << std::endl;
}

void ResultListener::onError(const char* msg) {
    std::cout << "ResultListener Error: " << msg << std::endl;
}

void ResultListener::onDisconnected() {
    std::cout << "ResultListener onDisconnected" << std::endl;
}

void ResultListener::onConnected() {
    std::cout << "ResultListener onConnected" << std::endl;
}