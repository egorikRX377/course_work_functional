#include "customer.h"
#include "paymentMethods.h"


using namespace std;


extern vector<shared_ptr<saleContract>> contractBASE;


Customer::Customer() : account(nullptr) {}
Customer::Customer(shared_ptr<UserAccount> account)
{
	if (!account)
	{
		throw std::runtime_error("������ ����� � �������!");
	}
	this->account = account;
}



string Customer::getName() { return name; }
string Customer::getAddress() { return address; }


void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }

void Customer::displayCustomerInfo()
{
	cout << "��� ���������: " << name << endl;
	cout << "����� ���������: " << address << endl;
}

void Customer::inputDataAboutYourSelf()
{
	cout << "������� ���� ���: ";
	cin >> name;
	cout << "������� ��� �����: ";
	cin >> address;
}



void Customer::printAllCarInfo(const vector <shared_ptr<Car>>& carBASE, Table<Car>& table)
{
	table.displayTable(carBASE);
	return;
}
void Customer::sortCarInfo(vector <shared_ptr<Car>>& carBASE)
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
			system("pause");
			break;
		}
		case 2:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getMileAge() < b->getMileAge(); });
			system("pause");
			break;
		}
		case 3:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getPrice() > b->getPrice(); });
			system("pause");
			break;
		}
		case 4:
		{
			system("pause");
			return;
		}
		default:
			cout << "�� ������ �����!" << endl;
		}
	}
}
void Customer::findCarInfo(const vector <shared_ptr<Car>>& carBASE)
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
void Customer::filtrateCarInfo(const vector <shared_ptr<Car>>& carBASE)
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


void Customer::orderCar(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t______________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________ �������� ���������� ________________________\n\n";

	int id;
	cout << "\t\t\t| ������� id ������ � ����: ";
	cin >> id;


	bool isExist = false;
	bool isAgree = false;

	for (int i = 0; i < carBASE.size(); i++)
	{
		if (carBASE.at(i)->getID() == id)
		{
			isExist = true;

			inputDataAboutYourSelf();

			shared_ptr<PaymentMethod> method;

			cout << "�������� ������ ������: " << endl;
			cout << "1. ���������" << endl;
			cout << "2. ������" << endl;
			int paymentChoice;
			cin >> paymentChoice;
			switch (paymentChoice)
			{
			case 1:
			{
				method = make_shared<InstallmentPayment>(carBASE.at(i)->getPrice());
				break;
			}
			case 2:
			{
				method = make_shared<Leasing>(carBASE.at(i)->getPrice());
				break;
			}
			default:
				cout << "�� ������ �����!" << endl;
			}

			shared_ptr<saleContract> contract = make_shared<saleContract>(*this, *carBASE.at(i), method);
			contract->displayContractInfo();
			cout << "�� �������� � ��������� �����-�������?" << endl;
			cout << "1. ��" << endl;
			cout << "2. ��� (�������� �����)" << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				isAgree = true;
				contractBASE.push_back(contract);
				cout << "����� ������!" << endl;
				break;
			}
			case 2:
			{
				break;
			}
			default:
				cout << "�� ������ ����!" << endl;
			}
			break;
		}
	}
	if (!isExist)
	{
		cout << "\t\t\t| ������ � ����� id �� �������" << endl;
		system("pause");
	}
	else if (!isAgree)
	{
		cout << "����� ������!" << endl;
		system("pause");
	}
}