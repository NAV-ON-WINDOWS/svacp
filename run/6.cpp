#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Emp {
    private:
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
        << "Salary: " << salary << endl;
    }

    // writing to file 
    void writeToFile() {
        ofstream outFile("emp.txt", ios::app);

        if (!outFile) {
            cout << "Error: Couldnt find file."; return;
        }

        outFile << id << "" << name << "" << salary << "";
        outFile.close();
        cout << "File saved.";
    }

    void readFromFile() {
        ifstream inFile("emp.txt");

        if (!inFile) {
            cout << "No records found."; return;
        }

        Emp E;
        cout << "--------Records Retrieved from File--------";
        while (inFile >> E.id >> E.name >> E.salary) {
            E.display();
        }

        inFile.close();
    }
};

int main() {
    cout << "Run done.";
}