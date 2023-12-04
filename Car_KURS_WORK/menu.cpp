#include "menu.h"


using namespace std;

void userFunctionalMenu::displayMenu(Customer& customer) const
{
	while (1)
	{
		system("cls");
		cout << "\t\t\t_____________________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t__________________________________  �������������� ���� ������������ ________________________________________\n\n";

		cout << "\t\t\t| 1. ���������� ���������� �� �����������" << endl;
		cout << "\t\t\t| 2. ����������� ���������� �� ����������� (�� ���������)" << endl;
		cout << "\t\t\t| 3. ������ ���������� �� ����������� (�� ���������)" << endl;
		cout << "\t\t\t| 4. ����������� ���������� �� ����������� (�� ����������)" << endl;
		cout << "\t\t\t| 5. �������� ����������" << endl;
		cout << "\t\t\t| 6. ����� �� ��������������� ���� ������������" << endl;
		int choice;
		choice = correctNumberInput<int>();
		switch (choice)
		{
		case 1:
		{
			CarTable table;
			customer.printAllCarInfo(carBASE, table);
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
		{
			cout << "\t\t\t| �� ������ ����!" << endl;
			cout << "\t\t\t| "; system("pause");
		}
		}
	}
}
void adminFunctionalMenu::displayMenu(Employee& employee) const
{
	while (1)
	{
		system("cls");
		cout << "\t\t\t_______________________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t____________________________________  �������������� ���� �������������� ______________________________________\n\n";
		cout << "\t\t\t| 1. ���������� ���������� �� �����������" << endl;
		cout << "\t\t\t| 2. �������� ���������� �� �����������" << endl;
		cout << "\t\t\t| 3. ������� ���������� �� �����������" << endl;
		cout << "\t\t\t| 4. ������������� ���������� �� �����������" << endl;
		cout << "\t\t\t| 5. ����������� ���������� �� ����������� (�� ���������)" << endl;
		cout << "\t\t\t| 6. ������ ���������� �� ����������� (�� ���������)" << endl;
		cout << "\t\t\t| 7. ����������� ���������� �� ����������� (�� ����������)" << endl << endl;
		cout << "\t\t\t| 8. ���������� ���������� � ��������� �����-�������" << endl;
		cout << "\t\t\t| 9. ����� �������� �� ����������" << endl;
		cout << "\t\t\t| 10. ������������� �������� �� ����������" << endl << endl;
		cout << "\t\t\t| 11. ���������� ��� ���������������� ��������" << endl;
		cout << "\t\t\t| 12. ������������� ������� ������������" << endl;
		cout << "\t\t\t| 13. �������������� ������� ������������" << endl << endl;
		cout << "\t\t\t| 14. ����� �� ��������������� ���� ������������" << endl;
		int choice;
		choice = correctNumberInput<int>();
		switch (choice)
		{
		case 1:
		{
			CarTable table;
			employee.printAllCarInfo(carBASE, table);
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
			employee.sortSaleContracts(contractBASE);
			break;
		}
		case 11:
		{
			employee.printAllUserAccounts(userAccounts);
			break;
		}
		case 12:
		{
			employee.blockUserAccount(userAccounts);
			break;
		}
		case 13:
		{
			employee.unblockUserAccount(userAccounts);
			break;
		}
		case 14:
		{
			return;
		}
		default:
		{
			cout << "\t\t\t| �� ������ ����!" << endl;
			cout << "\t\t\t| "; system("pause");
		}
		}
	}
}



void adminMainMenu::displayMenu(vector<shared_ptr<AdminAccount>>& adminAccounts) const
{
	while (1)
	{
		system("cls");
		cout << "\t\t\t_____________________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t___________________________________________  ������������� __________________________________________________\n\n";
		cout << "\t\t\t| 1. ���� � ������� ��������������" << endl;
		cout << "\t\t\t| 2. ����� �� �������� ����" << endl;
		int choice;
		choice = correctNumberInput<int>();
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
			catch (const exception& e)
			{
				cerr << "\t\t\t| ������: " << e.what() << std::endl;
				cout << "\t\t\t| "; system("pause");
			}
			break;
		}
		case 2:
		{
			return;
		}
		default:
		{
			cout << "\t\t\t| �� ������ ����!" << endl;
			cout << "\t\t\t| "; system("pause");
		}
		}
	}
}
void userMainMenu::displayMenu(vector<shared_ptr<UserAccount>>& userAccounts) const
{
	while (1)
	{
		system("cls");
		cout << "\t\t\t_____________________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t_________________________________________  ������������ _____________________________________________________\n\n";
		cout << "\t\t\t| 1. ����������� �������� ������������" << endl;
		cout << "\t\t\t| 2. ���� � ������� ������������" << endl;
		cout << "\t\t\t| 3. ����� �� �������� ����" << endl;
		int choice;
		choice = correctNumberInput<int>();
		switch (choice)
		{
		case 1:
		{
			RegistrateSystem<UserAccount> userRegSystem;
			userRegSystem.registrate(userAccounts);
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
			catch (const exception& e)
			{
				cerr << "\t\t\t| ������: " << e.what() << std::endl;
				cout << "\t\t\t| "; system("pause");
			}
			break;
		}
		case 3:
		{
			return;
		}
		default:
		{
			cout << "\t\t\t| �� ������ ����!" << endl;
			cout << "\t\t\t| "; system("pause");
		}
		}
	}
}

void statusMenu::displayMenu(vector<shared_ptr<UserAccount>>& userAccounts, vector<shared_ptr<AdminAccount>>& adminAccounts)
{
	while (1)
	{
		system("cls");
		cout << "\t\t\t_____________________________________________________________________________________________________________\n\n\n";
		cout << "\t\t\t__________________________________________  ���� ������ ������� _____________________________________________\n\n";
		cout << "\t\t\t| 1. ������������" << endl;
		cout << "\t\t\t| 2. �������������" << endl;
		cout << "\t\t\t| 3. ����� �� ���� ������ �������" << endl;
		int choice;
		choice = correctNumberInput<int>();
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
		{
			cout << "\t\t\t| �� ������ ����!" << endl;
			cout << "\t\t\t| "; system("pause");
		}
		}
	}
}
