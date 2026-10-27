#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    // Protected members can be accessed within this class and its derived classes.
    string name;
    int age;
public:
    Person() {
        name = "";
        age = 0;
    }

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

// Student publicly inherits from Person.
class Student : public Person {
protected:
    string Id, course;
public:
    Student() {
        this->name = "";
        this->age = 0;
        this->Id = "";
        this->course = "";
    }

    Student(string name, int age, string Id, string course) {
        this->name = name;
        this->age = age;
        this->Id = Id;
        this->course = course;
    }

    void display() {
        Person::display();
        cout << "Id: " << Id << "\n";
        cout << "Course: " << course << "\n";

    }
};

// GraduateStudent publicly inherits from Student.
// This forms multilevel inheritance:
// Person -> Student -> GraduateStudent.
class GraduateStudent : public Student {
private:
    string research;
public:
    GraduateStudent(string name, int age, string Id, string course, string research) {
        this->name = name;
        this->age = age;
        this->Id = Id;
        this->course = course;
        this->research = research;
    }

    void display() {
        Student::display();
        cout << "Research Topic: " << research << "\n";
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    Person a("Apple", 2);
    a.display();
    cout << "\n";

    //Single Inheritance
    Student b("Banana", 12, "ABC123", "CSE");
    b.display();
    cout << "\n";

    //Multi-level Inheritance
    GraduateStudent c("Cherry", 12, "ABC123", "CSE", "Fruits");
    c.display();
    cout << "\n";

    return 0;
}