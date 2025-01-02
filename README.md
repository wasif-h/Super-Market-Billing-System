
# 🛒 Super Shop Billing System - C++ Project

Welcome to the **Super Shop Billing System**! This project is an Object-Oriented Programming (OOP)-based C++ application for managing a shopping cart, calculating total bills, and improving the retail experience. The program uses modular design principles, splitting functionalities across multiple files for better readability and maintainability.

## 🚀 Features
- **Add Items to Cart**: Dynamically add items with name, price, and quantity.
- **Generate Bills**: View detailed purchase summaries and compute total costs.
- **File Handling**: Save cart data in a file for easy retrieval and processing.
- **User-Friendly Interface**: Simple navigation menus with clear options.
- **Efficient Memory Usage**: Deletes billing data after the program ends.

---

## 📂 Project Structure
The project is divided into multiple files to ensure scalability and maintainability:

### `Bill.h`
Defines the **`Bill` class**, encapsulating item attributes and related methods.

#### Key Elements:
- Private attributes:
  - `itemName`: Name of the product.
  - `itemPrice`: Price per unit.
  - `itemQuantity`: Number of units purchased.
- Public methods:
  - Constructor to initialize `Bill` objects.
  - Getter and Setter methods to access or modify attributes.

### `Bill.cpp`
Implements the **`Bill` class** methods declared in `Bill.h`.

#### Responsibilities:
- Initialize item details using constructor.
- Set or retrieve values for item attributes like name, price, and quantity.

---

### `AddToCart.h`
Declares the **`addItemToCart()`** function, which handles adding items to the cart.

#### Key Features:
- Clear prompts for item details input.
- Appends item data to `totalbill.txt` for record-keeping.
- Menu to continue shopping or return to the main menu.

### `AddToCart.cpp`
Implements the **`addItemToCart()`** functionality.

#### Responsibilities:
- Input item details from the user.
- Use `Bill` class methods to store and retrieve data.
- Save items to a file (`totalbill.txt`) with error handling.

---

### `ViewBill.h`
Declares the **`printTotalBill()`** function, which displays all purchased items and the total amount.

#### Key Features:
- Reads item data from `totalbill.txt`.
- Computes the total cost of all items in the cart.
- Allows users to view or return to the main menu.

### `ViewBill.cpp`
Implements the **`printTotalBill()`** functionality.

#### Responsibilities:
- Parse `totalbill.txt` to retrieve item details.
- Calculate and display individual item costs and the total bill.
- Clear and concise output formatting.

---

### `main.cpp`
The entry point of the application.

#### Features:
- Displays the **main menu** with options:
  1. Start Shopping.
  2. View Total Bill.
  3. Exit Program.
- Calls `addItemToCart()` and `printTotalBill()` as needed.
- Cleans up by deleting `totalbill.txt` after exiting.

---

## 🛠️ How to Run the Project

### Prerequisites
- C++ compiler (e.g., `g++` in GCC).
- Terminal or command-line tool.

### Steps
1. Clone this repository:
   ```bash
   git clone https://github.com/wasif-h/Super-Shop-Billing-System.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Super-Shop-Billing-System
   ```
3. Compile the project:
   ```bash
   g++ -o SuperShop Bill.cpp AddToCart.cpp ViewBill.cpp main.cpp
   ```
4. Run the executable:
   ```bash
   ./SuperShop
   ```

---

## 📈 Future Enhancements
- **Graphical User Interface (GUI)**: Replace the console-based interface with a user-friendly GUI.
- **Database Integration**: Store cart data in a database for persistent storage.
- **Discount Features**: Add options for applying discounts or promotional codes.
- **Multi-Language Support**: Expand accessibility with multiple language options.

---

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

## 🙌 Acknowledgments
Special thanks to everyone who inspired the development of this project. Contributions and feedback are always welcome!


### 👨‍💻 Author
**Wasif Hossain**  
GitHub: [wasif-h](https://github.com/wasif-h)

---
✨ Happy Coding! ✨
```

