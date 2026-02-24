// file name: FoodOrder.cpp
// Name: William Nguyen

#include "FoodOrder.h"
#include "InvalidInput.h"
using namespace std;

FoodOrder::FoodOrder(string name, string date, string phone, float miles, float orderBalance, string restaurantName) // Constructor
           :DeliveryOrder(name, date, phone, miles, orderBalance)   // calling DeliveryOrder's constructor
{

}

FoodOrder::~FoodOrder() {   // Destructor
    cout << "FoodOrder destroyed.\n";
}

void FoodOrder::receipt() const 
{
    DeliveryOrder::receipt(); // call receipt() function of DeliveryOrder
    cout << "\tDrinks Count: " << foodCount << endl;  // add extra line to receipt
}

float FoodOrder::VIPdiscount()  // Override VIPdiscount function
{
    if (foodCount > 50)
        return 0.85;
    if (foodCount > 30)
        return 0.9;
    if (foodCount > 20)
        return 0.95;
    else
        return 1;
}

void FoodOrder::addFood(string foodName, int sides, bool addSoup)
{
    float foodCost = 0;
    if (foodName.compare("Thick Cauliflower Steaks") == 0){
        foodCost = 15;
    }
    else if (foodName == "Rack of Lamb") {
        foodCost = 38;
    }
    else if (foodName == "Organic Scottish Salmon") {
        foodCost = 23;
    }
    else if (foodName == "Grilled Lobster Risotto") {
        foodCost = 46;  
    }              
    else {
        throw InvalidInput(foodName);
    }
    if (addSoup = true) {
        foodCost = foodCost + 5;
    } else
    foodCost = foodCost + sides * 6;
    orderBalance = orderBalance + foodCost;
    foodCount = foodCount + 1;
}