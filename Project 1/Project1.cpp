// file name: Project1.cpp
// Name: William Nguyen

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct userAccount {
    /* struct to store user information */
    string username, nationality;
    int age, accountBalance;
};

int main() {
    //Create an array of user struct holding up to 10 accounts
    userAccount accts[10];

    //Instruction
     cout << "Please enter information to database in the format of <username> <nationality> <age> <accountBalance>, separated each user by a newline:" << endl;

    //Initialize variables
    string username, nationality;
    int age, under18 = 0;
    float accountBalance, balanceSum = 0, highestBalance = 0;
    int usersFromJapan = 0;
    int userCount = 0;

    //Read in user name, nationality, age, and balance into struct
    while (cin >> username >> nationality >> age >> accountBalance) {
        userAccount user;
        user.username = username;
        user.nationality = nationality;
        user.age = age;
        user.accountBalance = accountBalance;
        accts[userCount] = user;
        if (age < 18) { //Count how many users are under 18
            under18 ++;
        }
        if (accountBalance > highestBalance) { //Update highest balance with each loop
            highestBalance = accountBalance;
        }
        if ((nationality.compare("Japanese")) == 0) { //Count how many users inputted "Japanese" for nationality
            usersFromJapan ++;
        }
        balanceSum = balanceSum + accountBalance; //Calculate the sum of the all account balances
        userCount++;
    }

    //Output user information
    cout << "\nQ: What is the highest account balance among all users?";
    cout << setprecision(2) << fixed; // set floating point with precision 2
    cout << "\nA: $" << highestBalance << endl;
    
    cout << "\nQ: What's the sum of account balance of all users?";
    cout << setprecision(1) << fixed; // set floating point with precision 1
    cout << "\nA: $" << balanceSum << endl;

    cout << "\nQ: How many users come from Japan";
    cout << "\nA: " << usersFromJapan << endl;

    cout << "\nQ: Do we have any user younger than 18?";
    cout << "\nA: ";
        if (under18 > 0) {  //Determine if the the count for users under 18 is higher than 0
            cout << "Yes";
        } else {
            cout << "No";
        }

    return 0;
}