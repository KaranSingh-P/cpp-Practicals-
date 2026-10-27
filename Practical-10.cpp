#include <iostream>
#include <exception>
using namespace std;

class InvalidAmount : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid amount! Amount must be greater than zero.";
    }
};

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "InsufficientFunds! Balance is too low.";
    }
};

class BankAccount {
    double balance;
public:
    BankAccount(double balance) {
        this->balance = balance;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }
        else if (amount > balance) {
            throw InsufficientFunds();
        }
        else {

            balance -= amount;
            cout << "Amount successfully withdrawn: " << amount << "\n";
        }
    }

    void showBalance() {
        cout << "Balance:  " << balance << "\n";
    }
};

int main() {
    cout << "Student name: Karan Singh\nURN: E25B000312\n\n";

    BankAccount account(1000);
    cout << "Initial ";
    account.showBalance();

    try {
        account.withdraw(200);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << "\n";
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << "\n";
    }
    account.showBalance();

    try {
        account.withdraw(2000);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << "\n";
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << "\n";
    }
    account.showBalance();

    try {
        account.withdraw(-200);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << "\n";
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << "\n";
    }
    account.showBalance();

    return 0;
}