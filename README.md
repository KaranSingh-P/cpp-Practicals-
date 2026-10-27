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

**Step 3:** **Execute the Program:** `Windows: SmartPointers.exe`

**Step 4:** **Check for Memory Leaks:** `Using Valgrind: valgrind --leak-check=full ./SmartPointers`

OR

**Use the C/C++ Extension in VS Code Editor.**
---