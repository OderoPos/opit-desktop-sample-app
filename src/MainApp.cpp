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
void ecrFiscaliseCmd();
void ecrInitElectronicJournalCmd();
void ecrGetDateTimeCmd();
void ecrGetVATRatesCmd();
void ecrGetCompanyDataCmd();
void ecrGetStatusCmd();
void ecrGetDailyTotalsCmd();
void ecrGetZreportCmd();
void ecrGetSoftwareVersionCmd();
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
			std::cout << "13 for ecr InitJournal Report" << std::endl;
			std::cout << "14 for ecr Journal Report" << std::endl;
			std::cout << "15 for ecr XJournal Report" << std::endl;
			std::cout << "16 for ecr Customer Data Report" << std::endl;
			std::cout << "17 for ecr Periodic Report By Date" << std::endl;
			std::cout << "18 for ecr Periodic Report By Z" << std::endl;

			std::cout << "19 for ecr Fiscalise Cmd" << std::endl;
			std::cout << "20 for ecr Init Electronic Journal Cmd" << std::endl;
			std::cout << "21 for ecr Get Date Time Cmd" << std::endl;
			std::cout << "22 for ecr Get VAT Rates Cmd" << std::endl;
			std::cout << "23 for ecr Get Company Data Cmd" << std::endl;
			std::cout << "24 for ecr Get Status Cmd" << std::endl;
			std::cout << "25 for ecr Get Daily Totals Cmd" << std::endl;
			std::cout << "26 for ecr Get Zreport Cmd" << std::endl;
			std::cout << "27 for ecr Get Software Version Cmd" << std::endl;

			std::cout << "28 for ecr Set Company" << std::endl;
			std::cout << "29 for ecr Set Date Time" << std::endl;
			std::cout << "30 for ecr Set Vat Rates" << std::endl;
			std::cout << "31 for ecr Screen Request" << std::endl;
			std::cout << "32 to Exit" << std::endl;
			std::cout << "Choose option: ";

			std::cin >> option;

			if (option < 1 || option > 32) {
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
		case 19: ecrFiscaliseCmd(); break;
		case 20: ecrInitElectronicJournalCmd(); break;
		case 21: ecrGetDateTimeCmd(); break;
		case 22: ecrGetVATRatesCmd(); break;
		case 23: ecrGetCompanyDataCmd(); break;
		case 24: ecrGetStatusCmd(); break;
		case 25: ecrGetDailyTotalsCmd(); break;
		case 26: ecrGetZreportCmd(); break;
		case 27: ecrGetSoftwareVersionCmd(); break;

		case 28: ecrSetCompany(); break;
		case 29: ecrSetDateTime(); break;
		case 30: ecrSetVatRates(); break;
		case 31: ecrScreenRequest(); break;
		case 32: opit.destroy(); ExitProcess(0); break;
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
	const char* param1 = "";
	const char* param2 = "";

	opit.ecrCommandRequest(CmdCode::JournalInit, param1, param2, UNIQUE_ID);
}

void ecrSaleRequest() {
	SaleInfo* saleInfo = new SaleInfo(1, "operator");
	CustomerInfo* customerInfo = NULL;// new CustomerInfo("RO1592512");

	const int productSize = 1;
	ProductsInfo* products = new ProductsInfo[productSize] {
		ProductsInfo("Chocolate", "buc", "10", "5,70", VatRateType::B, NULL, NULL, NULL)
		//, ProductsInfo("Banana", "pcs", "2", "2,70", VatRateType::B, NULL, NULL, NULL)
	};

	const int paymentSize = 1;
	PaymentsInfo* payments = new PaymentsInfo[paymentSize] {
		PaymentsInfo(0, "5,70"),
		//, PaymentsInfo(0, "3,33")
	};

	const int freeTextSize = 2;
	FreeTextInfo* freeTexts = new FreeTextInfo[freeTextSize] {
		FreeTextInfo("Welcome", PagePosition::Head),
		FreeTextInfo("Goodbye!", PagePosition::Foot)
	};
	
	const int discountSize = 0;
	TotalAdjustments* discounts = NULL;
	//	new TotalAdjustments[discountSize] {
	//	TotalAdjustments(VatRateType::D, 0, 0, "1"),
	//	TotalAdjustments(VatRateType::A, 1, 2, "3")
	//};

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
	opit.ecrInitJournalReport(UNIQUE_ID);
}

void ecrJournal() {//YYMMddHHmmss
	const char* startDate = "240801010101";
	const char* stopDate = "240801010201";

	opit.ecrJournalReport(startDate, stopDate, UNIQUE_ID);
}

void ecrXJournal() {
	opit.ecrXJournalReport(UNIQUE_ID);
}

void ecrCustomerData() {
	opit.ecrCustomerDataReport(UNIQUE_ID);
}

void ecrPeriodicReportByDate() {//YYMMddHHmmss
	const char* startDate = "240801010101";
	const char* stopDate = "240801010201";

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
	opit.ecrVatRatesRequest(VatRateType::D, "9.00", UNIQUE_ID);
}

void ecrFiscaliseCmd() {
	opit.ecrFiscaliseCmd(UNIQUE_ID);
}
void ecrInitElectronicJournalCmd() {
	opit.ecrInitElectronicJournalCmd(UNIQUE_ID);
}
void ecrGetDateTimeCmd() {
	opit.ecrGetDateTimeCmd(UNIQUE_ID);
}
void ecrGetVATRatesCmd() {
	opit.ecrGetVATRatesCmd(UNIQUE_ID);
}
void ecrGetCompanyDataCmd() {
	opit.ecrGetCompanyDataCmd(UNIQUE_ID);
}
void ecrGetStatusCmd() {
	opit.ecrGetStatusCmd(UNIQUE_ID);
}
void ecrGetDailyTotalsCmd() {
	opit.ecrGetDailyTotalsCmd(UNIQUE_ID);
}
void ecrGetZreportCmd() {
	opit.ecrGetZreportCmd(UNIQUE_ID);
}
void ecrGetSoftwareVersionCmd() {
	opit.ecrGetSoftwareVersionCmd(UNIQUE_ID);
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