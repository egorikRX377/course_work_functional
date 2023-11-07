#include "reg_log_area.h"


using namespace std;



Account::Account() : login("unknownValue"), password("unknownValue") {}
Account::Account(std::string login, std::string password) : login(login), password(password) {}

std::string Account::getLogin() { return login; }
std::string Account::getPassword() { return password; }
void Account::setLogin(std::string login) { this->login = login; }
void Account::setPassword(std::string password) { this->password = password; }



UserAccount::UserAccount() : Account() {}
UserAccount::UserAccount(std::string login, std::string password) : Account(login, password) {}
std::ostream& operator<<(std::ostream& buf, const std::shared_ptr<UserAccount>& accountPtr)
{
	buf << accountPtr->getLogin() << ' ' << accountPtr->getPassword() << std::endl;
	return buf;
}
std::istream& operator>>(std::istream& buf, std::shared_ptr<UserAccount>& accountPtr)
{
	std::string login;
	std::string password;
	buf >> login >> password;
	accountPtr->setLogin(login);
	accountPtr->setPassword(password);
	return buf;
}



AdminAccount::AdminAccount() : Account() {}
AdminAccount::AdminAccount(std::string login, std::string password) : Account(login, password) {}
std::ostream& operator<<(std::ostream& buf, const std::shared_ptr<AdminAccount>& accountPtr)
{
	buf << accountPtr->getLogin() << ' ' << accountPtr->getPassword() << std::endl;
	return buf;
}
std::istream& operator>>(std::istream& buf, std::shared_ptr<AdminAccount>& accountPtr)
{
	std::string login;
	std::string password;
	buf >> login >> password;
	accountPtr->setLogin(login);
	accountPtr->setPassword(password);
	return buf;
}