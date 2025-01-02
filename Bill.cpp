#include "Bill.h"

Bill::Bill(string itemName, int itemPrice, int itemQuantity) {
    this->itemName = itemName;
    this->itemPrice = itemPrice;
    this->itemQuantity = itemQuantity;
}

void Bill::setItemName(string itemName) {
    this->itemName = itemName;
}

void Bill::setItemPrice(int itemPrice) {
    this->itemPrice = itemPrice;
}

void Bill::setItemQuantity(int itemQuantity) {
    this->itemQuantity = itemQuantity;
}

string Bill::getItemName() {
    return itemName;
}

int Bill::getItemPrice() {
    return itemPrice;
}

int Bill::getItemQuantity() {
    return itemQuantity;
}
