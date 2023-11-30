#include "customer.h"
#include "paymentMethods.h"
#include "tables.h"


using namespace std;


extern vector<shared_ptr<saleContract>> contractBASE;


Customer::Customer() : account(nullptr) {}
Customer::Customer(shared_ptr<UserAccount> account)
{
	if (!account)
	{
		throw runtime_error("������� ����� ����� ��� ������!");
	}
	this->account = account;
}



string Customer::getName() { return name; }
string Customer::getAddress() { return address; }


void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }

void Customer::displayCustomerInfo()
{
	cout << "\t\t\t| ��� ���������: " << name << endl;
	cout << "\t\t\t| ����� ���������: " << address << endl;
}

void Customer::inputDataAboutYourSelf()
{
	cout << "\t\t\t| ������� ���� ���: ";
	getline(cin >> ws, name);
	cout << "\t\t\t| ������� ��� �����: ";
	getline(cin >> ws, address);
}


void Customer::printAllCarInfo(const vector <shared_ptr<Car>>& carBASE, Table<Car>& table)
{
	system("cls");

	if (carBASE.size() == 0)
	{
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t" << "| ���������� �� ����������� �����������" << endl;
		cout << "\t\t\t| "; system("pause");
		return;
	}
	table.displayTable(carBASE);
	cout << "\t\t\t| "; system("pause");
	return;
}

void Customer::sortCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  ������������� ���������� � ������� �� ���������_________________________\n\n";
		cout << "\t\t\t| 1. ������������� ������ �� ����� (� ���������� �������)" << endl;
		cout << "\t\t\t| 2. ������������� ������ �� ������� (� ������� �����������)" << endl;
		cout << "\t\t\t| 3. ������������� ������ �� ���� (� ������� ��������)" << endl;
		cout << "\t\t\t| 4. ����� �� ���� ����������" << endl;
		int choice;
		
		choice = correctNumberInput<int>();

		switch (choice)
		{
		case 1:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getBrand() < b->getBrand(); });
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 2:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getMileAge() < b->getMileAge(); });
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 3:
		{
			sort(carBASE.begin(), carBASE.end(), [](const shared_ptr<Car>& a, const shared_ptr<Car>& b) { return a->getPrice() > b->getPrice(); });
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 4:
		{
			cout << "\t\t\t| "; system("pause");
			return;
		}
		default:
			cout << "\t\t\t| �� ������ �����!" << endl;
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
		cout << "\t\t\t| 1. ����� ������ �� �����" << endl;
		cout << "\t\t\t| 2. ����� ������ �� ���������������� ������" << endl;
		cout << "\t\t\t| 3. ����� ������ �� ����" << endl;
		cout << "\t\t\t| 4. ����� �� ���� ������" << endl;
		int choice;
		choice = correctNumberInput<int>();
		switch (choice)
		{
		case 1:
		{
			string brand;
			cout << "\t\t\t| ������� ����� ����������: ";
			getline(cin >> ws, brand);
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&brand](const shared_ptr<Car>& a) { return a->getBrand() == brand; });
			if (iter == carBASE.end()) { cout << "\t\t\t| ����������, � ����� ������ �� ���� �������!" << endl; cout << "\t\t\t| "; system("pause"); break; }
			displayCarTableHeader();
			while (iter != carBASE.end())
			{
				(*iter)->displayCarInfo();
				iter = find_if(next(iter), carBASE.end(), [&brand](const shared_ptr<Car>& a) { return a->getBrand() == brand; });
			}
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 2:
		{
			string regNumber;
			cout << "\t\t\t| ������� ��������������� ����� ����������: ";
			getline(cin >> ws, regNumber);
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&regNumber](const shared_ptr<Car>& a) { return a->getRegistrationNumber() == regNumber; });
			if (iter == carBASE.end()) { cout << "\t\t\t| ����������, � ����� ��������������� ������� �� ���� �������!" << endl; cout << "\t\t\t| ";  system("pause"); break; }
			(*iter)->displayCarInfo();
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 3:
		{
			double price;
			cout << "\t\t\t| ������� ���� ����������: ";
			price = correctNumberInput<double>();
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&price](const shared_ptr<Car>& a) { return a->getPrice() == price; });
			if (iter == carBASE.end()) { cout << "\t\t\t| ����������, � ����� ����� �� ���� �������!" << endl; cout << "\t\t\t| "; system("pause");  break; }
			displayCarTableHeader();
			while (iter != carBASE.end())
			{
				(*iter)->displayCarInfo();
				iter = find_if(next(iter), carBASE.end(), [&price](const shared_ptr<Car>& a) { return a->getPrice() == price; });
			}
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "\t\t\t| �� ������ �����!" << endl;
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
		cout << "\t\t\t| 1. ������ ����������� ����� �����������:" << endl;
		cout << "\t\t\t| 2. ������ ����������� �������� ���" << endl;
		cout << "\t\t\t| 3. ������ ������������ ������" << endl;
		cout << "\t\t\t| 4. ����� �� ���� ������� ���������� ����������" << endl;
		int choice;

		choice = correctNumberInput<int>();

		switch (choice)
		{
		case 1:
		{
			string input;
			cout << "\t\t\t| ������� ����� ����������� ����������� (����� ���������� �������� ':') : ";
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
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 2:
		{
			cout << "\t\t\t| //������� �������� ���//" << endl;
			cout << "\t\t\t| ����������� ����: ";
			cin >> minPrice;
			cout << "\t\t\t| ������������ ����: ";
			cin >> maxPrice;
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 3:
		{
			cout << "\t\t\t| ������� ������������ ������ ����������� �����������: ";
			cin >> maxMileAge;
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 4:
		{
			break;
		}
		default:
			cout << "\t\t\t| �� ������ �����!" << endl;
		}
		if (choice == 4)
		{
			break;
		}
	}

	int i = 0;
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
						i++;
						if (i == 1)
						{
							displayCarTableHeader();
						}
						isExist = true;

						car->displayCarInfo();
					}
				}
			}
		}
	}
	if (!isExist) { cout << "\t\t\t| �� ���� ������� ����������� �� �������� ����������" << endl; }
	cout << "\t\t\t| "; system("pause");
	return;
}


