#include "ViewBill.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void printTotalBill() {
    bool continueViewingBill = true;

    while (continueViewingBill) {
        cout << "========================================" << endl;
        cout << "            View Total Bill             " << endl;
        cout << "========================================" << endl;
        cout << " [1] View Bill" << endl;
        cout << " [2] Return to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        int userChoice;
        cin >> userChoice;

        if (userChoice == 1) {
            system("cls");
            int totalAmount = 0;
            ifstream inputFile("totalbill.txt");

            if (!inputFile.is_open()) {
                cout << "No items found in the cart. Add items first!" << endl;
            } else {
                cout << "========================================" << endl;
                cout << "            Items Purchased             " << endl;
                cout << "========================================" << endl;

                string line;
                while (getline(inputFile, line)) {
                    stringstream lineStream(line);
                    string itemNameFromFile;
                    int itemPriceFromFile;
                    int itemQuantityFromFile;

                    getline(lineStream, itemNameFromFile, '|');
                    lineStream >> itemPriceFromFile;
                    lineStream.ignore();
                    lineStream >> itemQuantityFromFile;

                    int totalPriceForItem = itemPriceFromFile * itemQuantityFromFile;

                    cout << itemNameFromFile << " - " << itemPriceFromFile << " x " << itemQuantityFromFile << " = " << totalPriceForItem << endl;

                    totalAmount += totalPriceForItem;
                }

                cout << "========================================" << endl;
                cout << "Total Amount: " << totalAmount << endl;
                cout << "========================================" << endl;

                inputFile.close();
            }
        } else if (userChoice == 2) {
            system("cls");
            continueViewingBill = false;
            cout << "Returning to the main menu..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
