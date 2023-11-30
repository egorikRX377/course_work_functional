#include "car.h"


using namespace std;


extern vector<shared_ptr<Car>> carBASE;


Car::Car() : brand("unkown"), registrationNumber("unknown"), mileAge(0.00), price(0.00), condition("unknown")
{
	carID = generateUniqueID<Car>(carBASE);
}
Car::Car(string brand, string registrationNumber, double mileAge, double price, string condition) :
	brand(brand), registrationNumber(registrationNumber), mileAge(mileAge), price(price), condition(condition)
{
	carID = generateUniqueID<Car>(carBASE);
}
Car::Car(const Car& otherCar)
{
	this->carID = generateUniqueID<Car>(carBASE);
	this->brand = otherCar.brand;
	this->registrationNumber = otherCar.registrationNumber;
	this->mileAge = otherCar.mileAge;
	this->price = otherCar.price;
	this->condition = otherCar.condition;
}

int Car::getID() const { return carID; }
string Car::getBrand() const { return brand; }
string Car::getRegistrationNumber() const { return registrationNumber; }
double Car::getMileAge() const { return mileAge; }
double Car::getPrice() const { return price; }
string Car::getCondition() const { return condition; }

void Car::setBrand(string brand) { this->brand = brand; }
void Car::setRegistrationNumber(string registrationNumber) { this->registrationNumber = registrationNumber; }
void Car::setMileAge(double mileAge) { this->mileAge = mileAge; }
void Car::setPrice(double price) { this->price = price; }
void Car::setCondition(string condition) { this->condition = condition; }

void Car::displayCarInfo() const
{
	cout << "\t\t\t" << '|' << setw(5) << left << setfill(' ') << getID() << '|' << setw(20) << left << setfill(' ') << getBrand() << '|' << setw(25) << left << getRegistrationNumber() << '|' << setw(10) << left << getMileAge() << '|' << setw(10) << left << getPrice() << '|' << setw(20) << left << getCondition() << '|' << endl;
	cout << "\t\t\t" << '|' << setw(5) << right << setfill('=') << "" << setw(20) << left << setfill('=') << "" << setw(25) << left << setfill('=') << "" << setw(10) << left << "" << setw(10) << left << "" << setw(25) << left << "" << '|' << endl;
}

void Car::spcDisplayCarInfo() const
{
	cout << "\t\t\t" << "| =====================================================" << endl;
	cout << "\t\t\t" << "| Марка: " << brand << endl;
	cout << "\t\t\t" << "| Регистрационный номер: " << registrationNumber << endl;
}

ostream& operator<<(ostream& buf, const shared_ptr<Car>& carPtr)
{
	buf << carPtr->getID() << ' ' << carPtr->getBrand() << ',' << carPtr->getRegistrationNumber() << ',' << carPtr->getMileAge() << ' ' << carPtr->getPrice() << ' ' << carPtr->getCondition() << ',' << endl;
	return buf;
}
istream& operator>>(istream& buf, shared_ptr<Car>& carPtr)
{
	buf >> carPtr->carID;
	getline(buf >> ws, carPtr->brand, ',');
	getline(buf >> ws, carPtr->registrationNumber, ','); 
	buf >> carPtr->mileAge >> carPtr->price;
	getline(buf >> ws, carPtr->condition, ',');
	return buf;
}

