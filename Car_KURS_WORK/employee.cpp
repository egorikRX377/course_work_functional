#include "employee.h"

#include "tables.h"

using namespace std;



Employee::Employee() : account(nullptr) {}
Employee::Employee(shared_ptr<AdminAccount> account)
{
	if (!account)
	{
		throw std::runtime_error("������ ����� � �������!");
	}
	this->account = account;
}

void Employee::addCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	string brand;
	string regNumber;
	double mileAge;
	double price;
	string condition;
	cout << "������� ����� ����������: ";
	cin >> brand;
	cout << "������� ��������������� �����: ";
	cin >> regNumber;
	cout << "������� ������: ";
	cin >> mileAge;
	cout << "������� ���� ����������: ";
	cin >> price;
	cout << "������� ��������� ����������: ";
	cin >> condition;
	shared_ptr<Car> newCar = make_shared<Car>(brand, regNumber, mileAge, price, condition);
	carBASE.push_back(newCar);
	cout << "������ ������� ���������!" << endl;
	system("pause");
	return;
}
void Employee::printAllCarInfo(const vector <shared_ptr<Car>>& carBASE, Table<Car>& table)
{
	table.displayTable(carBASE);
	return;
}

void Employee::deleteCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t______________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________  ������� ���������� � ������ ________________________\n\n";

	int id;
	cout << "\t\t\t| ������� id ������, ������� ���� �������: ";
	cin >> id;

	bool isExist = false;

	for (int i = 0; i < carBASE.size(); i++)
	{
		if (carBASE.at(i)->getID() == id)
		{
			carBASE.erase(carBASE.begin() + i);
			isExist = true;
			break;
		}
	}

	if (isExist)
	{
		cout << "\t\t\t| ���������� � ������ ������� �������!" << endl;
	}
	else
	{
		cout << "\t\t\t| ������ � ����� id �� �������" << endl;
	}
	system("pause");
}
void Employee::editCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________  ��������������� ���������� � ������ �� ���������_______________________\n\n";

	int id;
	cout << "\t\t\t| ������� id ������, ������� ���� ���������������: ";
	cin >> id;

	bool isExist = false;

	for (int i = 0; i < carBASE.size(); i++)
	{
		if (carBASE.at(i)->getID() == id)
		{
			isExist = true;
			while (1)
			{
				cout << "\t\t\t| 1. ������������� ����� ������" << endl;
				cout << "\t\t\t| 2. ������������� ��������������� ����� ������" << endl;
				cout << "\t\t\t| 3. ������������� ������ ������" << endl;
				cout << "\t\t\t| 4. ������������� ���� �� ������" << endl;
				cout << "\t\t\t| 5. ������������� ��������� ������" << endl;
				cout << "\t\t\t| 6. ����� �� ���� ��������������" << endl;
				int choicee;

				cin >> choicee;

				switch (choicee)
				{
				case 1:
				{
					string brand;
					cout << "������� ����� ����������: ";
					cin >> brand;
					carBASE.at(i)->setBrand(brand);

					break;
				}
				case 2:
				{
					string regNumber;
					cout << "������� ��������������� �����: ";
					cin >> regNumber;
					carBASE.at(i)->setRegistrationNumber(regNumber);
					break;
				}
				case 3:
				{
					double mileAge;
					cout << "������� ������: ";
					cin >> mileAge;
					carBASE.at(i)->setMileAge(mileAge);
					break;
				}
				case 4:
				{
					double price;
					cout << "������� ���� ����������: ";
					cin >> price;
					carBASE.at(i)->setPrice(price);
					break;
				}
				case 5:
				{
					string condition;
					cout << "������� ��������� ����������: ";
					cin >> condition;
					carBASE.at(i)->setCondition(condition);
					break;
				}
				case 6:
				{
					return;
				}
				default:
				{
					cout << "\t\t\t| �������� ����!" << endl;
				}
				}
			}
		}
	}

	if (!isExist)
	{
		cout << "\t\t\t| ������ � ����� id �� �������" << endl;
		system("pause");
	}
}

