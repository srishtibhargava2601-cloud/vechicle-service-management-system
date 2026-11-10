
#include "Invoice.h"
#include <fstream>
#include <iomanip>

Invoice::Invoice(string id, string customer, string vehicle)
{
    invoiceId = id;
    customerName = customer;
    vehicleNumber = vehicle;

    labourCharges = 0;
    gstRate = 18;
}

void Invoice::addItem(string name, double price)
{
    if (price >= 0)
    {
        items.push_back({name, price});
    }
}

void Invoice::setLabourCharges(double amount)
{
    if (amount >= 0)
    {
        labourCharges = amount;
    }
}

double Invoice::calculateSubtotal()
{
    double total = labourCharges;

    for (auto item : items)
    {
        total += item.second;
    }

    return total;
}

double Invoice::calculateGST()
{
    return calculateSubtotal() * gstRate / 100;
}

double Invoice::calculateTotal()
{
    return calculateSubtotal() + calculateGST();
}

void Invoice::displayInvoice()
{
    cout << fixed << setprecision(2);

    cout << "\n========== VEHICLE SERVICE INVOICE ==========\n";

    cout << "Invoice ID: " << invoiceId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Vehicle Number: " << vehicleNumber << endl;

    cout << "\nService Details:\n";

    for (auto item : items)
    {
        cout << item.first << " : Rs. "
             << item.second << endl;
    }

    cout << "Labour Charges: Rs. "
         << labourCharges << endl;

    cout << "---------------------------------------------\n";

    cout << "Subtotal: Rs. "
         << calculateSubtotal() << endl;

    cout << "GST (18%): Rs. "
         << calculateGST() << endl;

    cout << "Grand Total: Rs. "
         << calculateTotal() << endl;

    cout << "=============================================\n";
}

void Invoice::saveInvoice()
{
    ofstream file("Invoice_" + invoiceId + ".txt");

    if (!file)
    {
        cout << "Error saving invoice!\n";
        return;
    }

    file << fixed << setprecision(2);

    file << "VEHICLE SERVICE INVOICE\n";
    file << "Invoice ID: " << invoiceId << endl;
    file << "Customer Name: " << customerName << endl;
    file << "Vehicle Number: " << vehicleNumber << endl;

    file << "\nService Details:\n";

    for (auto item : items)
    {
        file << item.first << " : Rs. "
             << item.second << endl;
    }

    file << "Labour Charges: Rs. "
         << labourCharges << endl;

    file << "Subtotal: Rs. "
         << calculateSubtotal() << endl;

    file << "GST: Rs. " << calculateGST() << endl;

    file << "Grand Total: Rs. "
         << calculateTotal() << endl;

    file.close();

    cout << "\nInvoice saved successfully!\n";
}
