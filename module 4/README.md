
# Vehicle Service Management System

## Module 4: Calculate Service Charges and Generate Invoices

### Project Description
This module calculates vehicle service charges
and generates customer invoices.

### Technologies Used
- C++
- Object-Oriented Programming
- Vectors
- File Handling

### Features
- Customer details
- Vehicle details
- Service and spare parts charges
- Labour charge calculation
- GST calculation
- Total bill generation
- Invoice saving in text file

### Formula
Subtotal = Service Charges + Parts Charges + Labour Charges

GST = Subtotal * 18 / 100

Total = Subtotal + GST

### How to Run

Compile:
g++ -std=c++17 main.cpp module4/Invoice.cpp -o vehicle.exe

Run:
.\vehicle.exe

### Module
Module 4 - Billing and Invoice Generation
