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
		throw runtime_error("Неверно введён логин или пароль!");
	}
	this->account = account;
}



string Customer::getName() { return name; }
string Customer::getAddress() { return address; }


void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }

void Customer::displayCustomerInfo()
{
	cout << "\t\t\t| Имя заказчика: " << name << endl;
	cout << "\t\t\t| Адрес заказчика: " << address << endl;
}

void Customer::inputDataAboutYourSelf()
{
	cout << "\t\t\t| Введите ваше имя: ";
	getline(cin >> ws, name);
	cout << "\t\t\t| Введите ваш адрес: ";
	getline(cin >> ws, address);
}


void Customer::printAllCarInfo(const vector <shared_ptr<Car>>& carBASE, Table<Car>& table)
{
	system("cls");

	if (carBASE.size() == 0)
	{
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t" << "| Информация об автомобилях отсутствует" << endl;
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
		cout << "\t\t\t________________________  ОТСОРТИРОВАТЬ ИНФОРМАЦИЮ О МАШИНАХ ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "\t\t\t| 1. Отсортировать машины по марке (в алфавитном порядке)" << endl;
		cout << "\t\t\t| 2. Отсортировать машины по пробегу (в порядке возрастания)" << endl;
		cout << "\t\t\t| 3. Отсортировать машины по цене (в порядке убывания)" << endl;
		cout << "\t\t\t| 4. Выйти из меню сортировки" << endl;
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
			cout << "\t\t\t| Не верный выбор!" << endl;
		}
	}
}
void Customer::findCarInfo(const vector <shared_ptr<Car>>& carBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  НАЙТИ ИНФОРМАЦИЮ О МАШИНАХ ПО ПАРАМЕТРУ________________________________\n\n";
		cout << "\t\t\t| 1. Найти машину по марке" << endl;
		cout << "\t\t\t| 2. Найти машину по регистрационному номеру" << endl;
		cout << "\t\t\t| 3. Найти машину по цене" << endl;
		cout << "\t\t\t| 4. Выйти из меню поиска" << endl;
		int choice;
		choice = correctNumberInput<int>();
		switch (choice)
		{
		case 1:
		{
			string brand;
			cout << "\t\t\t| Введите марку автомобиля: ";
			getline(cin >> ws, brand);
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&brand](const shared_ptr<Car>& a) { return a->getBrand() == brand; });
			if (iter == carBASE.end()) { cout << "\t\t\t| Автомобиля, с такой маркой не было найдено!" << endl; cout << "\t\t\t| "; system("pause"); break; }
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
			cout << "\t\t\t| Введите регистрационный номер автомобиля: ";
			getline(cin >> ws, regNumber);
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&regNumber](const shared_ptr<Car>& a) { return a->getRegistrationNumber() == regNumber; });
			if (iter == carBASE.end()) { cout << "\t\t\t| Автомобиля, с таким регистрационным номером не было найдено!" << endl; cout << "\t\t\t| ";  system("pause"); break; }
			(*iter)->displayCarInfo();
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 3:
		{
			double price;
			cout << "\t\t\t| Введите цену автомобиля: ";
			price = correctNumberInput<double>();
			auto iter = find_if(carBASE.begin(), carBASE.end(), [&price](const shared_ptr<Car>& a) { return a->getPrice() == price; });
			if (iter == carBASE.end()) { cout << "\t\t\t| Автомобиля, с такой ценой не было найдено!" << endl; cout << "\t\t\t| "; system("pause");  break; }
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
			cout << "\t\t\t| Не верный выбор!" << endl;
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

	bool isFirstCondition = false;

	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________ ОТФИЛЬТРОВАТЬ ИНФОРМАЦИЮ О МАШИНАХ ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "\t\t\t| 1. Задать необходимые марки автомобилей:" << endl;
		cout << "\t\t\t| 2. Задать необходимый диапазон цен" << endl;
		cout << "\t\t\t| 3. Задать максимальный пробег" << endl;
		cout << "\t\t\t| 4. Выйти из меню задания параметров фильтрации" << endl;
		int choice;
		choice = correctNumberInput<int>();

		switch (choice)
		{
		case 1:
		{
			isFirstCondition = true;
			string input;
			cout << "\t\t\t| Введите марки необходимых автомобилей (марки разделяйте символом ':') : ";
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
			cout << "\t\t\t| //Введите диапазон цен//" << endl;
			cout << "\t\t\t| Минимальная цена: ";
			minPrice = correctNumberInput<double>();
			cout << "\t\t\t| Максимальная цена: ";
			maxPrice = correctNumberInput<double>();
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 3:
		{
			cout << "\t\t\t| Введите максимальный пробег необходимых автомобилей: ";
			maxMileAge = correctNumberInput<double>();
			cout << "\t\t\t| "; system("pause");
			break;
		}
		case 4:
		{
			break;
		}
		default:
			cout << "\t\t\t| Не верный выбор!" << endl;
		}
		if (choice == 4)
		{
			break;
		}
	}

	int i = 0;
	for (const auto& car : carBASE)
	{
		if (isFirstCondition)
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
		else
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
	if (!isExist) { cout << "\t\t\t| Не было найдено автомобилей по заданным параметрам" << endl; }
	cout << "\t\t\t| "; system("pause");
	return;
}


void Customer::orderCar(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t______________________________________________________________________________\n\n\n";
	cout << "\t\t\t___________________________ ЗАКАЗАТЬ АВТОМОБИЛЬ ______________________________\n\n";

	int id;
	cout << "\t\t\t| Введите id машины в базе: ";
	
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

			cout << "\t\t\t| Выберете способ оплаты: " << endl;
			cout << "\t\t\t| 1. Рассрочка" << endl;
			cout << "\t\t\t| 2. Лизинг" << endl;
			int paymentChoice;

			while (1)
			{
				paymentChoice = correctNumberInput<int>();
				bool isTrue = false;

				switch (paymentChoice)
				{
				case 1:
				{
					method = make_shared<InstallmentPayment>(carBASE.at(i)->getPrice());
					isTrue = true;
					break;
				}
				case 2:
				{
					method = make_shared<Leasing>(carBASE.at(i)->getPrice());
					isTrue = true;
					break;
				}
				default:
					cout << "\t\t\t| Не верный выбор!" << endl;
				}
				if (isTrue)
				{
					break;
				}
			}

			shared_ptr<saleContract> contract = make_shared<saleContract>(*this, *carBASE.at(i), method);
			contract->displayContractInfo();
			cout << "\t\t\t| Вы согласны с договором купли-продажи?" << endl;
			cout << "\t\t\t| 1. Да" << endl;
			cout << "\t\t\t| 2. Нет (Отменить заказ)" << endl;
			int choice;

			while (1)
			{
				bool isTrue = false;
				choice = correctNumberInput<int>();
				switch (choice)
				{
				case 1:
				{
					isAgree = true;
					contractBASE.push_back(contract);
					carBASE.erase(carBASE.begin() + i);
					cout << "\t\t\t| Заказ принят!" << endl;
					cout << "\t\t\t| "; system("pause");
					isTrue = true;
					break;
				}
				case 2:
				{
					isTrue = true;
					break;
				}
				default:
					cout << "\t\t\t| Не верный ввод!" << endl;
				}
				if (isTrue)
				{
					break;
				}
			}
			break;
		}
	}
	if (!isExist)
	{
		cout << "\t\t\t| Машина с таким id не найдена" << endl;
		cout << "\t\t\t| "; system("pause");
	}
	else if (!isAgree)
	{
		cout << "\t\t\t| Заказ отменён!" << endl;
		cout << "\t\t\t| "; system("pause");
	}
}