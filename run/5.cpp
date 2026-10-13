#include <iostream>
using namespace std;

int main() {
    double n1, n2;

    cout << "Enter n1: "; cin >> n1;
    cout << "Enter n2: "; cin >> n2;

    try {
        if (n2 == 0) {
            throw  "Can't divide by 0 \n";
        }
    }

    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}

