// file name: FoodOrder.h
// Name: William Nguyen

#ifndef FOODORDER_H    // dup check
#define FOODORDER_H

#include "DeliveryOrder.h"
using namespace std;

class FoodOrder : public DeliveryOrder {

private: 
string restaurantName;
int foodCount = 0;

public:
FoodOrder(string, string, string, float, float, string);    // Constructor with same parameters as DeliveryOrder and an extra string
~FoodOrder();   // Destructor
void receipt() const;
float VIPdiscount();
void addFood(string foodName, int sides = 0, bool addSoup=false);

};

#endif // FOODORDER_H