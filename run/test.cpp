#include <iostream>
#include <string>

using namespace std;

class Emp {
    protected:
    int id; string n; float sal;

    public:
    Emp(int eId, string name, float salary) {
        id = eId; 
        n = name;
        sal = salary;
    }

    void display() {
        cout << "ID: " << id << endl
        << "Name: " << n << endl
        << "Salary: " << sal << endl;
    }
};

class pEmp : public Emp {
    float b;

    public:
    pEmp(int eId, string name, float salary, float bonus) : Emp(eId, name, salary) {
        b = bonus;
    }

    void display() {
        Emp::display();
        cout << "Bonus: " << b << endl;
        cout << "Total salary:" << (sal + b) << endl;
    }
};

class cEmp : public Emp {
    float hrs, r;

    public:
    cEmp(int eId, string name, float hours, float rate) : Emp(eId, name, 0) {
        hrs = hours; 
        r = rate;
    }

    void display() {
        Emp::display();
        cout << "Hours: " << hrs << endl;
        cout << "Rate: " << r << endl;
        cout << "Total salary: " << (hrs * r) << endl;
    }
};

int main() {
    pEmp p(101, "Arnav", 2587.85, 5122);
    p.display();

    cEmp c(102, "Ronaldo", 8, 550);
    c.display();

    return 0;
}