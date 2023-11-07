#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

#include "menu.h"

using namespace std;


vector <shared_ptr<AdminAccount>> adminAccounts;
vector <shared_ptr<UserAccount>> userAccounts;
vector<shared_ptr<Car>> carBASE;
vector<shared_ptr<saleContract>> contractBASE;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	carBASE = FileHandler<Car>::readFromFile(filePATHS::carPATH);
	adminAccounts = FileHandler<AdminAccount>::readFromFile(filePATHS::ADMIN_ACCOUNTS_PATH);
	userAccounts = FileHandler<UserAccount>::readFromFile(filePATHS::USER_ACCOUNTS_PATH);
	contractBASE = FileHandler<saleContract>::readFromFile(filePATHS::contractsPATH);

	statusMenu::displayMenu(userAccounts, adminAccounts);

	FileHandler<Car>::writeToFile(filePATHS::carPATH, carBASE);
	FileHandler<AdminAccount>::writeToFile(filePATHS::ADMIN_ACCOUNTS_PATH, adminAccounts);
	FileHandler<UserAccount>::writeToFile(filePATHS::USER_ACCOUNTS_PATH, userAccounts);
	FileHandler<saleContract>::writeToFile(filePATHS::contractsPATH, contractBASE);
	return 0;
}