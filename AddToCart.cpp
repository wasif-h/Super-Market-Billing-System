#include "AddToCart.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void addItemToCart(Bill& customerBill) {
    bool continueAddingItems = true;

    while (continueAddingItems) {
        system("cls");
        cout << "========================================" << endl;
        cout << "            Add to Cart Menu            " << endl;
        cout << "========================================" << endl;
        cout << " [1] Add Item to Cart" << endl;
        cout << " [2] Return to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        int userChoice;
        cin >> userChoice;

        if (userChoice == 1) {
            system("cls");
            cout << "========================================" << endl;
            cout << "           Add Item Details             " << endl;
            cout << "========================================" << endl;

            string itemNameInput;
            int itemPriceInput;
            int itemQuantityInput;

            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, itemNameInput);

            cout << "Enter item price: ";
            cin >> itemPriceInput;

            cout << "Enter item quantity: ";
            cin >> itemQuantityInput;

            customerBill.setItemName(itemNameInput);
            customerBill.setItemPrice(itemPriceInput);
            customerBill.setItemQuantity(itemQuantityInput);

            ofstream outputFile("totalbill.txt", ios::app);
            if (!outputFile.is_open()) {
                cout << "Error: Unable to open billing file." << endl;
            } else {
                outputFile << customerBill.getItemName() << "|" << customerBill.getItemPrice() << "|" << customerBill.getItemQuantity() << endl;
                outputFile.close();
                cout << "Item added to cart successfully!" << endl;
            }
        } else if (userChoice == 2) {
            system("cls");
            continueAddingItems = false;
            cout << "Returning to the main menu..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
