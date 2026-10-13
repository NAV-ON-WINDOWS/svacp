#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Emp {
    int id; string name; float salary;

    public:
    void accept() {
        cout << "Id: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Salary: "; cin >> salary;
    }

    void display() {
        cout << "Id: " << id << endl
        << "Name: " << name << endl
        << "Salary: " << salary <<endl;
    }

    void writeToFile() {
        ofstream outFile("emp.txt", ios::app);

        if (!outFile) {
            cout << "Error: Can't find file."; return;
        }

        outFile << id << " " << name << " " << salary << "\n";
        outFile.close();
        
        cout << "Record inserted successfully."; return;
    }

    void readToFile() {
        ifstream inFile("emp.txt");

        if (!inFile) {
            cout << "No records found."; return;
        }

        Emp E;

        while(inFile >> E.id >> E.name >> E.salary) {
            E.display();
        }

        inFile.close();
    }

    void clearFile() {
        ofstream outFile("emp.txt", ios::trunc); // trunc wipes the file clean
        outFile.close();
        cout << "All records cleared.\n";
    }
};

int main() {
    int c;
    Emp E;

    E.clearFile();

    do {
        cout << "\n =====FILE MANAGEMENT PROGRAM===== \n";
        cout << "1. Enter records. \n";
        cout << "2. Display records. \n";
        cout << "3. Exit. \n";

        cout << "Enter operation: "; cin >> c;

        switch (c) {
            case 1:
                E.accept();
                E.writeToFile();
                break;
            
            case 2:
                E.readToFile();
            
            case 3:
                break;
            
            default:
                cout << "Invalid Operation."; break;
        }
    } while(c != 3);

    return 0;
}