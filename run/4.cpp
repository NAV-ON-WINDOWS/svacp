// Design and implement a C++ program to demonstrate runtime
// polymorphism by creating a base class named Employee with a
// virtual function to calculate and display salary details. Derive
// classes such as PermanentEmployee and ContractEmployee
// from the base class and override the virtual function to
// implement their respective salary calculations. Use a base class
// pointer to invoke the overridden functions at runtime, thereby
// demonstrating runtime polymorphism, function overriding,
// and code reusability in an employee management system.

#include <iostream>
#include <string>
using namespace std;

class Emp {
    protected:
    int id;
    string name;

    public:
    Emp(int eId, string eName) {
        id = eId;
        name = eName;
    }

    virtual void display() {
        cout << "ID: " << id << endl
        << "Name: " << name << endl;
    } 
};

class pEmp : public Emp {
    float salary, bonus;

    public:
    pEmp(int eId, string eName, float eSalary, float eBonus) : Emp(eId, eName) {
        salary = eSalary;
        bonus = eBonus;
    }

    void display() {
        cout << "\n -----Permanen Employee ----- \n";
        cout << "Id: " << id << endl
        << "Name: " << name << endl
        << "Total salary: " << (salary + bonus) << endl;
    }
};

class cEmp : public Emp {
    float hours, rate;

    public:
    cEmp(int eId, string eName, float hrs, float r) : Emp(eId, eName) {
        hours = hrs;
        rate = r;        
    }

    void display() {
        cout << "\n -----Contract Employee ----- \n";
        cout << "ID: " << id << endl
        << "Name: " << name << endl
        << "Hours: " << hours << endl
        << "Rate: " << rate << endl
        << "Total salary: " << (hours * rate) << endl;
    }
};

int main() {
    pEmp P(101, "Arnav", 51414, 1542);
    cEmp C(102, "Ronaldo", 9, 12154);

    Emp* ptr;
    
    ptr = &P;
    ptr -> display();

    ptr = &C;
    ptr -> display();

    return 0;
}