#include "saleContract.h"
#include "helper.h"

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
	cout << "***************************************************************************************************************************************************************************" << endl;
	cout << "Договор купли-продажи транспортного средства №" << saleContractID << endl;
	cout << "Покупатель: " << customer.getName() << ", зарегистрированный по адресу: " << customer.getAddress() << ", и продавец заключили договор о нижеследующем:" << endl;
	cout << "1. Продавец обязуется передать в собственность покупателю, а покупатель обязуется оплатить следующее транспортное средство:" << endl;
	car.spcDisplayCarInfo();
	method->displayPaymentInfo();
	cout << "2. Продавец гарантирует, что транспортное средство свободно от любых прав третьих лиц, не находится в угоне, розыске." << endl;
	cout << "3. Право собственности покупателя на транспортное средство возникает в момент заключения настоящего Договора." << endl;
	cout << "4. Споры и разногласия, возникающие в связи с настоящим Договором, разрешаются в соответствии с действующим законодательством РБ." << endl;
	cout << "5. Настоящий договор составлен в 4 экземплярах, имеющих равную юридическую силу, и вступает в силу с момента его подписания Сторонами." << endl;
	cout << "***************************************************************************************************************************************************************************" << endl;
	system("pause");
}

int saleContract::getID() { return saleContractID; }
Car& saleContract::getCar() { return car; }
Customer& saleContract::getCustomer() { return customer; }
shared_ptr<PaymentMethod>& saleContract::getMethod() { return method; }

ostream& operator<<(ostream& buf, const shared_ptr<saleContract>& contractPtr)
{
	buf << contractPtr->getID() << ' ' << contractPtr->customer.getName() << ' ' << contractPtr->customer.getAddress() << ' ' << contractPtr->car.getBrand()
		<< ' ' << contractPtr->car.getRegistrationNumber() << ' ' << contractPtr->method->getMethodName() << ' ' << contractPtr->method->getCost() << ' ' << contractPtr->method->getFee() << ' '
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

	buf >> id >> name >> address >> brand >> regNumber >> methodName >> cost >> fee >> period >> percent >> monthlyFee >> resultCost;
	contractPtr->saleContractID = id;
	contractPtr->customer.setName(name);
	contractPtr->customer.setAddress(address);
	contractPtr->car.setBrand(brand);
	contractPtr->car.setRegistrationNumber(regNumber);

	if (methodName == "Рассрочка")
	{
		contractPtr->method = make_shared<InstallmentPayment>();
	}
	else if (methodName == "Лизинг")
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
