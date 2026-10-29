# cpp-Practicals
C++ programming practicals [1-12]

---
## Practical-01

### Objective

The objective of this practical is to understand the fundamentals of C++ programming by implementing basic arithmetic calculations, conditional logic, and input validation in a practical student assessment system.

### Chosen Problem Statement: 

Write a program that takes student's name and marks of three different subjects as input. The program should calculate the total marks and average, then check whether the student has passed. Add a remark for exceptional and failing students.

### Compile/Run instruction

**Step 1:** **Save the Program**

**Step 2:** **Compile the Program:** `g++ Practical-01.cpp -o student_marks`

**Step 3:** **Execute the Program:** `student_marks.exe`

OR

**Use the C/C++ Extension on VS code Editor.**

---
## Practical-02

### Question

Design and implement a class model for a real-world entity, such as a Vehicle or BankAccount, using private data members, public member functions, and a constructor.

### Theory

A class in C++ is a user-defined data type that combines data members and member functions into a single unit. It helps organise code and represent real-world entities.

#### Access Specifiers:

**Private:** Private members can be accessed directly only from within the class. They protect data from direct access or modification outside the class.
**Public:** Public members can be accessed from outside the class through objects. They allow users to interact with the class using member functions.

### Compile/Run instruction

**Step 1:** **Save the Program**

**Step 2:** **Compile the Program:** `g++ Practical-02.cpp -o vehicle`

**Step 3:** **Execute the Program:** `vehicle.exe`

OR

**Use the C/C++ Extension on VS code Editor.**

---
## Practical-03

### QUESTION

Implement a class that demonstrates default, parameterized, copy, and move constructors, and the Rule of Five.

### THEORY

Constructors are special member functions used to initialise objects in C++. Different types of constructors allow objects to be created and initialised in different ways.

* Default Constructor: Initialises an object without any arguments.
* Parameterized Constructor: Initialises an object using arguments passed during creation.
* Copy Constructor: Creates a new object by copying an existing object.
* Move Constructor: Transfers resources from one object to another without copying the resource.
* Copy Assignment Operator: Copies the contents of one existing object into another.
* Move Assignment Operator: Transfers resources from one existing object to another.
* Destructor: Releases allocated resources when an object is destroyed.

### RULE OF FIVE
The Rule of Five states that a class managing resources manually may need to define the following five special member functions:

* Destructor
* Copy constructor
* Copy assignment operator
* Move constructor
* Move assignment operator

These functions help manage resources safely, prevent memory leaks, and avoid issues such as double deletion.

### Compile/Run instruction

**Step 1:** **Save the Program**

**Step 2:** **Compile the Program:** `g++ Practical-03.cpp -o RuleFive`

**Step 3:** **Execute the Program:** `RuleFive.exe`

OR

**Use the C/C++ Extension on VS code Editor.**

---
## Practical-04

### QUESTION

Replace suitable raw new/delete usage with std::unique_ptr and std::shared_ptr. Compare behaviour and check for memory leaks.

### THEORY

RAII (Resource Acquisition Is Initialization) is a C++ programming technique in which resources are automatically acquired and released according to an object's lifetime. Smart pointers help manage dynamically allocated memory and reduce the need for manual memory management.

* std::unique_ptr: Manages an object with exclusive ownership. Only one unique_ptr can own the object at a time. The object is automatically destroyed when the pointer goes out of scope.
* std::shared_ptr: Allows multiple pointers to share ownership of the same object. The object is automatically destroyed when the last owning shared_ptr is released.
* RAII: Ensures that resources are released automatically when their owning objects are destroyed.
* Memory Leak: Occurs when dynamically allocated memory is not properly released and becomes inaccessible to the program.
* Valgrind/AddressSanitizer: Tools used to detect memory leaks and other memory-management errors.

### COMPILE/RUN INSTRUCTION
**Step 1:** **Save the Program**

**Step 2:** **Compile the Program:** `g++ -std=c++14 Practical-04.cpp -o SmartPointers`

**Step 3:** **Execute the Program:** `SmartPointers.exe`

**Step 4:** **Check for Memory Leaks:** Using Valgrind: `valgrind --leak-check=full ./SmartPointers`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-05

### QUESTION

Implement a university-management example using inheritance: Person → Student → GraduateStudent.

### THEORY

Inheritance is an object-oriented programming feature in C++ that allows a class to acquire the data members and member functions of another class. It promotes code reusability and helps establish relationships between classes.

