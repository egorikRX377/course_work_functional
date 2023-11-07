#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>


using namespace std;

namespace filePATHS
{
	const std::string USER_ACCOUNTS_PATH = "userAccounts.txt";
	const std::string ADMIN_ACCOUNTS_PATH = "adminAccounts.txt";
	const std::string humanPATH = "humans.txt";
}



class Account
{
protected:
	std::string login;
	std::string password;
public:
	Account();
	Account(std::string login, std::string password);

	std::string getLogin();
	std::string getPassword();
	void setLogin(std::string login);
	void setPassword(std::string password);
};

class UserAccount : public Account
{
public:
	UserAccount();
	UserAccount(std::string login, std::string password);

	friend std::ostream& operator<<(std::ostream& buf, const std::shared_ptr<UserAccount>& accountPtr);
	friend std::istream& operator>>(std::istream& buf, std::shared_ptr<UserAccount>& accountPtr);
};
class AdminAccount : public Account
{
public:
	AdminAccount();
	AdminAccount(std::string login, std::string password);

	friend std::ostream& operator<<(std::ostream& buf, const std::shared_ptr<AdminAccount>& accountPtr);
	friend std::istream& operator>>(std::istream& buf, std::shared_ptr<AdminAccount>& accountPtr);
};



template<class T>
class IRegistrable
{
public:
	virtual std::shared_ptr<T> registrate() = 0;
};
template<class T>
class RegistrateSystem : public IRegistrable<T>
{
public:
	std::shared_ptr<T> registrate() override
	{
		std::cout << "=Регистрация аккаунта=" << std::endl;

		std::string login;
		std::cout << "Введите логин: ";
		std::getline(std::cin >> std::ws, login);

		std::string password;
		std::cout << "Введите пароль: ";
		std::getline(std::cin >> std::ws, password);

		std::shared_ptr<T> accountPtr = std::make_shared<T>(login, password);

		std::cout << "Спасибо за регистрацию!" << std::endl;
		system("pause");

		return accountPtr;
	}
};

template<class T>
class IAuthenticable
{
public:
	virtual std::shared_ptr<T> authenticate(std::vector<std::shared_ptr<T>>& accountsBASE) = 0;
};
template<class T>
class AuthenticateSystem : public IAuthenticable<T>
{
public:
	std::shared_ptr<T> authenticate(std::vector<std::shared_ptr<T>>& accountsBASE) override
	{
		std::string logTry;
		std::string pasTry;
		std::cout << "Введите Ваш логин: ";
		std::getline(std::cin >> std::ws, logTry);
		std::cout << "Введите Ваш пароль: ";
		std::getline(std::cin >> std::ws, pasTry);
		for (auto& item : accountsBASE)
		{
			if (isInit(logTry, pasTry, item->getLogin(), item->getPassword()))
			{
				std::cout << "Вы успешно зашли в аккаунт!" << std::endl;
				return item;
			}
		}
		return nullptr;
	}
	bool isInit(std::string tryLogin, std::string tryPassword, std::string login, std::string password)
	{
		if (tryLogin == login && tryPassword == password)
			return true;
		else
			return false;
	}
};





template<class T>
class FileHandler
{
public:
	static void writeToFile(const std::string& filePath, const std::vector<std::shared_ptr<T>>& BASE)
	{
		std::ofstream file(filePath);

		if (file.is_open())
		{
			for (const auto& item : BASE)
			{
				file << item;
			}
			file.close();
		}
		else
		{
			std::cerr << "Невозможно открыть файл: " << filePath << std::endl;
		}
	}

	static std::vector<std::shared_ptr<T>> readFromFile(const std::string& filePath)
	{
		std::vector<std::shared_ptr<T>> accountsBASE;
		std::ifstream file(filePath);

		if (file.is_open())
		{
			std::shared_ptr<T> item = std::make_shared<T>();
			while (file >> item)
			{
				accountsBASE.push_back(item);
				item = std::make_shared<T>();
			}
			file.close();
		}
		else
		{
			std::cerr << "Невозможно открыть файл: " << filePath << std::endl;
		}
		return accountsBASE;
	}
};

