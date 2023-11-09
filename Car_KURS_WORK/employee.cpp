#include "employee.h"

#include "tables.h"

using namespace std;



Employee::Employee() : account(nullptr) {}
Employee::Employee(shared_ptr<AdminAccount> account)
{
	if (!account)
	{
		throw std::runtime_error("Ошибка входа в аккаунт!");
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
	cout << "Введите марку автомобиля: ";
	cin >> brand;
	cout << "Введите регистрационный номер: ";
	cin >> regNumber;
	cout << "Введите пробег: ";
	cin >> mileAge;
	cout << "Введите цену автомобиля: ";
	cin >> price;
	cout << "Введите состояние автомобиля: ";
	cin >> condition;
	shared_ptr<Car> newCar = make_shared<Car>(brand, regNumber, mileAge, price, condition);
	carBASE.push_back(newCar);
	cout << "Машина успешно добавлена!" << endl;
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
	cout << "\t\t\t________________________  УДАЛИТЬ ИНФОРМАЦИЮ О МАШИНЕ ________________________\n\n";

	int id;
	cout << "\t\t\t| Введите id машины, который надо удалить: ";
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
		cout << "\t\t\t| Информация о машине успешно удалена!" << endl;
	}
	else
	{
		cout << "\t\t\t| Машина с таким id не найдена" << endl;
	}
	system("pause");
}
void Employee::editCarInfo(vector <shared_ptr<Car>>& carBASE)
{
	system("cls");

	cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t________________________  ОТРЕДАКТИРОВАТЬ ИНФОРМАЦИЮ О МАШИНЕ ПО ПАРАМЕТРУ_______________________\n\n";

	int id;
	cout << "\t\t\t| Введите id машины, который надо отредактировать: ";
	cin >> id;

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
					cout << "Введите марку автомобиля: ";
					cin >> brand;
					carBASE.at(i)->setBrand(brand);

					break;
				}
				case 2:
				{
					string regNumber;
					cout << "Введите регистрационный номер: ";
					cin >> regNumber;
					carBASE.at(i)->setRegistrationNumber(regNumber);
					break;
				}
				case 3:
				{
					double mileAge;
					cout << "Введите пробег: ";
					cin >> mileAge;
					carBASE.at(i)->setMileAge(mileAge);
					break;
				}
				case 4:
				{
					double price;
					cout << "Введите цену автомобиля: ";
					cin >> price;
					carBASE.at(i)->setPrice(price);
					break;
				}
				case 5:
				{
					string condition;
					cout << "Введите состояние автомобиля: ";
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
					cout << "\t\t\t| Неверный ввод!" << endl;
				}
				}
			}
		}
	}

	if (!isExist)
	{
		cout << "\t\t\t| Машина с таким id не найдена" << endl;
		system("pause");
	}
}

void Employee::sortCarInfo(vector <shared_ptr<Car>>& carBASE)
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
			cout << "Не верный выбор!" << endl;
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
		cout << "\t\t\t________________________  НАЙТИ ИНФОРМАЦИЮ О ДОГОВОРАХ ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "1. Найти договора по имени заказчика" << endl;
		cout << "2. Найти договора по адресу заказчика" << endl;
		cout << "3. Найти договора по способу оплаты" << endl;
		cout << "4. Выйти из меню поиска" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "Введите имя заказчика: ";
			cin >> name;
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&name](const shared_ptr<saleContract>& a) { return a->getCustomer().getName() == name; });
			if (iter == contractBASE.end()) { cout << "Договора, с таким именем заказчика не найдено!" << endl; system("pause"); break; }
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
			cout << "Введите адрес заказчика: ";
			cin >> address;
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&address](const shared_ptr<saleContract>& a) { return a->getCustomer().getAddress() == address; });
			if (iter == contractBASE.end()) { cout << "Договора, с таким адресом заказчика не было найдено!" << endl; system("pause"); break; }
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
			cout << "Введите название способом оплаты: ";
			cin >> methodName;
			auto iter = find_if(contractBASE.begin(), contractBASE.end(), [&methodName](const shared_ptr<saleContract>& a) { return a->getMethod()->getMethodName() == methodName; });
			if (iter == contractBASE.end()) { cout << "Договора, с таким способом оплаты не было найдено!" << endl; system("pause");  break; }
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
			cout << "Не верный выбор!" << endl;
		}
	}
}
void Employee::sortSaleContracts(vector <shared_ptr<saleContract>>& contractBASE)
{
	system("cls");
	while (1)
	{
		cout << "\t\t\t_________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t________________________  ОТСОРТИРОВАТЬ ДОГОВОРА ПО ПАРАМЕТРУ_________________________\n\n";
		cout << "1. Отсортировать договора ежемесячному платежу (в порядке возрастания)" << endl;
		cout << "2. Отсортировать договора по конечной стоимости (в порядке убывания)" << endl;
		cout << "3. Отсортировать машины по начальному/конечному взносу (в порядке возрастания)" << endl;
		cout << "4. Выйти из меню сортировки" << endl;
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
			cout << "Не верный выбор!" << endl;
		}
		system("pause");
	}
}