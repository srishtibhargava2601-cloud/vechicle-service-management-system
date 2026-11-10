
#include <iostream>
#include <limits>
#include "invoice.h"

using namespace std;

int main()
{
    string id, customer, vehicle, service;
    int n;
    double price, labour;

    cout << "===== VEHICLE SERVICE MANAGEMENT SYSTEM =====\n";

    cout << "\nEnter Invoice ID: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Customer Name: ";
    getline(cin, customer);

    cout << "Enter Vehicle Number: ";
    getline(cin, vehicle);

    Invoice bill(id, customer, vehicle);

    cout << "\nEnter number of services/parts: ";
    cin >> n;

    if (cin.fail() || n < 0 || n > 50)
    {
        cout << "Invalid number of items!\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter service/part name: ";
        getline(cin, service);

        cout << "Enter price: ";
        cin >> price;

        if (cin.fail() || price < 0)
        {
            cout << "Invalid price!\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bill.addItem(service, price);
    }

    cout << "\nEnter labour charges: ";
    cin >> labour;

    if (cin.fail() || labour < 0)
    {
        cout << "Invalid labour charges!\n";
        return 1;
    }

    bill.setLabourCharges(labour);

    bill.displayInvoice();

    bill.saveInvoice();

    return 0;
}
