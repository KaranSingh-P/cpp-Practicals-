#include <iostream>
using namespace std;

class Array{
    int* data;
    int size;
    public:
        // 1. Default Constructor: Initializes an empty array with no allocated memory.
        Array(){
            size = 0;
            data = nullptr;
        }

        Array(int n){
            if (n>0){
                size = n;
                data = new int[size]();
            }else{
                size = 0;
                data = nullptr;
            }
        }

        // 2. Copy Constructor: Creates a new object by performing a deep copy of another object. 
        // Allocates separate memory and copies each element.
        Array(const Array &obj){
            size = obj.size;
            if (size>0){
                data = new int[size]();
                for(int i=0; i<size; i++){
                    data[i] = obj.data[i];
                }
            } else {
                data = nullptr;
            }
        }

        // 3. Copy Assignment Operator: Copies the contents of one existing object into another.
        // Performs a deep copy so that both objects own separate memory.
        // Checks for self-assignment to avoid unnecessary operations.
        Array& operator=(const Array &obj){
            if (this != &obj){
                size = obj.size;
                int* newData = new int[size]();
                for(int i=0; i<size; i++){
                    newData[i] = obj.data[i];
                }
                delete[] data;
                data = newData;
            }
            return *this;
        }

        // 4. Move Constructor: Transfers ownership of the dynamically allocated array 
        // from the source object to the newly created object.
        // No new array is allocated and no elements are copied.
        // The source object is reset to a valid empty state.
        Array(Array&& obj){
            size = obj.size;
            data = obj.data;

            obj.size = 0;
            obj.data = nullptr;
        }

        // 5. Move Assignment Operator:
        // Transfers ownership of the array from an existing source
        // object to an existing destination object.
        // First releases the destination's old memory, then takes
        // ownership of the source's memory.
        // Self-move assignment is checked, and the source is reset.
        Array& operator=(   Array &&obj){
            if (this != &obj){
                delete[] data;
            
                size = obj.size;
                data = obj.data;

                obj.size = 0;
                obj.data = nullptr;
            }
            return *this;
        }

        ~Array(){
            delete[] data;
        }

        void fill(){
            cout << "Enter the elements of the array[" << size << "]: ";
            for (int i = 0; i<size; i++){
                cin >> data[i];
            }
        }

        void display(){
            cout << "Elements of the array: ";
            for (int i = 0; i<size; i++){
                cout << data[i] << " ";
            }
            cout << "\n";
        }
};

int main(){
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    Array a; //Default constructor

    Array b(5); //Parameterized constructor
    b.fill();
    b.display();

    Array c(b); //Copy constructor
    c.display();

    a = b; //Copy operator
    a.display();

    Array d(move(b)); //Move constructor
    d.display();

    Array e;
    e = move(c); //Move operator
    e.display();

    return 0;
}