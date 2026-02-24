// file name: Account.cpp
// Name: William Nguyen

#include "Account.h"
using namespace std;


Account::Account(string username, string status)   //Constructor
{ 
    this->username = username;
    this->status = status;
}

Account::~Account() {   // Destructor
    cout << "Account removed.\n";
}


string Account::getStatus() const { // Getter Function
    return Account::status;
}


