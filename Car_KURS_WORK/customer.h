#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

#include "reg_log_area.h"
#include "car.h"
#include "paymentMethods.h"

using namespace std;


namespace filePATHS
{
	const string customerPATH = "customers.txt";
}



class saleContract;


class Customer
{
private:
	string name;
	string address;

	shared_ptr<UserAccount> account;
public:
	Customer();
	Customer(shared_ptr<UserAccount> account);


	string getName();
	string getAddress();

	void setName(string name);
	void setAddress(string address);


	void displayCustomerInfo();

	void inputDataAboutYourSelf();

	void printAllCarInfo(const vector <shared_ptr<Car>>& carBASE);
	void sortCarInfo(vector <shared_ptr<Car>>& carBASE);
	void findCarInfo(const vector <shared_ptr<Car>>& carBASE);
	void filtrateCarInfo(const vector <shared_ptr<Car>>& carBASE);


	void orderCar(vector <shared_ptr<Car>>& carBASE);
};



class saleContract
{
private:
	int saleContractID;
	Car car;
	Customer customer;

	shared_ptr<PaymentMethod> method;
public:
	saleContract();
	saleContract(Customer& customer, Car& car, shared_ptr<PaymentMethod>& method);


	int getID();
	Car& getCar();
	Customer& getCustomer();
	shared_ptr<PaymentMethod>& getMethod();

	void displayContractInfo();

	friend ostream& operator<<(ostream& buf, const shared_ptr<saleContract>& contractPtr);
	friend istream& operator>>(istream& buf, shared_ptr<saleContract>& contractPtr);
};
