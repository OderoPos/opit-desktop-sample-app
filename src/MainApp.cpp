#pragma once

#include "headers/main/OpitClient.h"
#include "headers/main/ResultListener.h"
#include "headers/utils/Sleep.hpp"

BOOL WINAPI ExitHandlerRoutine(DWORD eventCode);
void sale();
void doVoid();
void reprintLast();
void reprintReceiptById();
void detailedX();
void simpleX();
void lastSettlementCopy();
void startSettlement();
void resolveChooser(int option);
void ecrCommandRequest();
void ecrSaleRequest();
void ecrTechnicalReport();
void ecrZReport();
void ecrXReport();
void ecrInitJournal();
void ecrJournal();
void ecrXJournal();
void ecrCustomerData();
void ecrPeriodicReportByDate();
void ecrPeriodicReportByZ();
void ecrSetCompany();
void ecrSetDateTime();
void ecrSetVatRates();
void ecrScreenRequest();

#define UNIQUE_ID "73qyedhyecgyd7efyuaehudsjh"

ResultListener resultListener;
OpitClient opit(resultListener);

int __cdecl main(int argc, char** argv) {
	SetConsoleCtrlHandler(ExitHandlerRoutine, TRUE);
	int option;

    do {
		if (!opit.isConnected()) {
			while (!opit.start()) {
				std::cout << "client ping" << std::endl;
				Sleep(ONE_SECOND);
			}
		}
		else {
			std::cout << "\nInsert number:" << std::endl;
			std::cout << "1 for Sale" << std::endl;
			std::cout << "2 for Void" << std::endl;
			std::cout << "3 for Reprint Last" << std::endl;
			std::cout << "4 for Reprint Receipt No." << std::endl;
			std::cout << "5 for Detailed X Report" << std::endl;
			std::cout << "6 for Simple X Report" << std::endl;
			std::cout << "7 for Last Settlement Copy" << std::endl;
			std::cout << "8 for Start Settlement" << std::endl;
			std::cout << "9 for ecr Sale Request" << std::endl;
			std::cout << "10 for ecr Technical Report" << std::endl;
			std::cout << "11 for ecr ZReport" << std::endl;
			std::cout << "12 for ecr XReport" << std::endl;
			std::cout << "13 for ecr InitJournal" << std::endl;
			std::cout << "14 for ecr Journal" << std::endl;
			std::cout << "15 for ecr XJournal" << std::endl;
			std::cout << "16 for ecr Customer Data" << std::endl;
			std::cout << "17 for ecr Periodic Report By Date" << std::endl;
			std::cout << "18 for ecr Periodic Report By Z" << std::endl;
			std::cout << "19 for ecr Set Company" << std::endl;
			std::cout << "20 for ecr Set Date Time" << std::endl;
			std::cout << "21 for ecr Set Vat Rates" << std::endl;
			std::cout << "22 for ecr Screen Request" << std::endl;
			std::cout << "23 to Exit" << std::endl;
			std::cout << "Choose option: ";

			std::cin >> option;

			if (option < 1 || option > 23) {
				std::cin.clear();
				std::cout << "Wrong choice." << std::endl;
				return 0;
			}

			resolveChooser(option);
		}

	} while (opit.isConnected());

	std::cout << "Program has exit. Press ENTER to close the window." << std::endl;
	getchar();
	return 0;
}


void resolveChooser(int option) {
	switch (option) {
		case 1: sale(); break;
		case 2: doVoid(); break;
		case 3: reprintLast(); break;
		case 4: reprintReceiptById(); break;
		case 5: detailedX(); break;
		case 6: simpleX(); break;
		case 7: lastSettlementCopy(); break;
		case 8: startSettlement(); break;
		case 9: ecrSaleRequest(); break;
		case 10: ecrTechnicalReport(); break;
		case 11: ecrZReport(); break;
		case 12: ecrXReport(); break;
		case 13: ecrInitJournal(); break;
		case 14: ecrJournal(); break;
		case 15: ecrXJournal(); break;
		case 16: ecrCustomerData(); break;
		case 17: ecrPeriodicReportByDate(); break;
		case 18: ecrPeriodicReportByZ(); break;
		case 19: ecrSetCompany(); break;
		case 20: ecrSetDateTime(); break;
		case 21: ecrSetVatRates(); break;
		case 22: ecrScreenRequest(); break;
		case 23: opit.destroy(); ExitProcess(0); break;
		default: {
			std::cout << "Unknown choice" << std::endl;
			break;
		}
	}
}

void sale() {
	std::cout << "Insert amount: ";
	double amount;
	std::cin >> amount;
	std::cin.clear();

	opit.sendPaymentRequest(amount, "RON", UNIQUE_ID);
}

