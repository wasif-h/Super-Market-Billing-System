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

// Class to represent a Bill item and its attributes (name, price, quantity)
class Bill {
private:
    // Private attributes to store item details
    string itemName;
    int itemPrice;
    int itemQuantity;

public:
    // Constructor to initialize a Bill object with default or specific values
    Bill(string itemName = "", int itemPrice = 0, int itemQuantity = 0) {
        this->itemName = itemName;
        this->itemPrice = itemPrice;
        this->itemQuantity = itemQuantity;
    }

    // Setter methods to update item attributes
    void setItemName(string itemName) {
        this->itemName = itemName;
    }

    void setItemPrice(int itemPrice) {
        this->itemPrice = itemPrice;
    }

    void setItemQuantity(int itemQuantity) {
        this->itemQuantity = itemQuantity;
    }

    // Getter methods to retrieve item attributes
    string getItemName() {
        return itemName;
    }

    int getItemPrice() {
        return itemPrice;
    }

    int getItemQuantity() {
        return itemQuantity;
    }
};

// Function to handle adding items to the shopping cart
void addItemToCart(Bill customerBill) {
    // Variable to manage the loop for adding items
    bool continueAddingItems = true;

    // Loop to handle the add-to-cart menu
    while (continueAddingItems) {
        system("cls"); // Clear the terminal screen for better visibility

        // Display the add-to-cart menu
        cout << "========================================" << endl;
        cout << "            Add to Cart Menu            " << endl;
        cout << "========================================" << endl;
        cout << " [1] Add Item to Cart" << endl;
        cout << " [2] Return to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        int userChoice;
        cin >> userChoice;

        // Handle user choice to add items or return to main menu
        if (userChoice == 1) {
            system("cls"); // Clear the screen

            // Prompt user to input item details
            cout << "========================================" << endl;
            cout << "           Add Item Details             " << endl;
            cout << "========================================" << endl;

            string itemNameInput;
            int itemPriceInput;
            int itemQuantityInput;

            cout << "Enter item name: ";
            cin.ignore(); // Ignore leftover input from previous cin
            getline(cin, itemNameInput);

            cout << "Enter item price: ";
            cin >> itemPriceInput;

            cout << "Enter item quantity: ";
            cin >> itemQuantityInput;

            // Update the Bill object with input values
            customerBill.setItemName(itemNameInput);
            customerBill.setItemPrice(itemPriceInput);
            customerBill.setItemQuantity(itemQuantityInput);

            // Append the item details to the billing file
            ofstream outputFile("totalbill.txt", ios::app);
            if (!outputFile.is_open()) {
                cout << "Error: Unable to open billing file." << endl;
            } else {
                outputFile << customerBill.getItemName() << "|" << customerBill.getItemPrice() << "|" << customerBill.getItemQuantity() << endl;
                outputFile.close();
                cout << "Item added to cart successfully!" << endl;
            }
        } else if (userChoice == 2) {
            // Return to the main menu
            system("cls");
            continueAddingItems = false;
            cout << "Returning to the main menu..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Function to display the total bill and item details
void printTotalBill() {
    // Variable to manage the loop for viewing the bill
    bool continueViewingBill = true;

    // Loop to handle the view-bill menu
    while (continueViewingBill) {
        // Display the view-bill menu
        cout << "========================================" << endl;
        cout << "            View Total Bill             " << endl;
        cout << "========================================" << endl;
        cout << " [1] View Bill" << endl;
        cout << " [2] Return to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        int userChoice;
        cin >> userChoice;

        // Handle user choice to view the bill or return to main menu
        if (userChoice == 1) {
            system("cls");

            int totalAmount = 0; // Variable to store the total bill amount
            ifstream inputFile("totalbill.txt");

            if (!inputFile.is_open()) {
                cout << "No items found in the cart. Add items first!" << endl;
            } else {
                cout << "========================================" << endl;
                cout << "            Items Purchased             " << endl;
                cout << "========================================" << endl;

                string line;

                // Read item details from the file and display them
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

                    // Display individual item details and total price for that item
                    cout << itemNameFromFile << " - " << itemPriceFromFile << " x " << itemQuantityFromFile << " = " << totalPriceForItem << endl;

                    totalAmount += totalPriceForItem; // Add to total bill
                }

                cout << "========================================" << endl;
                cout << "Total Amount: " << totalAmount << endl;
                cout << "========================================" << endl;

                inputFile.close();
            }
        } else if (userChoice == 2) {
            // Return to the main menu
            system("cls");
            continueViewingBill = false;
            cout << "Returning to the main menu..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Main function to run the Super Shop System program
int main() {
    Bill customerBill; // Create a Bill object for the customer

    bool exitProgram = false; // Variable to manage the main menu loop

    // Loop to handle the main menu
    while (!exitProgram) {
        system("cls");

        // Display the main menu
        cout << "========================================" << endl;
        cout << "      WELCOME TO THE SUPER SHOP         " << endl;
        cout << "========================================" << endl;
        cout << " [1] Start Shopping" << endl;
        cout << " [2] View Total Bill" << endl;
        cout << " [3] Exit Program" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        int mainMenuChoice;
        cin >> mainMenuChoice;

        // Handle main menu choices
        if (mainMenuChoice == 1) {
            // Start shopping by adding items to the cart
            system("cls");
            addItemToCart(customerBill);
        } else if (mainMenuChoice == 2) {
            // View the total bill
            system("cls");
            printTotalBill();
        } else if (mainMenuChoice == 3) {
            // Exit the program
            system("cls");
            exitProgram = true;
            cout << "Thank you for using the Super Shop System. Goodbye!" << endl << endl;
        } else {
            cout << "Invalid input. Please enter a valid choice."<< endl << endl;
        }
    }

    // Remove the billing file after program execution
    remove("totalbill.txt");

    return 0;
}
