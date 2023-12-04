#include "employee.h"

#include "tables.h"

using namespace std;


Employee::Employee() : account(nullptr) {}
Employee::Employee(shared_ptr<AdminAccount> account)
{
	if (!account)
	{
		throw runtime_error("Неверно введён логин или пароль!");
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

	system("cls");

	cout << "\t\t\t_______________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________  ДОБАВИТЬ ИНФОРМАЦИЮ О МАШИНЕ ________________________\n\n";

	cout << "\t\t\t| Введите марку автомобиля: ";
	getline(cin >> ws, brand);

	cout << "\t\t\t| Введите регистрационный номер: ";
	getline(cin >> ws, regNumber);

	cout << "\t\t\t| Введите пробег: ";
	mileAge = correctNumberInput<double>();

	cout << "\t\t\t| Введите цену автомобиля: ";
	price = correctNumberInput<double>();

	cout << "\t\t\t| Введите состояние автомобиля: ";
	getline(cin >> ws, condition);

	shared_ptr<Car> newCar = make_shared<Car>(brand, regNumber, mileAge, price, condition);
	carBASE.push_back(newCar);
	cout << "\t\t\t| Машина успешно добавлена!" << endl;

	cout << "\t\t\t| "; system("pause");
	return;
}

void Employee::printAllCarInfo(const vector <shared_ptr<Car>>& carBASE, Table<Car>& table)
{
	system("cls");

	if (carBASE.size() == 0)
	{
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t| Информация об автомобилях отсутствует" << endl;
		cout << "\t\t\t| "; system("pause");
		return;
	}
	table.displayTable(carBASE);
	cout << "\t\t\t| "; system("pause");
	return;
}

void Employee::deleteCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t______________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________  УДАЛИТЬ ИНФОРМАЦИЮ О МАШИНЕ ________________________\n\n";

	int id;
	cout << "\t\t\t| Введите id машины, который надо удалить: ";
	
	id = correctNumberInput<int>();

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
		cout << "\t\t\t| Информация о машине успешно удалена!" << endl;
	}
	else
	{
		cout << "\t\t\t| Машина с таким id не найдена" << endl;
	}
	cout << "\t\t\t| "; system("pause");
}
void Employee::editCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________  ОТРЕДАКТИРОВАТЬ ИНФОРМАЦИЮ О МАШИНЕ ПО ПАРАМЕТРУ_______________________\n\n";

	int id;
	cout << "\t\t\t| Введите id машины, который надо отредактировать: ";
	
	id = correctNumberInput<int>();

	bool isExist = false;

	for (int i = 0; i < carBASE.size(); i++)
	{
		if (carBASE.at(i)->getID() == id)
		{
			isExist = true;
			while (1)
			{
				cout << "\t\t\t| 1. Редактировать марку машины" << endl;
				cout << "\t\t\t| 2. Редактировать регистрационный номер машины" << endl;
				cout << "\t\t\t| 3. Редактировать пробег товара" << endl;
				cout << "\t\t\t| 4. Редактировать цену на машину" << endl;
				cout << "\t\t\t| 5. Редактировать состояние машины" << endl;
				cout << "\t\t\t| 6. Выйти из меню редактирования" << endl;
				int choicee;

				cin >> choicee;

				switch (choicee)
				{
				case 1:
				{
					string brand;
					cout << "\t\t\t| Введите марку автомобиля: ";
					getline(cin >> ws, brand);
					carBASE.at(i)->setBrand(brand);

					break;
				}
				case 2:
				{
					string regNumber;
					cout << "\t\t\t| Введите регистрационный номер: ";
					getline(cin >> ws, regNumber);
					carBASE.at(i)->setRegistrationNumber(regNumber);
					break;
				}
				case 3:
				{
					double mileAge;
					cout << "\t\t\t| Введите пробег: ";
					mileAge = correctNumberInput<double>();
					carBASE.at(i)->setMileAge(mileAge);
					break;
				}
				case 4:
				{
					double price;
					cout << "\t\t\t| Введите цену автомобиля: ";
					price = correctNumberInput<double>();
					carBASE.at(i)->setPrice(price);
					break;
				}
				case 5:
				{
					string condition;
					cout << "\t\t\t| Введите состояние автомобиля: ";
					getline(cin >> ws, condition);
					carBASE.at(i)->setCondition(condition);
					break;
				}
				case 6:
				{
					return;
				}
				default:
				{
					cout << "\t\t\t| Неверный ввод!" << endl;
				}
				}
			}
		}
	}

	if (!isExist)
	{
		cout << "\t\t\t| Машина с таким id не найдена" << endl;
		cout << "\t\t\t| "; system("pause");
	}
}

