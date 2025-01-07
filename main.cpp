// Author - Md. Wasif Hossain
// Course - CSC 284    Section - G
// ID - 23303320
// Email - wasif.hx@gmail.com

// Project - IUBAT SUPER SHOP - USING C++ and OOP concepts

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Base class for all bill types
class Bill {
protected:
    string itemName;
    int itemPrice;
    int itemQuantity;

public:
    Bill(string itemName = "", int itemPrice = 0, int itemQuantity = 0) {
        this->itemName = itemName;
        this->itemPrice = itemPrice;
        this->itemQuantity = itemQuantity;
    }

    void setItemName(string itemName) {
        this->itemName = itemName;
    }

    void setItemPrice(int itemPrice) {
        this->itemPrice = itemPrice;
    }

    void setItemQuantity(int itemQuantity) {
        this->itemQuantity = itemQuantity;
    }

    string getItemName() {
        return itemName;
    }

    int getItemPrice() {
        return itemPrice;
    }

    int getItemQuantity() {
        return itemQuantity;
    }

    // Virtual method to calculate total cost (override in derived classes)
    virtual int calculateTotalCost() {
        return itemPrice * itemQuantity;
    }
};

// Derived class for handling discount calculations
class DiscountBill : public Bill {
private:
    float discountPercentage;

public:
    DiscountBill(string itemName = "", int itemPrice = 0, int itemQuantity = 0, float discountPercentage = 0)
        : Bill(itemName, itemPrice, itemQuantity) {
        this->discountPercentage = discountPercentage;
    }

    void setDiscountPercentage(float discount) {
        this->discountPercentage = discount;
    }

    float getDiscountPercentage() {
        return discountPercentage;
    }

    int calculateTotalCost() override {
        int totalCost = Bill::calculateTotalCost();
        return totalCost - static_cast<int>(totalCost * (discountPercentage / 100));
    }
};

// Function to handle adding items to the shopping cart
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

// Function to display the total bill with discount
void printTotalBill() {
    DiscountBill discountBill;
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

                inputFile.close();

                cout << "========================================" << endl;
                cout << "Enter discount percentage: ";
                float discountPercentage;
                cin >> discountPercentage;

                discountBill.setDiscountPercentage(discountPercentage);
                int discountedTotal = totalAmount - static_cast<int>(totalAmount * (discountPercentage / 100));

                cout << "Total Amount (Before Discount): " << totalAmount << endl;
                cout << "Discount Applied: " << discountPercentage << "%" << endl;
                cout << "Total Amount (After Discount): " << discountedTotal << endl;
                cout << "========================================" << endl;
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

int main() {
    DiscountBill customerBill;
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
