#include "paymentMethods.h"


using namespace std;

PaymentMethod::PaymentMethod()
{
	methodName = "unknown";
	cost = -1;
	fee = -1;
	period = -1;
	percent = -1;
	monthlyFee = -1;
	resultCost = -1;
}

double PaymentMethod::calcMonthlyFee()
{
	double monthlyPercent = double(percent) / 12;
	double result = ((cost - fee) / period) * (1 + monthlyPercent / 100);
	return result;
}
double PaymentMethod::calcResultCost(double monthlyFee)
{
	double result = monthlyFee * period + fee;
	return result;
}
void PaymentMethod::inputPeriod()
{
	while (1)
	{
		int somePeriod;
		bool correctInput = false;
		cin >> somePeriod;
		switch (somePeriod)
		{
		case oneYear:
		{
			period = oneYear;
			correctInput = true;
			break;
		}
		case threeYears:
		{
			period = threeYears;
			correctInput = true;
			break;
		}
		case fiveYears:
		{
			period = fiveYears;
			correctInput = true;
			break;
		}
		default:
			cout << "Не верный ввод!" << endl;
		}
		if (correctInput)
		{
			break;
		}
	}
}

string PaymentMethod::getMethodName() { return methodName; }
double PaymentMethod::getCost() { return cost; }
double PaymentMethod::getFee() { return fee; }
int PaymentMethod::getPeriod() { return period; }
int PaymentMethod::getPercent() { return percent; }
double PaymentMethod::getMonthlyFee() { return monthlyFee; }
double PaymentMethod::getResultCost() { return resultCost; }

void PaymentMethod::setMethodName(string methodName) { this->methodName = methodName; }
void PaymentMethod::setCost(double cost) { this->cost = cost; }
void PaymentMethod::setFee(double fee) { this->fee = fee; }
void PaymentMethod::setPeriod(int period) { this->period = period; }
void PaymentMethod::setPercent(int percent) { this->percent = percent; }
void PaymentMethod::setMonthlyFee(double monthlyFee) { this->monthlyFee = monthlyFee; }
void PaymentMethod::setResultCost(double resultCost) { this->resultCost = resultCost; }


InstallmentPayment::InstallmentPayment() {}
InstallmentPayment::InstallmentPayment(double cost)
{
	this->methodName = "Рассрочка";
	this->cost = cost;
	cout << "Введите первоначальный взнос: ";
	cin >> fee;
	this->percent = 10;
	cout << "Введите срок выплат: 12/36/60 :  ";
	inputPeriod();
	monthlyFee = calcMonthlyFee();
	resultCost = calcResultCost(monthlyFee);
}
void InstallmentPayment::displayPaymentInfo()
{
	cout << "=====================================================" << endl;
	cout << "Выбран метод оплаты: " << methodName << endl;
	cout << "Cтоимость автомобиля: " << cost << endl;
	cout << "Первоначальный взнос: " << fee << endl;
	cout << "Период выплат: " << period << endl;
	cout << "Ежемесячный платёж с учётом процента: " << monthlyFee << endl;
	cout << "Результирующая стоимость: " << resultCost << endl;
	cout << "=====================================================" << endl;
}

Leasing::Leasing() {}
Leasing::Leasing(double cost)
{
	this->methodName = "Лизинг";
	this->cost = cost;
	this->percent = 8;
	cout << "Введите срок аренды: 12/36/60 :  ";
	inputPeriod();
	fee = 0.6 * cost;
	monthlyFee = calcMonthlyFee();
	resultCost = calcResultCost(monthlyFee);
}
void Leasing::displayPaymentInfo()
{
	cout << "=====================================================" << endl;
	cout << "Выбран метод оплаты: " << methodName << endl;
	cout << "Стоимость автомобиля: " << cost << endl;
	cout << "Остаточная стоимость: " << fee << endl;
	cout << "Период аренды: " << period << endl;
	cout << "Ежемесячный платёж с учётом процента: " << monthlyFee << endl;
	cout << "Результирующая стоимость: " << resultCost << endl;
	cout << "=====================================================" << endl;
}