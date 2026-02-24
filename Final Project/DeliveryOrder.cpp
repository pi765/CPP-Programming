// file name: DeliveryOrder.cpp
// Name: William Nguyen

#include "DeliveryOrder.h"
#include <iomanip>
using namespace std;

int DeliveryOrder::orderCount;    // initialize static members
const float DeliveryOrder::taxRate = 0.09;
const float DeliveryOrder::deliveryRate = 1.5;

DeliveryOrder::DeliveryOrder(string name, string date, string phone, float miles, float orderBalance)   //Constructor
{  
    this->name = name;
    this->date = date;
    this->phone = phone;
    this->miles = miles;
    orderCount = orderCount + 1;  // increase orderCount
}

DeliveryOrder::~DeliveryOrder() {   // Destructor
    cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const {   // receipt
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << setprecision(2) << fixed;
    cout << "\tOrder Balance: $" << orderBalance << endl;
}

// Getter Functions
float DeliveryOrder::getTotalBalance() const {
    float deliveryBalance = orderBalance * (1 + taxRate) + miles * deliveryRate;
    return deliveryBalance;
}

int DeliveryOrder::getOrderCount() {
    return DeliveryOrder::orderCount;
}

