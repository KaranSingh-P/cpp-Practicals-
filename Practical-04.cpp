#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Student {
    string name;
public:
    Student(string name) {
        this->name = name;
    }

    void display() {
        cout << "Name of Student: " << name << "\n";
    }

    ~Student() {
        cout << "Object destroyed: " << name << "\n";
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    { //Empty scope
        unique_ptr<Student> a = make_unique<Student>("Apple"); //This object is a resource uniquely owned.
        a->display();
    }
    cout << "The unique pointer and the its owned object gets destroyed upon leaving the scope.\n";

    {
        shared_ptr<Student> b;
        {
            shared_ptr<Student> c = make_shared<Student>("Banana");
            b = c; //The object owned by c is now also owned by b. Thus, it is a shared resource.
        }
        cout << "The object owned by the shared pointer does not get destroyed upon leaving the inner scope as one of the shared pointer is still alive, despite c being destroyed.\n";
    }
    cout << "The object now gets destroyed because all shared pointers related to the object are out of scope.\n";

    return 0;
}