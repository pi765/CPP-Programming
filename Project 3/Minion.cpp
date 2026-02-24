// file name: Minion.cpp
// Name: William Nguyen

#include <iostream>
#include <string>

#include "Minion.h"
using namespace std;

int Minion::minionCount;    // initialize static member

Minion::Minion(string name, float height, int eyes, int bananas)
{   // Constructor
    this->name = name;
    this->height = height;
    this->eyes = eyes;
    bananasOwned = bananas;
    minionCount = minionCount + 1;  // increase minionCount
}

// Getter Functions
int Minion::getBananas() const{
    return Minion::bananasOwned;
}

string Minion::getName() const{
    return this->name;
}

// Static Function
void Minion::printMinionCount() {
    cout << minionCount << " minions created." << endl;
}

// Operators
bool Minion::operator>(const Minion &m) const   // operator>
{
    return this->height > m.height;
}

bool Minion::operator<(const Minion &m) const   // operator<
{
    return this->height < m.height;
}

ostream &operator<<(ostream &insertion, Minion &minion) // insertion<<
{
    insertion << "The minion " << minion.name << " is " << minion.height << " inches tall, has " << minion.eyes << " eye(s), and owns " << minion.bananasOwned << " banana(s)." << endl;
    return insertion;
}

Minion& Minion::operator++()    // pre-increment++
{
    this->bananasOwned++;
    return *this;
}

Minion Minion::operator++(int)  // post-increment++
{
    Minion temp = *this;
    this->bananasOwned++;
    return temp;
}