void Employee::sortCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  ������������� ���������� � ������� �� ���������_________________________\n\n";
		cout << "1. ������������� ������ �� ����� (� ���������� �������)" << endl;
		cout << "2. ������������� ������ �� ������� (� ������� �����������)" << endl;
		cout << "3. ������������� ������ �� ���� (� ������� ��������)" << endl;
		cout << "4. ����� �� ���� ����������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getBrand() < b->getBrand(); });
			break;
		}
		case 2:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getMileAge() < b->getMileAge(); });
			break;
		}
		case 3:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getPrice() > b->getPrice(); });
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "�� ������ �����!" << endl;
		}
		system("pause");
	}
}
void Employee::findCarInfo(const vector <shared_ptr<Car>>& carBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  ����� ���������� � ������� �� ���������_________________________\n\n";
		cout << "1. ����� ������ �� �����" << endl;
		cout << "2. ����� ������ �� ���������������� ������" << endl;
		cout << "3. ����� ������ �� ����" << endl;
		cout << "4. ����� �� ���� ������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string brand;
			cout << "������� ����� ����������: ";
			cin >> brand;
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&brand](const shared_ptr<Car>& a) { return a->getBrand() == brand; });
			if (iter == carBASE.end()) { cout << "����������, � ����� ������ �� ���� �������!" << endl; system("pause"); break; }
			(*iter)->displayCarInfo();
			system("pause");
			break;
		}
		case 2:
		{
			string regNumber;
			cout << "������� ��������������� ����� ����������: ";
			cin >> regNumber;
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&regNumber](const shared_ptr<Car>& a) { return a->getRegistrationNumber() == regNumber; });
			if (iter == carBASE.end()) { cout << "����������, � ����� ��������������� ������� �� ���� �������!" << endl; system("pause"); break; }
			(*iter)->displayCarInfo();
			system("pause");
			break;
		}
		case 3:
		{
			double price;
			cout << "������� ���� ����������: ";
			cin >> price;
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&price](const shared_ptr<Car>& a) { return a->getPrice() == price; });
			if (iter == carBASE.end()) { cout << "����������, � ����� ����� �� ���� �������!" << endl; system("pause");  break; }
			(*iter)->displayCarInfo();
			system("pause");
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "�� ������ �����!" << endl;
		}
	}
}
void Employee::filtrateCarInfo(const vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	vector<string> brands;
	double minPrice = 0;
	double maxPrice = 1000000;
	double maxMileAge = 5000000;

	bool isExist = false;
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________ ������������� ���������� � ������� �� ���������_________________________\n\n";
		cout << "1. ������ ����������� ����� �����������:" << endl;
		cout << "2. ������ ����������� �������� ���" << endl;
		cout << "3. ������ ������������ ������" << endl;
		cout << "4. ����� �� ���� ������� ���������� ����������" << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string input;
			cout << "������� ����� ����������� ����������� (����� ���������� �������� ':') : ";
			getline(cin >> ws, input);
			istringstream carBrands(input);

			string brand;
			while (getline(carBrands, brand, ':'))
			{
				bool isUnique = true;
				for (const auto& item : brands)
				{
					if (item == brand)
					{
						isUnique = false;
						break;
					}
				}
				if (!isUnique)
				{
					continue;
				}
				brands.push_back(brand);
			}
			system("pause");
			break;
		}
		case 2:
		{
			cout << "//������� �������� ���//" << endl;
			cout << "����������� ����: ";
			cin >> minPrice;
			cout << "������������ ����: ";
			cin >> maxPrice;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "������� ������������ ������ ����������� �����������: ";
			cin >> maxMileAge;
			system("pause");
			break;
		}
		case 4:
		{
			break;
		}
		default:
			cout << "�� ������ �����!" << endl;
		}
		if (choice == 4)
		{
			break;
		}
	}

	for (const auto& car : carBASE)
	{
		for (const auto& carBrand : brands)
		{
			if (car->getBrand() == carBrand)
			{
				if (car->getPrice() >= minPrice && car->getPrice() <= maxPrice)
				{
					if (car->getMileAge() <= maxMileAge)
					{
						isExist = true;
						car->displayCarInfo();
					}
				}
			}
		}
	}
	if (!isExist) { cout << "�� ���� ������� ����������� �� �������� ����������" << endl; }
	system("pause");
	return;
}




