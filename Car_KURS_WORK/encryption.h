#pragma once
#include <iostream>
#include <string>
#include <sha.h>
#include <hex.h>
#include <Windows.h>
#include <cryptlib.h>
#include <filters.h>


using namespace std;
using namespace CryptoPP;


string hashPassword(const string& password);

bool checkPassword(const string& inputPassword, const string& storedHashedPassword);