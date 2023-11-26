#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include <conio.h>


using namespace std;


template<class T>
class FileHandler
{
public:
	static void writeToFile(const string& filePath, const vector<shared_ptr<T>>& BASE)
	{
		try
		{
			ofstream file(filePath);

			if (!file.is_open())
			{
				throw runtime_error("\t\t\t| ���������� ������� ����: " + filePath);
			}

			for (const auto& item : BASE)
			{
				file << item;
			}

			file.close();
		}
		catch (const exception& e)
		{
			cerr << "\t\t\t| ������ ��� ������ � ����: " << e.what() << endl;
		}
	}
	static vector<shared_ptr<T>> readFromFile(const string& filePath)
	{
		vector<shared_ptr<T>> accountsBASE;
		try
		{
			ifstream file(filePath);

			if (!file.good())
			{
				return accountsBASE;
			}

			if (!file.is_open())
			{
				throw runtime_error("\t\t\t| ���������� ������� ����: " + filePath);
			}

			shared_ptr<T> item = make_shared<T>();
			while (file >> item)
			{
				accountsBASE.push_back(item);
				item = make_shared<T>();
			}

			file.close();
		}
		catch (const exception& e)
		{
			cerr << "\t\t\t| ������ ��� ������ �� �����: " << e.what() << endl;
		}
		return accountsBASE;
	}
};