void Employee::printAllSaleContracts(const vector <shared_ptr<saleContract>>& contractBASE)
{
	system("cls");
	for (const auto& item : contractBASE)
	{
		item->displayContractInfo();
	}
	return;
}
void Employee::findSaleContracts(const vector <shared_ptr<saleContract>>& contractBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  ����� ���������� � ��������� �� ���������_________________________\n\n";
		cout << "1. ����� �������� �� ����� ���������" << endl;
		cout << "2. ����� �������� �� ������ ���������" << endl;
		cout << "3. ����� �������� �� ������� ������" << endl;
		cout << "4. ����� �� ���� ������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "������� ��� ���������: ";
			cin >> name;
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&name](const shared_ptr<saleContract>& a) { return a->getCustomer().getName() == name; });
			if (iter == contractBASE.end()) { cout << "��������, � ����� ������ ��������� �� �������!" << endl; system("pause"); break; }
			while(iter != contractBASE.end())
			{
				(*iter)->displayContractInfo();
				iter = find_if(next(iter), contractBASE.end(), [&name](const shared_ptr<saleContract>& a) { return a->getCustomer().getName() == name; });
			}
			break;
		}
		case 2:
		{
			string address;
			cout << "������� ����� ���������: ";
			cin >> address;
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&address](const shared_ptr<saleContract>& a) { return a->getCustomer().getAddress() == address; });
			if (iter == contractBASE.end()) { cout << "��������, � ����� ������� ��������� �� ���� �������!" << endl; system("pause"); break; }
			while (iter != contractBASE.end())
			{
				(*iter)->displayContractInfo();
				iter = find_if(next(iter), contractBASE.end(), [&address](const shared_ptr<saleContract>& a) { return a->getCustomer().getAddress() == address; });
			}
			break;
		}
		case 3:
		{
			string methodName;
			cout << "������� �������� �������� ������: ";
			cin >> methodName;
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&methodName](const shared_ptr<saleContract>& a) { return a->getMethod()->getMethodName() == methodName; });
			if (iter == contractBASE.end()) { cout << "��������, � ����� �������� ������ �� ���� �������!" << endl; system("pause");  break; }
			while (iter != contractBASE.end())
			{
				(*iter)->displayContractInfo();
				iter = find_if(next(iter), contractBASE.end(), [&methodName](const shared_ptr<saleContract>& a) { return a->getMethod()->getMethodName() == methodName; });
			}
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "�� ������ �����!" << endl;
		}
	}
}
void Employee::sortSaleContracts(vector <shared_ptr<saleContract>>& contractBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  ������������� �������� �� ���������_________________________\n\n";
		cout << "1. ������������� �������� ������������ ������� (� ������� �����������)" << endl;
		cout << "2. ������������� �������� �� �������� ��������� (� ������� ��������)" << endl;
		cout << "3. ������������� ������ �� ����������/��������� ������ (� ������� �����������)" << endl;
		cout << "4. ����� �� ���� ����������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			sort(contractBASE.begin(), contractBASE.end(), [](const shared_ptr<saleContract>& a, const shared_ptr<saleContract>& b) { return a->getMethod()->getMonthlyFee() < b->getMethod()->getMonthlyFee(); });
			break;
		}
		case 2:
		{
			sort(contractBASE.begin(), contractBASE.end(), [](const shared_ptr<saleContract>& a, const shared_ptr<saleContract>& b) { return a->getMethod()->getResultCost() > b->getMethod()->getResultCost(); });
			break;
		}
		case 3:
		{
			sort(contractBASE.begin(), contractBASE.end(), [](const shared_ptr<saleContract>& a, const shared_ptr<saleContract>& b) { return a->getMethod()->getFee() < b->getMethod()->getFee(); });
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "�� ������ �����!" << endl;
		}
		system("pause");
	}
}