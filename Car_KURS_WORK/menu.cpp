#include "menu.h"


using namespace std;

void userFunctionalMenu::displayMenu(Customer& customer) const
{
	while (1)
	{
		cout << "=================ФУНКЦИОНАЛЬНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ================" << endl;
		cout << "1. Посмотреть информацию об автомобилях" << endl;
		cout << "2. Сортировать информацию об автомобилях (по параметру)" << endl;
		cout << "3. Искать информацию об автомобилях (по параметру)" << endl;
		cout << "4. Фильтровать информацию об автомобилях (по параметрам)" << endl;
		cout << "5. Заказать автомобиль" << endl;
		cout << "6. Выйти из функционального меню пользователя" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			customer.printAllCarInfo(carBASE);
			break;
		}
		case 2:
		{
			customer.sortCarInfo(carBASE);
			break;
		}
		case 3:
		{
			customer.findCarInfo(carBASE);
			break;
		}
		case 4:
		{
			customer.filtrateCarInfo(carBASE);
			break;
		}
		case 5:
		{
			customer.orderCar(carBASE);
			break;
		}
		case 6:
		{
			return;
		}
		default:
			cout << "Не верный ввод!" << endl;
		}
	}
}
void adminFunctionalMenu::displayMenu(Employee& employee) const
{
	while (1)
	{
		cout << "=================ФУНКЦИОНАЛЬНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ================" << endl;
		cout << "1. Посмотреть информацию об автомобилях" << endl;
		cout << "2. Добавить информацию об автомобилях" << endl;
		cout << "3. Удалить информацию об автомобилях" << endl;
		cout << "4. Редактировать информацию об автомобилях" << endl;
		cout << "5. Сортировать информацию об автомобилях (по параметру)" << endl;
		cout << "6. Искать информацию об автомобилях (по параметру)" << endl;
		cout << "7. Фильтровать информацию об автомобилях (по параметрам)" << endl << endl;
		cout << "8. Посмотреть информацию о договорах купли-продажи" << endl;
		cout << "9. Найти договора по параметрам" << endl;
		cout << "10. Выйти из функционального меню пользователя" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			employee.printAllCarInfo(carBASE);
			break;
		}
		case 2:
		{
			employee.addCarInfo(carBASE);
			break;
		}
		case 3:
		{
			employee.deleteCarInfo(carBASE);
			break;
		}
		case 4:
		{
			employee.editCarInfo(carBASE);
			break;
		}
		case 5:
		{
			employee.sortCarInfo(carBASE);
			break;
		}
		case 6:
		{
			employee.findCarInfo(carBASE);
			break;
		}
		case 7:
		{
			employee.filtrateCarInfo(carBASE);
			break;
		}
		case 8:
		{
			employee.printAllSaleContracts(contractBASE);
			break;
		}
		case 9:
		{
			employee.findSaleContracts(contractBASE);
			break;
		}
		case 10:
		{
			return;
		}
		default:
			cout << "Не верный ввод!" << endl;
		}
	}
}



void adminMainMenu::displayMenu(vector<shared_ptr<AdminAccount>>& adminAccounts) const
{
	while (1)
	{
		cout << "=================ГЛАВНОЕ МЕНЮ АДМИНИСТРАТОРА================" << endl;
		cout << "1. Вход в аккаунт администратора" << endl;
		cout << "2. Выйти из главного меню" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			AuthenticateSystem<AdminAccount> adminAuthSystem;
			shared_ptr<AdminAccount> adminAccount;
			Employee employee;
			try
			{
				adminAccount = adminAuthSystem.authenticate(adminAccounts);
				employee = Employee(adminAccount);
				adminFunctionalMenu functionalMenu;
				functionalMenu.displayMenu(employee);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			break;
		}
		case 2:
		{
			return;
		}
		default:
			cout << "Не верный ввод!" << endl;
		}
	}
}
void userMainMenu::displayMenu(vector<shared_ptr<UserAccount>>& userAccounts) const
{
	while (1)
	{
		cout << "=================ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ================" << endl;
		cout << "1. Регистрация аккаунта пользователя" << endl;
		cout << "2. Вход в аккаунт пользователя" << endl;
		cout << "3. Выйти из главного меню" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			RegistrateSystem<UserAccount> userRegSystem;
			userAccounts.push_back(userRegSystem.registrate());
			break;
		}
		case 2:
		{
			AuthenticateSystem<UserAccount> userAuthSystem;
			shared_ptr<UserAccount> userAccount;
			Customer customer;
			try
			{
				userAccount = userAuthSystem.authenticate(userAccounts);
				customer = Customer(userAccount);
				userFunctionalMenu functionalMenu;
				functionalMenu.displayMenu(customer);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			break;
		}
		case 3:
		{
			return;
		}
		default:
			cout << "Не верный ввод!" << endl;
		}
	}
}

void statusMenu::displayMenu(vector<shared_ptr<UserAccount>>& userAccounts, vector<shared_ptr<AdminAccount>>& adminAccounts)
{
	while (1)
	{
		cout << "=================МЕНЮ ВЫБОРА СТАТУСА================" << endl;
		cout << "1. Пользователь" << endl;
		cout << "2. Администратор" << endl;
		cout << "3. Выйти из меню выбора статуса" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			userMainMenu userMenu;
			userMenu.displayMenu(userAccounts);
			break;
		}
		case 2:
		{
			adminMainMenu adminMenu;
			adminMenu.displayMenu(adminAccounts);
			break;
		}
		case 3:
		{
			return;
		}
		default:
			cout << "Не верный ввод!" << endl;
		}
	}
}
