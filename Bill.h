#ifndef BILL_H
#define BILL_H

#include <string>
using namespace std;

class Bill {
private:
    string itemName;
    int itemPrice;
    int itemQuantity;

public:
    Bill(string itemName = "", int itemPrice = 0, int itemQuantity = 0);
    void setItemName(string itemName);
    void setItemPrice(int itemPrice);
    void setItemQuantity(int itemQuantity);
    string getItemName();
    int getItemPrice();
    int getItemQuantity();
};

#endif
