#pragma once

static const long USB_TIMEOUT_IN_MS = 5 * 1000;
static const long BUFFER_SIZE_IN_BYTES = 256 * 50;

static const char* Odero = "Odero";
static const char* OderoPOS = "OderoPOS";
static const char* POS = "POS";
static const char* OderoWeb = "https://odero.ro/all-in-one-pos";

static const char* TYPE_REQUEST_PAIR_CODE = "TYPE_REQUEST_PAIR_CODE";
static const char* TYPE_RECEIVE_PAIR_CODE = "TYPE_RECEIVE_PAIR_CODE";
static const char* TYPE_ERROR = "TYPE_ERROR";
static const char* TYPE_SUCCESS = "TYPE_SUCCESS";
static const char* STATUS_TYPE = "status_type";

static const char* TYPE_PAYMENT = "TYPE_PAYMENT";
static const char* TYPE_SETTLEMENT = "TYPE_SETTLEMENT";
static const char* TYPE_LAST_SETTLEMENT = "TYPE_LAST_SETTLEMENT";
static const char* TYPE_SIMPLE_X_REPORT = "TYPE_SIMPLE_X_REPORT";
static const char* TYPE_DETAILED_X_REPORT = "TYPE_DETAILED_X_REPORT";
static const char* TYPE_REPRINT_RECEIPT_NO = "TYPE_REPRINT_RECEIPT_NO";
static const char* TYPE_REPRINT_RECEIPT_LAST = "TYPE_REPRINT_RECEIPT_LAST";
static const char* TYPE_VOID = "TYPE_VOID";
static const char* OPERATION_TYPE = "operation_type";
static const char* OPERATION_RESULT = "result";

static const int NOTIFICATION_ID_HOST = 101;
static const int NOTIFICATION_ID_CLIENT = 102;