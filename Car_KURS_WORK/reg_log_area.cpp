#include "reg_log_area.h"


using namespace std;


Account::Account() : login("unknownValue"), password("unknownValue") {}
Account::Account(string login, string password) : login(login), password(password) {}

string Account::getLogin() { return login; }
string Account::getPassword() { return password; }
void Account::setLogin(string login) { this->login = login; }
void Account::setPassword(string password) { this->password = password; }



UserAccount::UserAccount() : Account() {}
UserAccount::UserAccount(string login, string password) : Account(login, password) {}

bool UserAccount::getAccess() { return access; }
void UserAccount::setAccess(bool access) { this->access = access; }

void UserAccount::virtualFunc()
{
	cout << "Func";
}

ostream& operator<<(ostream& buf, const shared_ptr<UserAccount>& accountPtr)
{
	buf << accountPtr->getLogin() << ' ' << accountPtr->getPassword() << ' ' << accountPtr->getAccess() << endl;
	return buf;
}
istream& operator>>(istream& buf, shared_ptr<UserAccount>& accountPtr)
{
	string login;
	string password;
	bool access;

	buf >> login >> password >> access;

	accountPtr->setLogin(login);
	accountPtr->setPassword(password);
	accountPtr->setAccess(access);

	return buf;
}



AdminAccount::AdminAccount() : Account() {}
AdminAccount::AdminAccount(string login, string password) : Account(login, password) {}
bool AdminAccount::getAccess()
{
	return true;
}

void AdminAccount::virtualFunc()
{
	cout << "Func";
}
ostream& operator<<(ostream& buf, const shared_ptr<AdminAccount>& accountPtr)
{
	buf << accountPtr->getLogin() << ' ' << accountPtr->getPassword() << endl;
	return buf;
}
istream& operator>>(istream& buf, shared_ptr<AdminAccount>& accountPtr)
{
	string login;
	string password;
	buf >> login >> password;
	accountPtr->setLogin(login);
	accountPtr->setPassword(password);
	return buf;
}