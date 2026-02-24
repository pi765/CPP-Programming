// file name: main.cpp
// Name: William Nguyen

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "DeliveryOrder.cpp"
#include "BobaOrder.cpp"
#include "FoodOrder.cpp"
#include "Account.cpp"

using namespace std;

float applyDiscount(DeliveryOrder* pointer, const Account &acct) {  // applyDiscount function

    float discount = pointer->getTotalBalance();
    string status = acct.getStatus();
    if (status.compare("Owner") == 0)
        discount = discount * 0.1;
    else if (status.compare("VIP") == 0)
        discount = discount * pointer->VIPdiscount();
    else
    return discount;
}


int main() {
    const Account a1("Stuart", "Owner");    // Create accounts
    Account a2("Kevin", "VIP");
    Account a3("Bob");
    DeliveryOrder* ptr; // DeliveryOrder pointer

    cout << "Kevin placing order.\n";

    BobaOrder Kevin("Kevin", "11/20/2022", "123-456-0000", 10.4, 0, "M Tea");
    
    try {
        Kevin.addDrink("Green Tea Latte");                  // Try and catch block for adding drinks
        Kevin.addDrink("Brown Sugar Pearl Milk", false);
        Kevin.addDrink("Brown Sugar Boba Milk", false, 2);
        Kevin.addDrink("Iron Goddess", false, 0);
     }
    catch (InvalidInput &e)
    {
        e.print_reason();
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    } 

    Kevin.receipt();    // print receipt
    cout << setprecision(2) << fixed;   // Round to 2 decimal places
    cout << "Balance: $" << Kevin.getTotalBalance() << "\n";    // total Balance

    cout << "Discounted Balance: $" << /* applyDiscount(ptr, a2) << */  "\n";
    cout << "\n\n";


    cout << "Stuart placing order.\n";

    FoodOrder Stuart("Stuart", "11/20/2022", "123-456-1111", 25.5, 0, "Tavern Green");

    try {
        Stuart.addFood("Thick Cauliflower Steaks", 1, true);
        Stuart.addFood("Organic Scottish Salmon", 0, false);
        Stuart.addFood("Rack of Lamb", 0, true);
     }
    catch (InvalidInput &e)
    {
        e.print_reason();
        cout << "Not serving requested food. Food order ignored.\n\n";
    } 

    Stuart.receipt();
    cout << setprecision(2) << fixed;
    cout << "Balance: $" << Stuart.getTotalBalance() << "\n";
    cout << "Discounted Balance: $" << "\n";
    cout << "\n\n";


    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";

    Stuart.receipt();       // re-use Stuart's receipt
    cout << "Balance: $" << Stuart.getTotalBalance() << "\n";
    cout << "Discounted Balance: $" << "\n";
    cout << "Bob upset, cancelling order :(\n\n";

    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "\n\n";

return 0;
}