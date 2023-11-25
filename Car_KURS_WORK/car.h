#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>

#include "reg_log_area.h"
#include "helper.h"


using namespace std;


namespace filePATHS
{
	const string carPATH = "cars.txt";
}


class Car
{
private:
	int carID;
	string brand;
	string registrationNumber;
	double mileAge;
	double price;
	string condition;
public:
	Car();
	Car(string brand, string registrationNumber, double mileAge, double price, string condition);
	Car(const Car& otherCar);


	int getID() const;
	string getBrand() const;
	string getRegistrationNumber() const;
	double getMileAge() const;
	double getPrice() const;
	string getCondition() const;

	void setBrand(string brand);
	void setRegistrationNumber(string registrationNumber);
	void setMileAge(double mileAge);
	void setPrice(double price);
	void setCondition(string condition);

	void displayCarInfo() const;
	void spcDisplayCarInfo() const;


	friend ostream& operator<<(ostream& buf, const shared_ptr<Car>& carPtr);
	friend istream& operator>>(istream& buf, shared_ptr<Car>& carPtr);
};