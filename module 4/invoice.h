
#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Invoice
{
private:
    string invoiceId;
    string customerName;
    string vehicleNumber;

    vector<pair<string, double>> items;

    double labourCharges;
    double gstRate;

public:
    Invoice(string id, string customer, string vehicle);

    void addItem(string name, double price);

    void setLabourCharges(double amount);

    double calculateSubtotal();

    double calculateGST();

    double calculateTotal();

    void displayInvoice();

    void saveInvoice();
};

#endif
