// file name: main.cpp
// Name: William Nguyen

#include <iostream>
#include <fstream>
#include <string>

#include "Minion.cpp"
using namespace std;

int main() {

//Open and read file
    //Open file
    ifstream minionsFile("minions.txt");
    //Check file open
    if (!minionsFile.is_open()){
        cout << "File fail to open." << endl;
        return 0;
    }

//Initialize minion with name, height, eyes, and bananasOwned
    string name;
    float height;
    int eyes;
    int bananas;
    minionsFile >> name >> height >> eyes >> bananas;
    const Minion minion1(name, height, eyes, bananas);
    minionsFile >> name >> height >> eyes >> bananas;
    Minion minion2(name, height, eyes, bananas);
    minionsFile >> name >> height >> eyes >> bananas;
    Minion minion3(name, height, eyes, bananas);

//Close "minions.txt"
    minionsFile.close();

//Find the taller minion
    if (minion1 > minion2) {
        cout << minion1.getName() << " is taller than " << minion2.getName();
    }
    if (minion2 < minion3) {
        cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl;

//Minion2 gets 2 bananas
    cout << minion2;
    cout << minion2.getName() << " getting bananas.\n";
    cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;

//Minion3 grows 1 strand
    cout << minion3;
    cout << minion3.getName() << " getting bananas.\n";
    cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;

//Count number of minions created.
    Minion::printMinionCount();

return 0;
}