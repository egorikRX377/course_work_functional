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
int generateUniqueID(vector<shared_ptr<T>> anyBASE)
{
	time(0);
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
