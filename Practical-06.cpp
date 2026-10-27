#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function makes Shape an abstract class.
    virtual void area() = 0;

    // Virtual destructor ensures proper cleanup of derived objects using base pointers.
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) {
        this->radius = radius;
    }

    void area() override {
        if (radius <= 0) {
            cout << "Invalid radius for circle.\n";
            return;
        }
        cout << "Area of circle: " << 3.14 * radius * radius << "m^2\n";
    }
};

class Triangle : public Shape {
private:
    double height, base;
public:
    Triangle(double height, double base) {
        this->height = height;
        this->base = base;
    }

    void area() override {
        if (height <= 0 || base <= 0) {
            cout << "Invalid dimensions for triangle.\n";
            return;
        }
        cout << "Area of Triangle: " << 0.5 * base * height << "m^2\n";
    }
};

class Rectangle : public Shape {
private:
    double height, width;
public:
    Rectangle(double height, double width) {
        this->height = height;
        this->width = width;
    }

    void area() override {
        if (height <= 0 || width <= 0) {
            cout << "Invalid dimensions for rectangle.\n";
            return;
        }
        cout << "Area of Rectangle: " << height * width << "m^2\n";
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    Circle a(2);
    Triangle b(4, 2);
    Rectangle c(10, 20);

    // Shape cannot be instantiated because it is abstract:
    // Shape s;  // Compilation error: area() is pure virtual.  

    Shape* ptrs[] = { &a, &b, &c };

    ptrs[0]->area();
    ptrs[1]->area();
    ptrs[2]->area();
}