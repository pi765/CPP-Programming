// file name: Account.h
// Name: William Nguyen

#ifndef ACCOUNT_H    // dup check
#define ACCOUNT_H

#include "DeliveryOrder.h"
using namespace std;

class Account{

private: 
string username;    //variables
string status;

public:
Account(string username, string status = "Regular");    // Constructor
~Account();     // Destructor
string getStatus() const;   // get Status
};

#endif // ACCOUNT_H