void Employee::sortCarInfo(vector <shared_ptr<Car>>& carBASE)
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
			cout << "\t\t\t| Не верный выбор!" << endl;
		}
		cout << "\t\t\t| "; system("pause");
	}
}
void Employee::findCarInfo(const vector <shared_ptr<Car>>& carBASE)
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
			if (iter == carBASE.end()) { cout << "\t\t\t| Автомобиля, с таким регистрационным номером не было найдено!" << endl; cout << "\t\t\t| "; system("pause"); break; }
			displayCarTableHeader();
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
void Employee::filtrateCarInfo(const vector <shared_ptr<Car>>& carBASE)
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




void Employee::printAllSaleContracts(const vector <shared_ptr<saleContract>>& contractBASE)
{
	system("cls");
	if (contractBASE.size() == 0)
	{
		cout << "\t\t\t| Информация о договорах купли-продажи отсутствует!" << endl;
		cout << "\t\t\t| "; system("pause");
		return;
	}
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
		cout << "\t\t\t___________________________  НАЙТИ ИНФОРМАЦИЮ О ДОГОВОРАХ ПО ПАРАМЕТРУ___________________________\n\n";
		cout << "\t\t\t| 1. Найти договора по имени заказчика" << endl;
		cout << "\t\t\t| 2. Найти договора по адресу заказчика" << endl;
		cout << "\t\t\t| 3. Найти договора по способу оплаты" << endl;
		cout << "\t\t\t| 4. Выйти из меню поиска" << endl;
		int choice;

		choice = correctNumberInput<int>();

		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "\t\t\t| Введите имя заказчика: ";
			getline(cin >> ws, name);
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&name](const shared_ptr<saleContract>& a) { return a->getCustomer().getName() == name; });
			if (iter == contractBASE.end()) { cout << "\t\t\t| Договора, с таким именем заказчика не найдено!" << endl; cout << "\t\t\t| ";  system("pause"); break; }
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
			cout << "\t\t\t| Введите адрес заказчика: ";
			getline(cin >> ws, address);
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&address](const shared_ptr<saleContract>& a) { return a->getCustomer().getAddress() == address; });
			if (iter == contractBASE.end()) { cout << "\t\t\t| Договора, с таким адресом заказчика не было найдено!" << endl; cout << "\t\t\t| ";  system("pause"); break; }
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
			cout << "\t\t\t| Введите название способом оплаты: ";
			getline(cin >> ws, methodName);
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&methodName](const shared_ptr<saleContract>& a) { return a->getMethod()->getMethodName() == methodName; });
			if (iter == contractBASE.end()) { cout << "\t\t\t| Договора, с таким способом оплаты не было найдено!" << endl; cout << "\t\t\t| "; system("pause");  break; }
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
			cout << "\t\t\t| Не верный выбор!" << endl;
		}
	}
}
void Employee::sortSaleContracts(vector <shared_ptr<saleContract>>& contractBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t_____________________________  ОТСОРТИРОВАТЬ ДОГОВОРА ПО ПАРАМЕТРУ_______________________________\n\n";
		cout << "\t\t\t| 1. Отсортировать договора ежемесячному платежу (в порядке возрастания)" << endl;
		cout << "\t\t\t| 2. Отсортировать договора по конечной стоимости (в порядке убывания)" << endl;
		cout << "\t\t\t| 3. Отсортировать машины по начальному/конечному взносу (в порядке возрастания)" << endl;
		cout << "\t\t\t| 4. Выйти из меню сортировки" << endl;
		int choice;
		choice = correctNumberInput<int>();
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
			cout << "\t\t\t| Не верный выбор!" << endl;
		}
		cout << "\t\t\t| "; system("pause");
	}
}

