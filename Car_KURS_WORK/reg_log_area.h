#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include <conio.h>


using namespace std;


namespace filePATHS
{
	const string USER_ACCOUNTS_PATH = "userAccounts.txt";
	const string ADMIN_ACCOUNTS_PATH = "adminAccounts.txt";
	const string humanPATH = "humans.txt";
}

const string passwordExample = "1892paSSword";

class Account
{
protected:
	string login;
	string password;
public:
	Account();
	Account(string login, string password);

	string getLogin();
	string getPassword();
	void setLogin(string login);
	void setPassword(string password);
};

class UserAccount : public Account
{
public:
	UserAccount();
	UserAccount(string login, string password);

	friend ostream& operator<<(ostream& buf, const shared_ptr<UserAccount>& accountPtr);
	friend istream& operator>>(istream& buf, shared_ptr<UserAccount>& accountPtr);
};
class AdminAccount : public Account
{
public:
	AdminAccount();
	AdminAccount(string login, string password);

	friend ostream& operator<<(ostream& buf, const shared_ptr<AdminAccount>& accountPtr);
	friend istream& operator>>(istream& buf, shared_ptr<AdminAccount>& accountPtr);
};



template<class T>
class IRegistrable
{
public:
	virtual void registrate(vector<shared_ptr<T>>& accountsBASE) = 0;
};
template<class T>
class RegistrateSystem : public IRegistrable<T>
{
public:
	void registrate(vector<shared_ptr<T>>& accountsBASE) override
	{
		cout << "=����������� ��������=" << std::endl;

		string login;
		cout << "������� �����: ";
		
		login = inputCorrectLogin(accountsBASE);

		string password;
		cout << "������� ������: ";
		password = inputPassword();

		accountsBASE.push_back(make_shared<T>(login, password));

		cout << "������� �� �����������!" << endl;
		system("pause");
	}

	string inputCorrectLogin(vector<shared_ptr<T>>& accountsBASE)
	{
		string login;
		while (1)
		{
			getline(cin >> ws, login);

			if (isOneWord(login))
			{
				if (isEnglish(login))
				{
					if (isLoginUnique(login, accountsBASE))
					{
						break;
					}
				}
			}
		}
		return login;
	}

	bool isOneWord(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				cout << "\t\t\t| ������ ������� ������ ��� ������ �����! (��� ��������)" << endl;
				return false;
			}
		}
		return true;
	}
	bool isEnglish(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if ((str[i] < 48 || str[i] > 57) && (str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
			{
				cout << "\t\t\t| ������ ���� ������������ ����� ���� ����������� ��������!" << endl;
				return false;	
			}
		}
		return true;
	}
	bool isLoginUnique(string login, vector<shared_ptr<T>>& accountsBASE)
	{
		for (const auto& item : accountsBASE )
		{
			if (login == item->getLogin())
			{
				cout << "\t\t\t| ������ ����� ��� ����������. ���������� ��� ���..." << endl << endl;
				return false;
			}
		}
		return true;
	}

	bool isPasswordSecure(string password)
	{
		bool uppercaseSymbol = false;
		bool lowercaseSymbol = false;
		bool digitSymbol = false;

		if (password.length() < 4) {
			cout << "\t\t\t| ������ ������ �������� ��� ������� �� 4 ��������." << endl;
			cout << endl;
			return false;
		}

		for (int i = 0; i < password.length(); i++) {
			if (isupper(password[i])) {
				uppercaseSymbol = true;
			}
			if (islower(password[i])) {
				lowercaseSymbol = true;
			}
			if (isdigit(password[i])) {
				digitSymbol = true;
			}
		}

		if (!uppercaseSymbol) {
			cout << "\t\t\t| ������ ������ ��������� ���� �� ���� ��������� �����." << endl;
			cout << endl;
		}
		if (!lowercaseSymbol) {
			cout << "\t\t\t| ������ ������ ��������� ���� �� ���� �������� �����." << endl;
			cout << endl;
		}
		if (!digitSymbol) {
			cout << "\t\t\t| ������ ������ ��������� ���� �� ���� �����." << endl;
			cout << endl;
		}

		if (uppercaseSymbol && lowercaseSymbol && digitSymbol) {
			cout << "\t\t\t| ������ ������������� ����������� ������������." << endl;
			return true;
		}
		return false;
	}

	string inputPassword()
	{
		string password;
		cout << "\t\t\t| ������� ����� ������:" << endl;
		cout << "\t\t\t| 1. ������ ������ �������� ������ �� 1 �����" << endl;
		cout << "\t\t\t| 2. ������ ������ �������� �� �������� [����������� ��������]" << endl;
		cout << "\t\t\t| 3. C�������� � ���� ��� ������� 4 �������(���������, �������� ����� � �����)" << endl;
		cout << "\t\t\t| ������ �������� ������: " << passwordExample << endl;
		while (1)
		{
			cout << "\t\t\t| ������� ������: ";
			getline(cin >> ws, password);
			cout << endl;
			if (isOneWord(password))
			{
				if (isEnglish(password))
				{
					if (isPasswordSecure(password))
					{
						break;
					}
				}
			}
		}
		return password;
	}
};


template<class T>
class IAuthenticable
{
public:
	virtual shared_ptr<T> authenticate(vector<shared_ptr<T>>& accountsBASE) = 0;
};
template<class T>
class AuthenticateSystem : public IAuthenticable<T>
{
public:
	shared_ptr<T> authenticate(vector<shared_ptr<T>>& accountsBASE) override
	{
		string logTry;
		string pasTry;
		cout << "������� ��� �����: ";
		getline(cin >> ws, logTry);
		cout << "������� ��� ������: ";
		pasTry = inputPasswordSecure();
		for (auto& item : accountsBASE)
		{
			if (isInit(logTry, pasTry, item->getLogin(), item->getPassword()))
			{
				cout << "�� ������� ����� � �������!" << endl;
				return item;
			}
		}
		return nullptr;
	}
	bool isInit(string tryLogin, string tryPassword, string login, string password)
	{
		if (tryLogin == login && tryPassword == password)
			return true;
		else
			return false;
	}
	string inputPasswordSecure()
	{
		string password;
		int ch = 0;
		cout << "\t\t\t| ������� ������: ";
		while (1)
		{
			ch = _getch(); // 13 - ��� ENTER
			if (ch == 13)
			{
				break;
			}
			else if (ch == 8) // 8 - ��� BACKSPACE
			{
				if (password.length() > 0)
				{
					password.erase(password.length() - 1); // �������� ���������� ������� �� ������
					cout << (char)8 << ' ' << (char)8; //������� ������ �� 1 ����� - �������� �������� ��������� ������(��������� ��������) - ���������� ������ ������� �� 1 ������� �����.
				}
			}
			else
			{
				cout << '*';
				password += (char)ch;
			}
		}
		cout << endl;
		return password;
	}
};



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
				throw runtime_error("���������� ������� ����: " + filePath);
			}

			for (const auto& item : BASE)
			{
				file << item;
			}

			file.close();
		}
		catch (const exception& e)
		{
			cerr << "������ ��� ������ � ����: " << e.what() << endl;
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
				throw runtime_error("���������� ������� ����: " + filePath);
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
			cerr << "������ ��� ������ �� �����: " << e.what() << endl;
		}
		return accountsBASE;
	}
};

