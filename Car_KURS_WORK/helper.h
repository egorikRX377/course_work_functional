#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <time.h>	
#include <stdlib.h>


using namespace std;


template<class T>
int generateUniqueID(const vector<shared_ptr<T>>& anyBASE)
{
	srand(time(NULL));
	while (1)
	{
		int id = rand() % 10000;
		bool isUnique = true;
		for (const auto& item : anyBASE)
		{
			if (item->getID() == id)
			{
				isUnique = false;
				break;
			}
		}
		if (isUnique)
		{
			return id;
		}
	}
}

template<class T>
T correctNumberInput()
{
	T number;
	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоррекный ввод!" << endl;
			continue;
		}
		cin.ignore(32767, '\n');
		if (cin.gcount() > 1)
		{
			cout << "Некорректный ввод!" << endl;
			continue;
		}
		break;
	}
	return number;
}