void Customer::orderCar(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t______________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________ �������� ���������� ________________________\n\n";

	int id;
	cout << "\t\t\t| ������� id ������ � ����: ";
	
	id = correctNumberInput<int>();


	bool isExist = false;
	bool isAgree = false;

	for (int i = 0; i < carBASE.size(); i++)
	{
		if (carBASE.at(i)->getID() == id)
		{
			isExist = true;

			inputDataAboutYourSelf();

			shared_ptr<PaymentMethod> method;

			cout << "\t\t\t| �������� ������ ������: " << endl;
			cout << "\t\t\t| 1. ���������" << endl;
			cout << "\t\t\t| 2. ������" << endl;
			int paymentChoice;

			paymentChoice = correctNumberInput<int>();

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
				cout << "\t\t\t| �� ������ �����!" << endl;
			}

			shared_ptr<saleContract> contract = make_shared<saleContract>(*this, *carBASE.at(i), method);
			contract->displayContractInfo();
			cout << "\t\t\t| �� �������� � ��������� �����-�������?" << endl;
			cout << "\t\t\t| 1. ��" << endl;
			cout << "\t\t\t| 2. ��� (�������� �����)" << endl;
			int choice;
			choice = correctNumberInput<int>();
			switch (choice)
			{
			case 1:
			{
				isAgree = true;
				contractBASE.push_back(contract);
				carBASE.erase(carBASE.begin() + i);
				cout << "\t\t\t| ����� ������!" << endl;
				cout << "\t\t\t| "; system("pause");
				break;
			}
			case 2:
			{
				cout << "\t\t\t| "; system("pause");
				break;
			}
			default:
				cout << "\t\t\t| �� ������ ����!" << endl;
			}
			break;
		}
	}
	if (!isExist)
	{
		cout << "\t\t\t| ������ � ����� id �� �������" << endl;
		cout << "\t\t\t| "; system("pause");
	}
	else if (!isAgree)
	{
		cout << "\t\t\t| ����� ������!" << endl;
		cout << "\t\t\t| "; system("pause");
	}
}