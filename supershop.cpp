// Author : Wasif Hossain <https://www.linkedin.com/in/wasif-h>
// Project  : Super Shop Billing System
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
using namespace std;

class Bill
{
private:
    string item;
    int price, quantity;

public:
    Bill(string item = "", int price = 0, int quantity = 0)
    {
        this->item = item;
        this->price = price;
        this->quantity = quantity;
    }

    void setitem(string item)
    {
        this->item = item;
    }

    void setprice(int price)
    {
        this->price = price;
    }

    void setquantity(int quantity)
    {
        this->quantity = quantity;
    }

    string getitem()
    {
        return item;
    }

    int getprice()
    {
        return price;
    }
    int getquantity()
    {
        return quantity;
    }
};

void additem(Bill obj)
{
    bool close = false;
    while (!close)
    {
        system("cls");
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Close" << endl;
        cout << "\tEnter Choice : ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int price, quantity;
            cout << "\tEnter item name : ";
            cin >> item;
            obj.setitem(item);

            cout << "\tEnter price : ";
            cin >> price;
            obj.setprice(price);

            cout << "\tEnter quantity : ";
            cin >> quantity;
            obj.setquantity(quantity);

            ofstream my_file("totalbill.txt", ios::app);
            if (!my_file)
            {
                cout << "Error, Can't Open Billing File" << endl;
            }
            else
            {
                my_file << "\t" << obj.getitem() << " : "
                        << obj.getprice() << " : "
                        << obj.getquantity() << endl
                        << endl;

                my_file.close();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            cout << "\t--- Back to Main Menu !!" << endl;
            Sleep(1000);

            close = true;
        }
        else
        {
            cout << "Invalid Entry" << endl;
        }
    }
}

void printbill()
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1. Total Bill" << endl;
        cout << "\t2. Back to Menu" << endl;
        cout << "\tEnter Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            int total = 0;

            system("cls");

            ifstream in("totalbill.txt");
            if (!in)
            {
                cout << "Please buy something before\nchecking your Bill !!\n\n";
            }
            else
            {
            string line;

            while (getline(in, line))
            {
                cout << line << endl;
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                if (ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant)
                {
                    total += (itemRate * itemQuant);
                }
            }
            cout << "\t--------------------------" << endl;
            cout << "\tTotal Bill = " << total << " BDT\n\n"
                 << endl;
            in.close();
            }
        }
        else if (choice == 2)
        {
            close = true;
            system("cls");
            cout << "--- Back to Main Menu !!" << endl;
            Sleep(2000);
        }
        else
        {
            cout << "Invalid Entry";
        }
    }
}
// <<<---------  main function   --------->>>
int main()
{

    Bill b1;

    bool exit = false;
    while (!exit)
    {
        system("cls");

        cout << "  *************************" << endl;
        cout << "  IUBAT SUPER SHOP - UTTARA" << endl;
        cout << "  *************************" << endl;
        cout << "\t1. Start Shopping" << endl;
        cout << "\t2. Print Total Bill" << endl;
        cout << "\t3. Exit" << endl
             << endl;
        cout << "  *************************\n\n";
        cout << "\tEnter Choice : ";


        int choice;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            additem(b1);
            Sleep(2000);
        }
        else if (choice == 2)
        {
            system("cls");
            printbill();
        }
        else if (choice == 3)
        {
            system("cls");
            cout << "--- Thank You Sir / Maam" << endl;
            cout << "--- Assalamualaikum\n\n";
            Sleep(1000);
            exit = true;
        }
        else
        {
            cout << "Invalid Input - Try Again";
        }
    }
    remove("totalbill.txt");

    return 0;
}