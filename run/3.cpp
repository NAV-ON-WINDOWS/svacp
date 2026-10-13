// Design and implement a C++ program to demonstrate inheritance by
// creating a base class named Employee and derived classes such as
// PermanentEmployee and ContractEmployee. The base class should
// contain common employee details such as employee ID, employee
// name, and basic salary. The derived classes should override member
// functions to calculate and display the salary based on their respective
// pay structures. Create objects of the derived classes and demonstrate
// inheritance, function overriding, and code reusability by displaying the
// salary details of different types of employees.


#include <iostream>
#include <string>
using namespace std;

class Emp {
    protected:
        int id; string n; float bSal;

    public:
        Emp(int eId, string name, float basicSal) {
            id = eId; n = name; bSal = basicSal;
        }

        void display() {
            cout << "ID: " << id << endl;
            cout << "Name: " << n << endl;
            cout << "Basic Salary: " << bSal;
        } 
};

class pEmp : public Emp {
    float b;
    
    protected:
        pEmp(int eId, string name, float pSal, float bonus) : Emp(eId, name, bSal) {
            b = bonus;
        }

        void display() {
            Emp::display();
            cout << "Bonus: " << b << endl;
            cout << "Total Salary: " << (bSal + b) << endl;
        }
};

class cEmp : public Emp {
    float hrs, r;

    protected:
        cEmp(int eId, string name, float pSal, float hours, float rate) : Emp(eId, name, bSal) {
            hrs = hours; r = rate;
        }

        void display() {
            Emp::display();
            cout << "Hours: " << hrs << endl;
            cout << "Rate: " << r << endl;
        }
};

int main() {
    pEmp p(101, "Arnav", 50000, 50000);
    p.display();

    cEmp c(102, "Arnav", 8, 750);
    c.display();

    return 0;
}