void Employee::printAllUserAccounts(const vector <shared_ptr<UserAccount>>& accountBASE)
{
	system("cls");

	cout << "\t\t\t__________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t_______________________________________  ВЫВОД ВСЕХ ЗАРЕГИСТРИРОВАННЫХ ПОЛЬЗОВАТЬСКИХ АККАУНТОВ __________________________________\n\n";
	if (accountBASE.size() == 0)
	{
		cout << "\t\t\t| Пользовательские аккаунты отсутствуют" << endl;
		cout << "\t\t\t| "; system("pause");
		return;
	}
	cout << "\t\t\t" << setw(20) << right << setfill('=') << "" << setw(16) << setfill('=') << "" << endl;
	cout << "\t\t\t" << '|' << setw(20) << left << setfill(' ') << "Логин" << '|' << setw(13) << left << setfill(' ') << "Доступ" << '|' << endl;
	cout << "\t\t\t" << setw(20) << right << setfill('=') << "" << setw(16) << setfill('=') << "" << endl;

	for (const auto& item : accountBASE)
	{
		cout << "\t\t\t" << '|' << setw(20) << left << setfill(' ') << item->getLogin() << '|' << setw(13) << left << setfill(' ');
		if (item->getAccess() == 1)
		{
			cout << "Активен" << '|' << endl;
		}
		else
		{
			cout << "Заблокирован" << '|' << endl;
		}
		cout << "\t\t\t" << setw(20) << right << setfill('=') << "" << setw(16) << setfill('=') << "" << endl;
	}

	cout << "\t\t\t| "; system("pause");
	return;
}
void Employee::blockUserAccount(vector <shared_ptr<UserAccount>>& accountBASE)
{
	system("cls");

	cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t__________________________________  ЗАБЛОКИРОВАТЬ ПОЛЬЗОВАТЕЛЯ __________________________________\n\n";
	if (accountBASE.size() == 0)
	{
		cout << "\t\t\t| Пользовательские аккаунты отсутствует!" << endl;
		cout << "\t\t\t| "; system("pause");
		return;
	}

	string login;
	cout << "\t\t\t| Введите логин пользователя, которого надо заблокировать: ";
	getline(cin >> ws, login);

	bool isExist = false;
	for (auto& item : accountBASE)
	{
		if (item->getLogin() == login)
		{
			isExist = true;
			if (item->getAccess() == false)
			{
				cout << "\t\t\t| Аккаунт уже заблокирован!" << endl;
				cout << "\t\t\t| "; system("pause");
				return;
			}
			item->setAccess(false);
			cout << "\t\t\t| Аккаунт успешно заблокирован!" << endl;
			cout << "\t\t\t| "; system("pause");
			return;
		}
	}

	if (!isExist)
	{
		cout << "\t\t\t| Данного пользовательского аккаунта не существует!" << endl;
		cout << "\t\t\t| "; system("pause");
	}
	return;
}
void Employee::unblockUserAccount(vector <shared_ptr<UserAccount>>& accountBASE)
{
	system("cls");

	cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t__________________________________  РАЗБЛОКИРОВАТЬ АККАУНТ __________________________________\n\n";
	if (accountBASE.size() == 0)
	{
		cout << "\t\t\t| Пользовательские аккаунты отсутствует!" << endl;
		cout << "\t\t\t| "; system("pause");
		return;
	}

	string login;
	cout << "\t\t\t| Введите логин пользователя, которого надо разблокировать: ";
	getline(cin >> ws, login);

	bool isExist = false;
	for (auto& item : accountBASE)
	{
		if (item->getLogin() == login)
		{
			isExist = true;
			if (item->getAccess() == true)
			{
				cout << "\t\t\t| Аккаунт уже активен!" << endl;
				cout << "\t\t\t| "; system("pause");
				return;
			}
			item->setAccess(true);
			cout << "\t\t\t| Аккаунт успешно разблокирован!" << endl;
			cout << "\t\t\t| "; system("pause");
			return;
		}
	}

	if (!isExist)
	{
		cout << "\t\t\t| Данного пользовательского аккаунта не существует!" << endl;
		cout << "\t\t\t| "; system("pause");
	}
	return;
}

