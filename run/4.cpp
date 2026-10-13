#include <iostream>
using namespace std;

class Shape {
    public:
    Shape() {
        cout << "Constructor created." << endl;
    }

    virtual void area() {
        cout << "This is a method to calculate area." << endl;
    }
};

class Rect : public Shape {
    private:
    float l, b;

    public:
    Rect(float len, float bre) {
        l = len; b = bre;
    }

    void area() {
        int area = l * b;
        cout << "Area: " << area << endl;
    }
};

class Circle : public Shape {
    private:
    float r;

    public:
    Circle(float rad) {
        r = rad;
    }

    void area() {
        int area;

        area = 3.15 * r * r;
        cout << "Area: " << area << endl;
    }
};

int main() {
    Rect R(10, 5);
    Circle C(10);

    Shape* ptr;

    ptr = &R;
    ptr -> area();

    ptr = &C;
    ptr -> area();

    return 0;
}