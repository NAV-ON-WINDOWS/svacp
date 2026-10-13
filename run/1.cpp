// Design and implement a C++ program to create a class named Student
// with data members roll number, name, and marks. Implement
// member functions to accept the student details from the user and
// display the entered details. Create an object of the Student class and
// demonstrate the functionality by calling the member functions.

#include <iostream>
using namespace std;

class Student {
    private:
    int roll; string name; float marks;

    public:
    void accept() {
        cout << "Enter your Rollno.: "; cin >> roll;
        cout << "Enter your Name: "; cin >> name;
        cout << "Enter your Marks: "; cin >> marks; 
    }

    void display() {
        cout << "Rollno.: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student S;
    
    S.accept();
    S.display();

    return 0;
}