* Base Class: A class whose members are inherited by another class. In this practical, Person is the base class.
* Derived Class: A class that inherits members from another class. Student inherits from Person, and GraduateStudent inherits from Student.
* Single Inheritance: Occurs when one derived class inherits from one base class, as in Person → Student.
* Multilevel Inheritance: Occurs when a class inherits from a derived class, forming a chain such as Person → Student → GraduateStudent.
* Constructors: Special member functions used to initialise objects when they are created.
* Display Functions: Member functions used to display the information stored in each class.

### COMPILE/RUN INSTRUCTION

**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ Practical-05.cpp -o Inheritance`

**Step 3: Execute the Program:** `Inheritance.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-06

### QUESTION

Create an abstract Shape class and implement Circle, Rectangle and Triangle with an area() function.

### THEORY

Polymorphism is an object-oriented programming feature in C++ that allows the same interface to perform different operations depending on the object involved.

* Abstract Class: A class that contains at least one pure virtual function. Objects of an abstract class cannot be instantiated directly.
* Virtual Function: A member function declared using the virtual keyword that allows the appropriate derived-class function to be called at runtime.
* Pure Virtual Function: A virtual function declared with = 0 that must be implemented by concrete derived classes to make them instantiable.
* Runtime Polymorphism: Allows a function call through a base-class pointer or reference to execute the overridden function of the actual derived object.
* Virtual Destructor: Ensures that the derived-class destructor is called correctly when an object is deleted through a base-class pointer.

### COMPILE/RUN INSTRUCTION
**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ Practical-06.cpp -o Polymorphism`

**Step 3: Execute the Program:** `Polymorphism.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-07

### QUESTION

Demonstrate function overloading and operator overloading using a Complex Number or Matrix class.

### THEORY

Compile-time polymorphism is an object-oriented programming feature in C++ that allows the same function name or operator to perform different operations depending on the arguments or operand types.

* Function Overloading: Allows multiple functions to have the same name but different parameter lists, such as add(int, int) and add(double, double). The compiler selects the appropriate function based on the arguments.
* Operator Overloading: Allows existing operators, such as +, to work with user-defined objects by defining their behaviour within a class.
* Complex Number Class: Represents a complex number using real and imaginary parts. Two complex numbers can be added by adding their real parts and imaginary parts separately.
* Compile-Time Polymorphism: The compiler determines which overloaded function or operator to use during compilation.
Runtime Polymorphism: The appropriate overridden virtual function is selected at runtime based on the actual derived object.

### COMPILE/RUN INSTRUCTION

**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ Practical-07.cpp -o Overloading`

**Step 3: Execute the Program:** `Overloading.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-08

### QUESTION

Implement either the Singleton or Factory design pattern in C++ and discuss its use case and trade-offs.

### THEORY

Design patterns are reusable solutions to common software design problems. They help organise code, improve maintainability, and provide a structured approach to object creation.

* Factory Design Pattern: A creational design pattern that provides a method for creating objects without requiring the calling code to construct the concrete classes directly.
* Abstract Base Class: A class that defines a common interface for derived classes. In this practical, the weapons class provides the attack() function.
* Derived Classes: The sword and hammer classes inherit from weapons and implement their own versions of the attack() function.
* Factory Class: The weaponFactory class creates and returns the appropriate weapon object based on the requested weapon type.
* Smart Pointers: The std::unique_ptr smart pointer manages the created objects automatically and releases their memory when they go out of scope.

### FACTORY DESIGN PATTERN

The Factory pattern is suitable for this example because the program needs to create different types of weapons based on the user's requested type.

* Weapons: An abstract base class that defines the common attack() interface.
* Sword: A derived class that implements the sword attack.
* Hammer: A derived class that implements the hammer attack.
* WeaponFactory: Creates and returns a Sword or Hammer object using the chooseWeapon() function.

### COMPILE/RUN INSTRUCTION

**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ -std=c++14 Practical-08.cpp -o FactoryPattern`

**Step 3: Execute the Program:** `FactoryPattern.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-09

### QUESTION

Write a generic Stack or Queue class using templates and test it with int, float and std::string values.

### THEORY

Templates are a feature of C++ that allows functions and classes to work with different data types without writing separate implementations for each type. They promote code reusability and reduce code duplication.

* Class Template: Allows a class to operate on different data types by using a template parameter, such as template <typename T>.
* Stack: A linear data structure that follows the Last In, First Out (LIFO) principle, meaning the last inserted element is removed first.
* Push Operation: Adds an element to the top of the stack.
* Pop Operation: Removes the top element from the stack.
* Top Operation: Accesses the top element without removing it.
* Empty Check: Determines whether the stack contains any elements.
* Exception Handling: Helps manage invalid operations, such as attempting to remove or access an element from an empty stack.

### TEST CASES

