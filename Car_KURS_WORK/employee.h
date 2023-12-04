#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include <iomanip>

#include "reg_log_area.h"
#include "car.h"
#include "tables.h"
#include "customer.h"

using namespace std;


class Employee
{
private:
	shared_ptr<AdminAccount> account;
public:
	Employee();
	Employee(shared_ptr<AdminAccount> account);

	void addCarInfo(vector <shared_ptr<Car>>& carBASE);
	void printAllCarInfo(const vector <shared_ptr<Car>>& carBASE, Table<Car>& table);
	void deleteCarInfo(vector <shared_ptr<Car>>& carBASE);
	void editCarInfo(vector <shared_ptr<Car>>& carBASE);

	void sortCarInfo(vector <shared_ptr<Car>>& carBASE);
	void findCarInfo(const vector <shared_ptr<Car>>& carBASE);
	void filtrateCarInfo(const vector <shared_ptr<Car>>& carBASE);


	void printAllSaleContracts(const vector <shared_ptr<saleContract>>& contractBASE);
	void findSaleContracts(const vector <shared_ptr<saleContract>>& contractBASE);
	void sortSaleContracts(vector <shared_ptr<saleContract>>& contractBASE);

	void printAllUserAccounts(const vector <shared_ptr<UserAccount>>& accountBASE);
	void blockUserAccount(vector <shared_ptr<UserAccount>>& accountBASE);
	void unblockUserAccount(vector <shared_ptr<UserAccount>>& accountBASE);
};