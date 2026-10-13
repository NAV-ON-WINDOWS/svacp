// Design and implement a C++ program to create a class named
// BankAccount that stores account details such as account
// number, account holder name, and balance. Use a
// parameterized constructor to initialize the account details when
// an object is created and a destructor to indicate when an object is
// destroyed. Implement a static data member to maintain and
// display the total number of bank account objects created. Create
// multiple objects of the BankAccount class to demonstrate the
// working of constructors, destructors, and the static data member.

#include <iostream>
using namespace std;

class BankAccount {
    private:
    int no; string n; float b;
    static int count;

    public:
    BankAccount(int accno, string name, float balance) {
        no = accno; n = name; b = balance;
    }

    void display() {
        cout << "Account No.: " << no << endl;
        cout << "Name: " << n << endl;
        cout << "Balance: " << b << endl;
    }

    static void showCount() {
        count++;
        cout << "Total accounts created: " << count << endl;
    }

    ~BankAccount() {
        cout << "Constructor deleted sucessfully. \n"; return;
    }
};

int BankAccount::count = 0;

int main() {
    cout << "\n ===== BANK ACCOUNT DETAILS ===== \n";

    BankAccount B1(101, "Arnav", 7584.32);
    BankAccount B2(102, "Ronaldo", 22578.79);

    B1.display();
    B1.showCount();
    
    B2.display();
    B2.showCount();

    return 0;

}