* Normal Operation: Push elements into the stack and display or remove the top element.
* Multiple Data Types: Test the stack using int, float and std::string values.
* Empty Stack: Check the behaviour when attempting to access or remove an element from an empty stack.
* Empty Check: Verify that empty() returns the correct result after all elements have been removed.

### COMPILE/RUN INSTRUCTION

**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ -std=c++11 Practical-09.cpp -o GenericStack`

**Step 3: Execute the Program:** `GenericStack.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-10

### QUESTION

Create a custom exception hierarchy and throw/catch specific exceptions in a banking transaction program.

### THEORY

Exception handling is a mechanism in C++ used to detect and handle runtime errors without abruptly terminating the program. It uses try, throw, and catch to manage exceptional situations.

* Custom Exceptions: User-defined exception classes that represent specific application errors, such as insufficient funds or invalid transaction amounts.
* std::exception: A standard base class for exceptions in C++. Custom exception classes can inherit from it and override the what() function to provide an error message.
* throw: Used to signal an exception when an error condition occurs.
* try: Contains code that may generate an exception.
* catch: Handles an exception thrown from a corresponding try block.
* InvalidAmount: A custom exception thrown when a withdrawal or transaction amount is zero or negative.
* InsufficientFunds: A custom exception thrown when the requested withdrawal exceeds the available account balance.

### COMPILE/RUN INSTRUCTION

**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ Practical-10.cpp -o Banking`

**Step 3: Execute the Program:** `Banking.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-11

### QUESTION

Implement a CSV reader/writer using fstream to store and retrieve student records. Demonstrate seekg(), seekp(), tellg() and tellp().

### THEORY

File handling in C++ allows data to be stored permanently in files and retrieved when required. The <fstream> library provides classes and functions to perform file input and output operations.

* fstream: A file stream class that supports both reading and writing operations.
* CSV (Comma-Separated Values): A simple text-based format in which fields are separated by commas. In this practical, student records contain an ID, name and marks.
* seekg(): Moves the input (get) position to a specified location in a file.
* seekp(): Moves the output (put) position to a specified location in a file.
* tellg(): Returns the current input position in the file.
* tellp(): Returns the current output position in the file.
* File Modes: Specify how a file is opened, such as ios::in for reading, ios::out for writing and ios::app for appending.
* Error Handling: Checks whether a file opened successfully and whether reading or writing operations completed correctly.

### COMPILE/RUN INSTRUCTION

**Step 1: Save the Program**

**Step 2: Compile the Program:** `g++ Practical-11.cpp -o CSVFileHandling`

**Step 3: Execute the Program:** `CSVFileHandling.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

---
## Practical-12

### QUESTION

Build a console-based Library Management System using C++. Apply OOP concepts, STL containers, exception handling and file handling to add, edit, search and list book records. Store and retrieve library records using a CSV file.

### THEORY

Object-Oriented Programming (OOP) in C++ allows programs to be organized using classes and objects. In this practical, a Library Management System is implemented to manage book records and their availability.

* Class: A user-defined data type that combines data and functions. The Library class manages book records and library operations.
* Structure (struct): The Book structure stores the title, author and availability of a book.
* Encapsulation: The Library class keeps its book records and helper functions private while providing public functions to perform library operations.
* Function Overloading: The Add() function is overloaded to add books with or without specifying the initial availability.
* STL (map): The map<int, Book> container stores book records indexed by their unique IDs.
* STL (vector): The vector<int> container temporarily stores matching book IDs during searches.
* Exception Handling: A custom InvalidInput class inherits from exception and is used to handle invalid console input through try, throw and catch.
* File Handling (fstream): The <fstream> library is used to read and write book records in Library.csv.
* CSV (Comma-Separated Values): A text-based format used to store book ID, title, author and availability as comma-separated fields.
* Input Validation: Book IDs must be non-negative, and book availability must be between 0 and 999. Invalid operations are handled with appropriate messages.
* Searching and Editing: Books can be searched by ID, author or title, and existing records can be edited or updated.
* Data Persistence: Existing records are loaded when the application starts, and updated records are saved to the CSV file when the user exits.

### COMPILE/RUN INSTRUCTION
**Step 1: Save the Program**

Save the source code as Practical-12.cpp and create an empty Library.csv file in the program's working directory if one does not already exist.

**Step 2: Compile the Program:** `g++ Practical-12.cpp -o LibraryManagement`

**Step 3: Execute the Program:** `LibraryManagement.exe`

OR

**Use the C/C++ Extension in VS Code Editor.**

Note: The program expects Library.csv to exist before execution. Book records are saved when option 8 (Exit) is selected.