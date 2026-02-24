// file name: BobaOrder.h
// Name: William Nguyen

#ifndef BOBAORDER_H    // dup check
#define BOBAORDER_H

#include "DeliveryOrder.h"
using namespace std;

class BobaOrder : public DeliveryOrder {

private: 
string shopName;
int drinksCount = 0;

public:
BobaOrder(string, string, string, float, float, string);    // Constructor with same parameters as DeliveryOrder and an extra string
~BobaOrder();   // Destructor
void receipt() const;
float VIPdiscount();
void addDrink(string drinkName, bool addBoba=true, int sameDrinks = 1);

};

#endif // BOBAORDER_H