#include <iostream>
#include <string>
#include <memory>
using namespace std;

class weapons {
public:
    virtual void attack() = 0;
    virtual ~weapons() = default;
};

class sword : public weapons {
public:
    void attack() override {
        cout << "You attack using a sword.\n";
    }
};

class hammer : public weapons {
public:
    void attack() override {
        cout << "You attack using a hammer.\n";
    }
};

class weaponFactory {
public:
    static unique_ptr<weapons> chooseWeapon(const string& weapon) {
        if (weapon == "Sword") {
            return make_unique<sword>();
        }
        else if (weapon == "Hammer") {
            return make_unique<hammer>();
        }
        else {
            return nullptr;
        }
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";

    unique_ptr<weapons> a = weaponFactory::chooseWeapon("Sword");
    if (a) {
        a->attack();
    }
    unique_ptr<weapons> b = weaponFactory::chooseWeapon("Hammer");
    if (b) {
        b->attack();
    }

    return 0;
}