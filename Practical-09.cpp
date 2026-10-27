#include <iostream>
#include <stack>
#include <string>
using namespace std;

template<class t>
class Stack {
    stack<t> s;
public:
    void push(t val) {
        s.push(val);
    }

    void pop() {
        if (!s.empty()) {
            cout << "Popped element: " << s.top() << "\n";
            s.pop();
        }
        else {
            cout << "Stack underflow.\n";
        }
    }

    void top() {
        if (!s.empty()) {
            cout << "Top element: " << s.top() << "\n";
        }
        else {
            cout << "Stack underflow.\n";
        }
    }

    void display() {
        if (s.empty()) {
            cout << "Stack empty.\n";
            return;
        }
        else {
            cout << "Elements of stack are (top -> bottom): ";
            stack<t> temp = s;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << "\n";
        }
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";

    cout << "Integer stack: ";
    Stack<int> a;
    a.pop();
    a.push(10);
    a.push(20);
    a.push(30);
    a.display();
    a.top();
    a.pop();
    a.display();
    
    cout << "\nFloat stack: ";
    Stack<float> b;
    b.top();
    b.push(1.5f);
    b.push(2.5f);
    b.push(3.5f);
    b.display();
    b.pop();

    cout << "\nString stack: ";
    Stack<string> c;
    c.push("Hello");
    c.push("World");
    c.display();
    c.pop();

    return 0;
}