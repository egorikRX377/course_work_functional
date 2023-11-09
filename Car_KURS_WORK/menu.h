#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

#include "reg_log_area.h"
#include "employee.h"
#include "customer.h"
#include "saleContract.h"
#include "tables.h"

using namespace std;


extern vector <shared_ptr<AdminAccount>> adminAccounts;
extern vector<shared_ptr<Car>> carBASE;
extern vector<shared_ptr<saleContract>> contractBASE;





template<class T>
class functionalMenu
{
	virtual void displayMenu(T& anyExecutor) const = 0;
};
class userFunctionalMenu : public functionalMenu<Customer>
{
public:
	void displayMenu(Customer& customer) const override;
};
class adminFunctionalMenu : public functionalMenu<Employee>
{
public:
	void displayMenu(Employee& employee) const override;
};



template<class T>
class Menu
{
public:
	virtual void displayMenu(vector<shared_ptr<T>>& accounts) const = 0;
};
class adminMainMenu : public Menu<AdminAccount>
{
public:
	void displayMenu(vector<shared_ptr<AdminAccount>>& adminAccounts) const override;
};
class userMainMenu : public Menu<UserAccount>
{
public:
	void displayMenu(vector<shared_ptr<UserAccount>>& userAccounts) const override;
};


class statusMenu
{
public:
	static void displayMenu(vector<shared_ptr<UserAccount>>& userAccounts, vector<shared_ptr<AdminAccount>>& adminAccounts);
};