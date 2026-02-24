// file name: InvalidInput.h
// Name: William Nguyen

#ifndef INVALIDINPUT_H    // dup check
#define INVALIDINPUT_H

#include <iostream>
#include <string>
using namespace std;

class InvalidInput 
{
public:
    InvalidInput(string input) : message("Invalid input \"" + input + "\".\n") {};  // Exception (input is the name of the drink or food)

    void print_reason() {cout << message;}  // print reason

private:
    const string message;
    
};

#endif // INVALIDINPUT_H