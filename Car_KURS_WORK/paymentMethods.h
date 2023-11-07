#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <time.h>	
#include <stdlib.h>


using namespace std;


enum periods
{
	oneYear = 12, threeYears = 36, fiveYears = 60
};



class PaymentMethod
{
protected:
	string methodName;
	double cost;
	double fee;
	int period;
	int percent;
	double monthlyFee;
	double resultCost;
public:
	PaymentMethod();

	double calcMonthlyFee();
	double calcResultCost(double monthlyFee);

	string getMethodName();
	double getCost();
	double getFee();
	int getPeriod();
	int getPercent();
	double getMonthlyFee();
	double getResultCost();

	void setMethodName(string methodName);
	void setCost(double cost);
	void setFee(double fee);
	void setPeriod(int period);
	void setPercent(int percent);
	void setMonthlyFee(double monthlyFee);
	void setResultCost(double resultCost);

	void inputPeriod();
	virtual void displayPaymentInfo() = 0;
};

class InstallmentPayment : public PaymentMethod
{
public:
	InstallmentPayment();
	InstallmentPayment(double cost);
	void displayPaymentInfo() override;
};
class Leasing : public PaymentMethod
{
public:
	Leasing();
	Leasing(double cost);
	void displayPaymentInfo() override;
};