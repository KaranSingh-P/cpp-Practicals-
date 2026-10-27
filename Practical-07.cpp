#include <iostream>
using namespace std;

void add(int a, int b) {
    cout << "Sum of " << a << "+" << b << " : " << a + b << "\n";
}

void add(double a, double b) {
    cout << "Sum of " << a << "+" << b << " : " << a + b << "\n";
}

class ComplexNumber {
    double real, imag;
public:
    ComplexNumber(double real = 0, double imag = 0) {
        this->real = real;
        this->imag = imag;
    }

    ComplexNumber operator+(const ComplexNumber& obj){
        return ComplexNumber(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
        cout << "\n";
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";

    add(1,2);
    add(3.5,7.2);

    ComplexNumber a(1, -2.9);
    cout << "\nComplex number a: ";
    a.display();

    ComplexNumber b(3.1, 0.5);
    cout << "Complex number b: ";
    b.display();

    ComplexNumber c = a + b;
    cout << "Complex number c: ";
    c.display();

    return 0;
}