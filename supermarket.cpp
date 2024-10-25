// Author : Wasif Hossain <https://www.linkedin.com/in/wasif-h>
// Project  : Super Market Billing System
#include <bits/stdc++.h>
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

// <<<---------  main function   --------->>>
int main()
{

    cout << "---- Code with Wasif ----\n\n";

    return 0;
}