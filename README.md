
# IUBAT Super Shop Billing System

A C++ application simulating a billing system for **IUBAT Super Shop**. This project demonstrates Object-Oriented Programming (OOP) principles and utilizes file handling to manage product data and customer billing.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Structure](#structure)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)


## Features

- **Product Management**: Add, remove, and update products in inventory.
- **Billing System**: Generate bills for customers based on selected items.
- **File Handling**: Store and retrieve data on products and sales using files.
- **OOP Principles**: Classes and objects model real-world entities like `Product`, `Customer`, and `Bill`.

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/wasif-h/Super-Shop-Billing-System.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Super-Shop-Billing-System
   ```
3. Compile the code (ensure you have a C++ compiler):
   ```bash
   g++ main.cpp -o billingSystem
   ```

4. Run the executable:
   ```bash
   ./billingSystem
   ```

## Usage

1. **Add Products**: Enter product details such as name, price, and quantity.
2. **Billing**: Select products to purchase, and the system will calculate the total price.
3. **Save and Retrieve Data**: Data is saved to and loaded from files to maintain persistence between sessions.

## Structure

- **Classes**:
  - `Product`: Represents items available in the shop.
  - `Customer`: Manages customer information.
  - `Bill`: Calculates and manages billing information.
  
- **File Handling**:
  - Data is saved in text files to keep track of inventory and customer bills.

## Technologies Used

- **C++**: Language for implementing the billing system.
- **File I/O**: Used for saving and retrieving data in files.

## Contributing

Contributions are welcome! Feel free to fork this repository, submit issues, or create pull requests.
