#include <iostream>
#include <string>
using namespace std;

class Car{
    private:
    // Private members protect the car's internal state from being modified directly outside the class.
    string Car_color, Car_model;
    int Car_year;
    bool Start;
    int moving;

    // Private functions control internal car operations. They can only be called from within the class.
    void carStart(){
        Start = 1;
        cout << Car_model << "'s engine starts.\n";
    }
    void carStop(){
        Start = 0;
        cout << Car_model << "'s engine has been turned off.\n\n";
    }
    void moveForward(){
        if (Start){
            if (moving == 0){
                cout << Car_model << "'s moves forward.\n";
                moving = 1;
            }else if(moving == 1){
                cout << Car_model << "'s moves faster.\n";
                moving = 2;
            }else if(moving == 2){
                cout << Car_model << "'s speed does not change. It is already at max speed.\n";
            }
        } else {
            cout << Car_model << " stays still. Start the Car!\n";
        }
    }
    void brake(){
        if (Start){
            if (moving == 1){
                cout << Car_model << "'s slows to a halt.\n";
                moving = 0;
            }else if(moving == 2){
                cout << Car_model << "'s moves slower.\n";
                moving = 1;
            }
        } else {
            cout << Car_model << " stays still. Car wasn't moving.\n";
        }
    }
    public:
    // Public constructor initializes each Car object.
    Car(string color, string model, int year){
        Car_color = color;
        Car_model = model;
        Car_year = year;
        cout << "The car created is "<< year << " " << color << " " << model << "\n";
        Start = 0;
        moving = 0;

    }

    void turnKey(){
        if (!Start){
            carStart(); 
        }else if(Start && !moving){
            carStop();
        }else{
            cout << "Stop the Car before turning the key!!";
        }
    }
    void accelerate(){
        moveForward();
    }
    void decelerate(){
        brake();
    }

    void display(){
        cout << "Your car is: "<< Car_year << " " << Car_color << " " << Car_model << "\n\n";
    }
};

int main(){
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";
    Car toyota("White", "Toyota", 2020), Mahindra("Black","Mahindra",2020);
    
    toyota.display();
    toyota.turnKey();
    toyota.accelerate();
    toyota.decelerate();
    toyota.turnKey();

    Mahindra.display();
    Mahindra.accelerate();
    Mahindra.turnKey();
    Mahindra.accelerate();
    Mahindra.decelerate();
    Mahindra.turnKey();

    return 0;
}