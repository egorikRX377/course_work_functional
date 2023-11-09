#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

#include "car.h"

using namespace std;


template <class T>
class Table
{
public:
	virtual void displayTable(const vector<shared_ptr<T>>& anyBASE) const = 0;
};


class CarTable : public Table<Car>
{
public:
	void displayTable(const vector<shared_ptr<Car>>& carBASE) const override;
};