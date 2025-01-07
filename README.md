
# IUBAT Super Shop Billing System

## Project Overview

The **IUBAT Super Shop Billing System** is a C++-based application designed to automate the billing process for a super shop. The system supports item addition, discount calculations, and total bill generation. It uses Object-Oriented Programming (OOP) principles to ensure efficiency, scalability, and ease of use.

### Project Details

- **Course**: CSC – 284
- **Submitted To**: Abdullah Mohammad Sakib
- **Department**: CSE
- **Team Name**: Anonymous
- **Team Members**: 1
- **Project Name**: IUBAT Super Shop Billing System
- **Technology**: C++
- **Member Name**: Md. Wasif Hossain
- **ID**: 23303320
- **Department**: BCSE, Section G

## Project Structure

The project is modular and adheres to Object-Oriented Programming principles. The main components are:

### 1. **Classes**:
- **Bill**: The base class for handling general billing operations.
- **DiscountBill**: A derived class that extends the Bill class to include discount logic.

### 2. **Functions**:
- **addItemToCart(Bill&)**: Adds items to the shopping cart.
- **printTotalBill()**: Displays the detailed bill, including discount calculations.
- **main()**: Controls the flow of the program and handles user interaction.

### 3. **File Handling**:
- The project uses file I/O operations to save item details to a text file (`totalbill.txt`), ensuring smooth data handling.

## OOP Concepts Used

### 1. **Encapsulation**:
- Private and protected attributes like `itemName`, `itemPrice`, and `itemQuantity` in the Bill class.
- Getter and setter methods to control access to these attributes.

### 2. **Inheritance**:
- **DiscountBill** class inherits from **Bill**, allowing code reuse and functionality extension.

### 3. **Polymorphism**:
- The `calculateTotalCost()` method is overridden in **DiscountBill** to apply discounts.

### 4. **Abstraction**:
- High-level methods like `addItemToCart()` and `printTotalBill()` abstract complex logic for ease of use and maintenance.

## Benefits of the Project

- **Efficiency**: Automates the billing process, reducing human error and saving time.
- **Flexibility**: Supports adding multiple items and applying customizable discounts.
- **Scalability**: Easily extendable to include features like taxes, loyalty points, or barcode scanning.
- **User-Friendly**: Simple menu-driven interface for smooth user interaction.

## Sample Outputs

1. **Start Shopping**
   - Input: User enters item details (name, price, quantity).
   - Output: Item is saved to `totalbill.txt` and a confirmation message is displayed.

2. **View Total Bill**
   - Input: User enters a discount percentage.
   - Output: The system displays the item list, calculates the total before and after applying the discount.

3. **Exit Program**
   - Action: Program terminates, and the `totalbill.txt` file is deleted, clearing all saved data.

## Handling User Inputs

1. **Invalid Menu Option**:
   - Input: A number outside the menu range.
   - Output: Error message prompts re-entry.

2. **Non-Numeric Input for Numeric Fields**:
   - Input: Text instead of a number for price or quantity.
   - Output: Program crashes (suggest input validation to prevent this).

3. **Empty Input for Item Name**:
   - Input: Pressing Enter without an item name.
   - Output: Item added with an empty name (this can be enhanced).

## Repository Link

You can access the full project repository here:

- **GitHub Repository**: [IUBAT Super Shop Billing System](https://github.com/wasif-h/Super-Shop-Billing-System.git)

## Conclusion

The IUBAT Super Shop Billing System demonstrates the practical application of OOP principles in C++. By incorporating features like discounts and file handling, this project showcases how C++ can be used for real-world solutions.

---

**Contact**:  
Email: wasif.hx@gmail.com  
©️ 2025 Wasif Hossain. All Rights Reserved.
```
