#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <array>
#include <ctime>
#include <list>
#include <algorithm>
using namespace std;

const int SIZE = 53;
const int NUM_OPS = 10;
const int MAX_CASH = 100, MIN_CASH = 25,
          MAX_BILL = 50, MIN_BILL = 10;

class Customer
{
private:
    string name;
    double cash;
    double bill;
public:
    Customer()
        { name = ""; cash = 0.0; bill = 0.0; }
    Customer(string n, double c, double b)
        { name = n; cash = c; bill = b; }
    void setName(string n) { name = n; }
    void setCash(double b) { cash = b; }
    string getName()       { return name; }
    double getCash()       { return cash; }
    double getBill()       { return bill; }
    void adjustBill(int a) { bill -= a; }
};

class GroceryStore
{
private:
public:
    vector<deque<Customer>> cashiers;
    void setCashier(deque<Customer> d)
        {  cashiers.push_back(d);  }
    int getSize() { return cashiers.size(); }

};

Customer getCustomer(array<string, SIZE>);
void printLane(deque<Customer>);

int main()
{
    //housekeeping
    srand(time(0));

    //load names into names array
    array<string, SIZE> names;
    ifstream fin("names.txt");
    int index = 0;
    while (fin >> names[index++]);
    fin.close();

    GroceryStore safeway;
    int opCount = 0;
    deque<Customer>cashier1;
    cout << "Initial setup:\n";
    cashier1.push_back(getCustomer(names));
    cashier1.push_back(getCustomer(names));
    safeway.setCashier(cashier1);
    printLane(cashier1);

    while (opCount < NUM_OPS)
    {
        cout << "\n\n/*** Operation # " << opCount+1 << ": ***/\n";

        //check for new lane: if 4 customers in any queue open new lane
        bool needNewLane = false;
        Customer tempCust;
        for (int i = 0; i < safeway.getSize(); i++) //checks each lane
            if (safeway.cashiers[i].size() == 4) //checks queue size
            {
                needNewLane = true;
                //retrieve first customer in line
                tempCust = safeway.cashiers[i].front();
                safeway.cashiers[i].pop_front();
            }
        if (needNewLane)
        {
            cout << "* Manager's action: *\nCreating new lane by moving customer ";
            //create new temp customers for the new lane
            cout << tempCust.getName() << " (bill: $" << tempCust.getBill() << " cash: $"
                 << tempCust.getCash() << ") to Lane " << safeway.getSize() + 1 << "\n";
            //create temp queue
            deque<Customer> tempDeque;
            tempDeque.push_back(tempCust);
            safeway.setCashier(tempDeque);
            cout << "\nNew lane queues:\n";
            for (int i = 0; i < safeway.getSize(); i++) //checks each lane
            {
                cout << "Lane #" << i+1 << ":\n";
                printLane(safeway.cashiers[i]);
            }
        }

        cout << "\nLane operations:\n";
        for (int i = 0; i < safeway.getSize(); i++) //checks each lane
        {
            int operation;
            if (safeway.cashiers[i].size() == 0) operation = 1;
            else operation = rand() % 2;
            switch(operation)
            {
            case 0: //customer attempts to check out
            {
                //check front customer's balance and bill
                double custCash = safeway.cashiers[i].front().getCash();
                double custBill = safeway.cashiers[i].front().getBill();
                string n1 = safeway.cashiers[i].front().getName();
                cout << "Lane #" << i+1 << ": ";
                if (custCash < custBill)
                {
                    safeway.cashiers[i].front().adjustBill(custBill - custCash);
                    cout << "* Manager's action: *\n";
                    cout << "\tCustomer " << n1 << " is short on cash; items returned and "
                         << "bill reduced by $" << custBill - custCash << " to $"
                         << safeway.cashiers[i].front().getBill() << endl;
                }
                else
                {
                    cout << "Customer " << n1 << " checks out with bill $"
                         << custBill << " using cash on hand of $" << custCash << endl;
                    safeway.cashiers[i].pop_front();
                }
            }
                break;
            case 1: //new customer added to queue
                Customer t4 = getCustomer(names);
                safeway.cashiers[i].push_back(t4);
                cout << "Lane #" << i+1 << ": ";
                cout << "Added customer " << t4.getName() << " (bill: $"
                     << t4.getBill() << " cash: $" << t4.getCash() << ") to Lane "
                     << i+1 << endl;
            }
            cout << "Lane #" << i+1 << " new queue:\n";
            printLane(safeway.cashiers[i]);
        }
        opCount++;
    }

    return 0;
}

void printLane(deque<Customer> d)
{
    if (d.size() == 0) cout << "\t<empty>\n";
    else
        for (auto element : d)
            cout << "\t" << element.getName() << " (bill: $" << element.getBill()
                 << " cash: $" << element.getCash() << ")\n";
}

Customer getCustomer(array<string, SIZE> n)
{
    return Customer(n[rand() % n.size()],
                    rand() % (MAX_CASH - MIN_CASH + 1) + MIN_CASH,
                    rand() % (MAX_BILL - MIN_BILL + 1) + MIN_BILL);
}
