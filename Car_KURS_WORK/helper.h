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
int generateUniqueID(vector<shared_ptr<T>>& anyBASE)
{
	srand(static_cast<unsigned int>(time(NULL)));
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
    T number = 0;
    while (true)
    {
        try
        {
            cin >> number;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                throw runtime_error("Некорректный ввод!");
            }

            if (number < 0)
            {
                throw 1;
            }

            break;
        }
        catch (const runtime_error& e)
        {
            cerr << "\t\t\t| Ошибка: " << e.what() << endl;
        }
        catch (int)
        {
            cerr << "\t\t\t| Ошибка: Отрицательный ввод!" << endl;
        }
    }
    return number;
}
