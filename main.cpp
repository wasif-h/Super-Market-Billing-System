#include "Bill.h"
#include "AddToCart.h"
#include "ViewBill.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    Bill customerBill;
    bool exitProgram = false;

    while (!exitProgram) {
        system("cls");
        cout << "========================================" << endl;
        cout << "            IUBAT SUPER SHOP            " << endl;
        cout << "========================================" << endl;
        cout << " [1] Start Shopping" << endl;
        cout << " [2] View Total Bill" << endl;
        cout << " [3] Exit Program" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        int mainMenuChoice;
        cin >> mainMenuChoice;

        if (mainMenuChoice == 1) {
            system("cls");
            addItemToCart(customerBill);
        } else if (mainMenuChoice == 2) {
            system("cls");
            printTotalBill();
        } else if (mainMenuChoice == 3) {
            system("cls");
            exitProgram = true;
            cout << "Thank you for using the Super Shop System. Goodbye!" << endl << endl;
        } else {
            cout << "Invalid input. Please enter a valid choice." << endl << endl;
        }
    }

    remove("totalbill.txt");
    return 0;
}
