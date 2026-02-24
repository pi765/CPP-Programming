// file name: Minion.h
// Name: William Nguyen

#ifndef MINION_H    // dup check
#define MINION_H

#include <iostream>
#include <string>
using namespace std;

class Minion {
    friend ostream& operator<<(ostream&, Minion&);  // insertion<<

private: 
    string name;
    float height;
    int eyes;
    int bananasOwned;
    static int minionCount; //static private

public:
    Minion(string name, float height, int eyes, int bananas); // Constructor
    int getBananas() const; // Getter function
    string getName() const; // Getter function
    static void printMinionCount(); // Static function

    bool operator>(const Minion&) const;    // operator>
    bool operator<(const Minion&) const;    // operator<
    Minion &operator++();   // pre-increment++
    Minion operator++(int); // post-increment++

};

#endif // MINION_H