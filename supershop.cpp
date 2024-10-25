// Author : Wasif Hossain <https://www.linkedin.com/in/wasif-h>
// Project  : Super Shop Billing System
#include <iostream>
#include <fstream>
#include <windows.h>
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
        int val;
        cin >> val;

        if (val == 1)
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
        else
        {
            system("cls");
            cout << "\t--- Back to Main Menu" << endl;
            Sleep(2000);

            close = true;
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
        cout << "\tEnter Choice : ";

        int val;
        cin >> val;

        if (val == 1)
        {
            system("cls");
            additem(b1);
            Sleep(2000);
        }

        if (val == 3)
        {
            system("cls");
            cout << "--- Thank You Sir / Maam" << endl;
            cout << "--- Hope to See you again";
            Sleep(2000);
            exit = true;
        }
    }

    return 0;
}