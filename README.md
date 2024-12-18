
# 🛒 **IUBAT Super Shop Billing System** 🧾

## 📜 **Overview**
Welcome to the **Super Shop Billing System** developed as part of the university project in the **CSC 284** course, section **G**. This system allows users to easily manage their shopping experience with an interactive interface, where they can add items to the cart, view the total bill, and exit the program.

🔧 **Technologies**: C++ | Object-Oriented Programming (OOP)

### 👨‍💻 **Author Information:**
- **Author**: Md. Wasif Hossain
- **Course**: CSC 284, Section G
- **University ID**: 23303320
- **Email**: wasif.hx@gmail.com
- **GitHub Username**: [wasif-h](https://github.com/wasif-h)

## 🚀 **Features**
- 🛍️ **Add Items to Cart**: Input item details such as name, price, and quantity.
- 💰 **View Total Bill**: See the breakdown of items in the cart and the total cost.
- 📑 **Bill Storage**: Item information is stored temporarily in a file (`totalbill.txt`) during the session.
- 🧹 **File Cleanup**: The `totalbill.txt` file is automatically deleted after the program ends.

## 📝 **Requirements**
- C++ compiler (e.g., GCC, MinGW, or any IDE that supports C++)
- Windows or Linux-based OS for execution.

## 📂 **How to Run the Program**
1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/wasif-h/Super-Shop-Billing-System.git
    ```

2. Navigate to the project directory:
    ```bash
    cd Super-Shop-Billing-System
    ```

3. Compile the C++ code:
    ```bash
    g++ -o superShop main.cpp
    ```

4. Run the compiled program:
    ```bash
    ./superShop
    ```

## 🧑‍💻 **Code Explanation**
The program is structured with several key components:
- **Bill Class**: Represents an item with attributes like name, price, and quantity.
- **Main Menu**: Users can choose between adding items to the cart, viewing the total bill, or exiting the program.
- **Add Item Function**: Collects item details and stores them in the `totalbill.txt` file.
- **Print Total Bill Function**: Displays the items in the cart along with the total amount.

## 🗂️ **File Handling**
The system uses a text file `totalbill.txt` to temporarily store the cart information. This file is automatically deleted when the program finishes running.

## 📊 **Example of Bill Input**:
```
========================================
            IUBAT SUPER SHOP
========================================
 [1] Start Shopping
 [2] View Total Bill
 [3] Exit Program
========================================
Enter your choice: 
========================================

```
## 📊 **Example of Selecting Option 1**:
```
========================================
            Add to Cart Menu
========================================
 [1] Add Item to Cart
 [2] Return to Main Menu
========================================
Enter your choice:

```

```
========================================
           Add Item Details
========================================
Enter item name: Coca Cola
Enter item price: 45
Enter item quantity: 3
```



## 📊 **Example of Selecting Option 2**:
```
========================================
            View Total Bill
========================================
 [1] View Bill
 [2] Return to Main Menu
========================================
Enter your choice:

```

## 📊 **Example of Bill Output**:
```
========================================
            Items Purchased
========================================
Coca Cola - 45 x 3 = 135
A4 Paper - 2 x 100 = 200
========================================
Total Amount: 335
========================================

```
## 💬 **Contact**
Feel free to reach out via email: **wasif.hx@gmail.com** if you have any questions.

Thanks for using the **IUBAT Super Shop Billing System**! 🙌
