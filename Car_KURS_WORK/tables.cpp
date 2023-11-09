#include "tables.h"
#include <iomanip>


using namespace std;

void CarTable::displayTable(const vector<shared_ptr<Car>>& carBASE) const
{
	cout  << setw(5) << right << setfill('=') << "" << setw(20) << left << setfill('=') << "" << setw(25) << left << setfill('=') << "" << setw(10) << left << "" << setw(10) << left << "" << setw(27) << left << "" << endl;
	cout << '|' << setw(5) << left << setfill(' ') << "ID" << '|' << setw(20) << left << setfill(' ') << "Марка" << '|' << setw(25) << left << "Регистрационный номер" << '|' << setw(10) << left << "Пробег" << '|' << setw(10) << left << "Цена" << '|' << setw(20) << left << "Состояние" << '|' << endl;
	cout << '|' << setw(5) << right << setfill('=') << "" << setw(20) << left << setfill('=') << "" << setw(25) << left << setfill('=') << "" << setw(10) << left << "" << setw(10) << left << "" << setw(25) << left << "" << '|' << endl;
	for (auto& item : carBASE)
	{
		cout << '|' << setw(5) << left << setfill(' ') << item->getID() << '|' << setw(20) << left << setfill(' ') << item->getBrand() << '|' << setw(25) << left << item->getRegistrationNumber() << '|' << setw(10) << left << item->getMileAge() << '|' << setw(10) << left << item->getPrice() << '|' << setw(20) << left << item->getCondition() << '|' << endl;
		cout << '|' << setw(5) << right << setfill('=') << "" << setw(20) << left << setfill('=') << "" << setw(25) << left << setfill('=') << "" << setw(10) << left << "" << setw(10) << left << "" << setw(25) << left << "" << '|' << endl;
	}
}
