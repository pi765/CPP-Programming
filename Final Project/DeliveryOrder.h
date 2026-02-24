// file name: DeliveryOrder.h
// Name: William Nguyen

#ifndef DELIVERYORDER_H    // dup check
#define DELIVERYORDER_H

#include <iostream>
#include <string>
using namespace std;

class DeliveryOrder {

private: 
    string name;        // variables
    string date;
    string phone;
    float miles;
    static int orderCount;
    static const float taxRate;
    static const float deliveryRate;

protected:
    float orderBalance;

public:
    DeliveryOrder(string name, string date, string phone, float miles, float orderBalance = 0); // Constructor
    ~DeliveryOrder();       // Destructor
    void receipt() const;   // Print out the order receipt
    float getTotalBalance() const;
    static int getOrderCount();
    virtual float VIPdiscount() = 0; // pure virtual function

};

#endif // DELIVERYORDER_H