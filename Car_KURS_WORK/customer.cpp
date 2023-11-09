#include "customer.h"
#include "paymentMethods.h"


using namespace std;


extern vector<shared_ptr<saleContract>> contractBASE;


Customer::Customer() : account(nullptr) {}
Customer::Customer(shared_ptr<UserAccount> account)
{
	if (!account)
	{
		throw std::runtime_error("Ошибка входа в аккаунт!");
	}
	this->account = account;
}



string Customer::getName() { return name; }
string Customer::getAddress() { return address; }


void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }

void Customer::displayCustomerInfo()
{
	cout << "Имя заказчика: " << name << endl;
	cout << "Адрес заказчика: " << address << endl;
}

void Customer::inputDataAboutYourSelf()
{
	cout << "Введите ваше имя: ";
	cin >> name;
	cout << "Введите ваш адрес: ";
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
		cout << "\t\t\t________________________  ОТСОРТИРОВАТЬ ИНФОРМАЦИЮ О МАШИНАХ ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "1. Отсортировать машины по марке (в алфавитном порядке)" << endl;
		cout << "2. Отсортировать машины по пробегу (в порядке возрастания)" << endl;
		cout << "3. Отсортировать машины по цене (в порядке убывания)" << endl;
		cout << "4. Выйти из меню сортировки" << endl;
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
			cout << "Не верный выбор!" << endl;
		}
	}
}
void Customer::findCarInfo(const vector <shared_ptr<Car>>& carBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  НАЙТИ ИНФОРМАЦИЮ О МАШИНАХ ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "1. Найти машину по марке" << endl;
		cout << "2. Найти машину по регистрационному номеру" << endl;
		cout << "3. Найти машину по цене" << endl;
		cout << "4. Выйти из меню поиска" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string brand;
			cout << "Введите марку автомобиля: ";
			cin >> brand;
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&brand](const shared_ptr<Car>& a) { return a->getBrand() == brand; });
			if (iter == carBASE.end()) { cout << "Автомобиля, с такой маркой не было найдено!" << endl; system("pause"); break; }
			(*iter)->displayCarInfo();
			system("pause");
			break;
		}
		case 2:
		{
			string regNumber;
			cout << "Введите регистрационный номер автомобиля: ";
			cin >> regNumber;
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&regNumber](const shared_ptr<Car>& a) { return a->getRegistrationNumber() == regNumber; });
			if (iter == carBASE.end()) { cout << "Автомобиля, с таким регистрационным номером не было найдено!" << endl; system("pause"); break; }
			(*iter)->displayCarInfo();
			system("pause");
			break;
		}
		case 3:
		{
			double price;
			cout << "Введите цену автомобиля: ";
			cin >> price;
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&price](const shared_ptr<Car>& a) { return a->getPrice() == price; });
			if (iter == carBASE.end()) { cout << "Автомобиля, с такой ценой не было найдено!" << endl; system("pause");  break; }
			(*iter)->displayCarInfo();
			system("pause");
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "Не верный выбор!" << endl;
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
		cout << "\t\t\t________________________ ОТФИЛЬТРОВАТЬ ИНФОРМАЦИЮ О МАШИНАХ ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "1. Задать необходимые марки автомобилей:" << endl;
		cout << "2. Задать необходимый диапазон цен" << endl;
		cout << "3. Задать максимальный пробег" << endl;
		cout << "4. Выйти из меню задания параметров фильтрации" << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string input;
			cout << "Введите марки необходимых автомобилей (марки разделяйте символом ':') : ";
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
			cout << "//Введите диапазон цен//" << endl;
			cout << "Минимальная цена: ";
			cin >> minPrice;
			cout << "Максимальная цена: ";
			cin >> maxPrice;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введите максимальный пробег необходимых автомобилей: ";
			cin >> maxMileAge;
			system("pause");
			break;
		}
		case 4:
		{
			break;
		}
		default:
			cout << "Не верный выбор!" << endl;
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
	if (!isExist) { cout << "Не было найдено автомобилей по заданным параметрам" << endl; }
	system("pause");
	return;
}


void Customer::orderCar(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t______________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________ ЗАКАЗАТЬ АВТОМОБИЛЬ ________________________\n\n";

	int id;
	cout << "\t\t\t| Введите id машины в базе: ";
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

			cout << "Выберете способ оплаты: " << endl;
			cout << "1. Рассрочка" << endl;
			cout << "2. Лизинг" << endl;
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
				cout << "Не верный выбор!" << endl;
			}

			shared_ptr<saleContract> contract = make_shared<saleContract>(*this, *carBASE.at(i), method);
			contract->displayContractInfo();
			cout << "Вы согласны с договором купли-продажи?" << endl;
			cout << "1. Да" << endl;
			cout << "2. Нет (Отменить заказ)" << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				isAgree = true;
				contractBASE.push_back(contract);
				cout << "Заказ принят!" << endl;
				break;
			}
			case 2:
			{
				break;
			}
			default:
				cout << "Не верный ввод!" << endl;
			}
			break;
		}
	}
	if (!isExist)
	{
		cout << "\t\t\t| Машина с таким id не найдена" << endl;
		system("pause");
	}
	else if (!isAgree)
	{
		cout << "Заказ отменён!" << endl;
		system("pause");
	}
}