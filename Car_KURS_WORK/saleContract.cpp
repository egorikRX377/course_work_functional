#include "helper.h"
#include "car.h"
#include "customer.h"

using namespace std;


extern vector<shared_ptr<saleContract>> contractBASE;


saleContract::saleContract(Customer& customer, Car& car, shared_ptr<PaymentMethod>& method) : customer(customer), car(car), method(method)
{
	saleContractID = generateUniqueID<saleContract>(contractBASE);
}

saleContract::saleContract()
{
	saleContractID = generateUniqueID<saleContract>(contractBASE);
}

void saleContract::displayContractInfo()
{
	cout << "\t\t\t| ***************************************************************************************************************************************************************************" << endl;
	cout << "\t\t\t| ������� �����-������� ������������� �������� �" << saleContractID << endl;
	cout << "\t\t\t| ����������: " << customer.getName() << ", ������������������ �� ������: " << customer.getAddress() << ", � �������� ��������� ������� � �������������:" << endl;
	cout << "\t\t\t| 1. �������� ��������� �������� � ������������� ����������, � ���������� ��������� �������� ��������� ������������ ��������:" << endl;
	car.spcDisplayCarInfo();
	method->displayPaymentInfo();
	cout << "\t\t\t| 2. �������� �����������, ��� ������������ �������� �������� �� ����� ���� ������� ���, �� ��������� � �����, �������." << endl;
	cout << "\t\t\t| 3. ����� ������������� ���������� �� ������������ �������� ��������� � ������ ���������� ���������� ��������." << endl;
	cout << "\t\t\t| 4. ����� � �����������, ����������� � ����� � ��������� ���������, ����������� � ������������ � ����������� ����������������� ��." << endl;
	cout << "\t\t\t| 5. ��������� ������� ��������� � 4 �����������, ������� ������ ����������� ����, � �������� � ���� � ������� ��� ���������� ���������." << endl;
	cout << "\t\t\t| ***************************************************************************************************************************************************************************" << endl;
	cout << "\t\t\t| "; system("pause");
}

int saleContract::getID() { return saleContractID; }
Car& saleContract::getCar() { return car; }
Customer& saleContract::getCustomer() { return customer; }
shared_ptr<PaymentMethod>& saleContract::getMethod() { return method; }

ostream& operator<<(ostream& buf, const shared_ptr<saleContract>& contractPtr)
{
	buf << contractPtr->getID() << ' ' << contractPtr->customer.getName() << ',' << contractPtr->customer.getAddress() << '~' << contractPtr->car.getBrand()
		<< ',' << contractPtr->car.getRegistrationNumber() << ',' << contractPtr->method->getMethodName() << ',' << contractPtr->method->getCost() << ' ' << contractPtr->method->getFee() << ' '
		<< contractPtr->method->getPeriod() << ' ' << contractPtr->method->getPercent() << ' ' << contractPtr->method->getMonthlyFee() << ' ' << contractPtr->method->getResultCost() << endl;
	return buf;
}
istream& operator>>(istream& buf, shared_ptr<saleContract>& contractPtr)
{
	int id;
	string name;
	string address;
	string brand;
	string regNumber;

	string methodName;
	double cost;
	double fee;
	int period;
	int percent;
	double monthlyFee;
	double resultCost;

	buf >> id;
	getline(buf >> ws, name, ',');
	getline(buf >> ws, address, '~');
	getline(buf >> ws, brand, ',');
	getline(buf >> ws, regNumber, ',');
	getline(buf >> ws, methodName, ',');
	buf >> cost >> fee >> period >> percent >> monthlyFee >> resultCost;

	contractPtr->saleContractID = id;
	contractPtr->customer.setName(name);
	contractPtr->customer.setAddress(address);
	contractPtr->car.setBrand(brand);
	contractPtr->car.setRegistrationNumber(regNumber);

	if (methodName == "���������")
	{
		contractPtr->method = make_shared<InstallmentPayment>();
	}
	else if (methodName == "������")
	{
		contractPtr->method = make_shared<Leasing>();
	}
	else
	{
		return buf;
	}
	contractPtr->method->setMethodName(methodName);
	contractPtr->method->setCost(cost);
	contractPtr->method->setFee(fee);
	contractPtr->method->setPeriod(period);
	contractPtr->method->setPercent(percent);
	contractPtr->method->setMonthlyFee(monthlyFee);
	contractPtr->method->setResultCost(resultCost);

	return buf;
}
