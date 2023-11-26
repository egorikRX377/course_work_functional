#include "encryption.h"

using namespace std;
using namespace CryptoPP;


string hashPassword(const string& password)
{
    SHA256 hash;
    string hashedPassword;

    StringSource(password, true, new HashFilter(hash, new HexEncoder(new StringSink(hashedPassword))));

    return hashedPassword;
}

bool checkPassword(const string& inputPassword, const string& storedHashedPassword)
{
    string inputHashedPassword = hashPassword(inputPassword);
    return (inputHashedPassword == storedHashedPassword);
}