void doVoid() {
	std::cout << "Insert receipt number: ";
	std::string receiptNo;
	std::cin >> receiptNo;
	std::cin.clear();

	opit.voidReceipt(receiptNo.c_str(), UNIQUE_ID);
}

void reprintLast() {
	opit.reprintLastReceipt(UNIQUE_ID);
}

void reprintReceiptById() {
	std::cout << "Insert receipt number: ";
	std::string receiptNo;
	std::cin >> receiptNo;
	std::cin.clear();

	opit.reprintReceiptNo(receiptNo.c_str(), UNIQUE_ID);
}

void detailedX() {
	opit.getDetailedXReport("RON", UNIQUE_ID);
}

void simpleX() {
	opit.getSimpleXReport("RON", UNIQUE_ID);
}

void lastSettlementCopy() {
	opit.printLastSettlement("RON", UNIQUE_ID);
}

void startSettlement() {
	opit.printSettlement(UNIQUE_ID);
}

void ecrCommandRequest() {
	const char* param1 = "";//horia bookmark
	const char* param2 = "";

	opit.ecrCommandRequest(CmdCode::JournalInit, param1, param2, UNIQUE_ID);
}

void ecrSaleRequest() {
	SaleInfo* saleInfo = new SaleInfo(1, "Employee 1");
	CustomerInfo* customerInfo = new CustomerInfo("RO1592512");

	const int productSize = 2;
	ProductsInfo* products = new ProductsInfo[productSize] {
		ProductsInfo("Chocolate", "pcs", "10", VatRate::D, 0, 0, "0"),
		ProductsInfo("Banana", "pcs", "2", VatRate::E, 0, 0, "0")
	};

	const int paymentSize = 2;
	PaymentsInfo* payments = new PaymentsInfo[paymentSize] {
		PaymentsInfo(0, "1,00"),
		PaymentsInfo(0, "3,33")
	};

	const int freeTextSize = 2;
	FreeTextInfo* freeTexts = new FreeTextInfo[freeTextSize] {
		FreeTextInfo("Welcome", PagePosition::Head),
		FreeTextInfo("Goodbye!", PagePosition::Foot)
	};
	
	const int discountSize = 2;
	TotalAdjustments* discounts = new TotalAdjustments[discountSize] {
		TotalAdjustments(VatRate::D, 0, 0, "1"),
		TotalAdjustments(VatRate::A, 1, 2, "3")
	};

	opit.ecrSaleRequest(
		saleInfo, customerInfo,
		products, productSize,
		payments, paymentSize,
		freeTexts, freeTextSize,
		discounts, discountSize, UNIQUE_ID);
}

void ecrTechnicalReport() {
	opit.ecrTechnicalReport(UNIQUE_ID);
}

void ecrZReport() {
	opit.ecrZReport(UNIQUE_ID);
}

void ecrXReport() {
	opit.ecrXReport(UNIQUE_ID);
}

void ecrInitJournal() {
	opit.ecrInitJournal(UNIQUE_ID);
}

void ecrJournal() {//YYMMddHHmmss
	const char* startDate = "240801010101";
	const char* stopDate = "240801010101";

	opit.ecrJournal(startDate, stopDate, UNIQUE_ID);
}

void ecrXJournal() {
	opit.ecrXJournal(UNIQUE_ID);
}

void ecrCustomerData() {
	opit.ecrCustomerData(UNIQUE_ID);
}

void ecrPeriodicReportByDate() {//YYMMddHHmmss
	const char* startDate = "240801010101";
	const char* stopDate = "240801010101";

	opit.ecrPeriodicReportByDate(startDate, stopDate, UNIQUE_ID);
}

void ecrPeriodicReportByZ() {
	int* startZ = new int(7);
	int* stopZ = new int(14);

	opit.ecrPeriodicReportByZ(startZ, stopZ, UNIQUE_ID);
}

void ecrSetCompany() {
	const char* name = "TOKEN PAYMENT SERVICES SRL";
	const char* address = "Str. Gara Herastrau, cladirea 5C";
	const char* cui = "43511483";
	const char* fiscalSeries = "1234567890";

	opit.ecrSetCompanyRequest(name, address, cui, fiscalSeries, UNIQUE_ID);
}

void ecrSetDateTime() {//YYMMddHHmmss
	const char* value = "240901010101";

	opit.ecrSetDateTimeRequest(value, UNIQUE_ID);
}

void ecrSetVatRates() {
	opit.ecrVatRatesRequest(VatRate::D, "9.00", UNIQUE_ID);
}

void ecrScreenRequest() {
	const char* value = "111";

	opit.ecrScreenRequest(value, UNIQUE_ID);
}

BOOL WINAPI ExitHandlerRoutine(DWORD eventCode) {
	/*
	switch (eventCode) {
		case CTRL_CLOSE_EVENT:
			opit.destroy();
			return TRUE;
		}
	*/

	opit.destroy();
	return TRUE;
}