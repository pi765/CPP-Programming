// file name: BobaOrder.cpp
// Name: William Nguyen

#include "BobaOrder.h"
#include "InvalidInput.h"
using namespace std;

BobaOrder::BobaOrder(string name, string date, string phone, float miles, float orderBalance, string shopName) // Constructor
           :DeliveryOrder(name, date, phone, miles, orderBalance)   // calling DeliveryOrder's constructor
{
    this->shopName = shopName;
}

BobaOrder::~BobaOrder() {   // Destructor
    cout << "BobaOrder destroyed.\n";
}

void BobaOrder::receipt() const 
{
    DeliveryOrder::receipt(); // call receipt() function of DeliveryOrder
    cout << "\tDrinks Count: " << drinksCount << endl;  // add extra line to receipt
}

float BobaOrder::VIPdiscount()  // VIPdiscount function
{
    if (drinksCount > 10)
        return 0.85;
    if (drinksCount > 5)
        return 0.9;
    if (drinksCount > 2)
        return 0.95;
    else
        return 1;
}

void BobaOrder::addDrink(string drinkName, bool addBoba, int sameDrinks)
{
    float drinkCost = 0;
    if (drinkName.compare("Green Tea Latte") == 0) {
        drinkCost = 5.8;
    }
    else if (drinkName.compare("Brown Sugar Boba Milk") == 0) {
        drinkCost = 7.8;
    }
    else if (drinkName.compare("Brown Sugar Pearl Milk") == 0) {
        drinkCost = 9.8;
    }
    else {
        throw InvalidInput(drinkName);  //throw exception
    }
    if (addBoba = true) {
        drinkCost = drinkCost + 1.5;    //add boba
    } else
    drinkCost = drinkCost * sameDrinks;
    orderBalance = orderBalance + drinkCost;    // add up costs
    drinksCount = drinksCount + sameDrinks;     // add up drink count
}