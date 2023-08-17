#include <iostream>
#include <string>
#include <map>

class Wallet {
private:
    double balance;

public:
    Wallet() : balance(0.0) {}

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

int main() {
    std::map<std::string, Wallet> users;

    while (true) {
        std::cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;
            users[username] = Wallet();
            std::cout << "Account created successfully.\n";
        } else if (choice == 2) {
            std::string username;
            double amount;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            users[username].deposit(amount);
            std::cout << "Deposit successful.\n";
        } else if (choice == 3) {
            std::string username;
            double amount;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            if (users[username].withdraw(amount)) {
                std::cout << "Withdrawal successful.\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
        } else if (choice == 4) {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Balance: " << users[username].getBalance() << "\n";
        } else if (choice == 5) {
        	std::cout <<"Exiting Program....\n"; 
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
