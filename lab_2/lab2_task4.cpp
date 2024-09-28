#include <iostream>
#include <string>

class Account {
public:
    int accountNumber;
    double balance;
    std::string customerName;

    Account(int accountNumber, double balance, const std::string& customerName) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->customerName = customerName;
    }

    virtual void deposit(double amount) {
        this->balance += amount;
        std::cout << "Balance deposited: " << amount << std::endl;
    }

    virtual void withdraw(double amount) {
        this->balance -= amount;
        std::cout << "Balance withdrawn: " << amount << std::endl;
    }

    void displayInfo() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Balance: " << balance << std::endl;
        std::cout << "Account Holder Name: " << customerName << std::endl;
    }

    // Overload comparison operators
    bool operator>(const Account& other) const {
        return this->balance > other.balance;
    }

    bool operator<(const Account& other) const {
        return this->balance < other.balance;
    }

    bool operator==(const Account& other) const {
        return this->balance == other.balance;
    }

    virtual ~Account() {} // Virtual destructor
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accountNumber, double balance, const std::string& customerName, double interestRate)
        : Account(accountNumber, balance, customerName), interestRate(interestRate) {}

    void deposit(double amount) override {
        double interest = interestRate * amount;
        Account::deposit(amount + interest); // Deposit with interest
        std::cout << "Interest earned: " << interest << std::endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            std::cout << "Can't withdraw money, insufficient balance." << std::endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accountNumber, double balance, const std::string& customerName, double overdraftLimit)
        : Account(accountNumber, balance, customerName), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            std::cout << "Can't withdraw money, exceeding overdraft limit." << std::endl;
        } else {
            balance -= amount; // Deduct amount from balance
            std::cout << "Balance withdrawn: " << amount << std::endl;
        }
    }
};

class InvestmentAccount : public Account {
private:
    int investmentDuration; 
    double riskFactor;      

public:
    InvestmentAccount(int accountNumber, double balance, const std::string& customerName, int investmentDuration, double riskFactor)
        : Account(accountNumber, balance, customerName), investmentDuration(investmentDuration), riskFactor(riskFactor) {}

    void deposit(double amount) override {
        if (amount > 0) {
            double profit = amount * riskFactor * investmentDuration / 12; // Monthly profit
            balance += amount + profit; // Add deposit and profit
            std::cout << "Deposited: " << amount << " with profit: " << profit << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            double loss = amount * riskFactor * investmentDuration / 12; 
            balance -= amount + loss; 
            std::cout << "Withdrawn: " << amount << " with loss: " << loss << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount." << std::endl;
        }
    }
};

int main() {
    // Create account objects
    Account* accounts[3];
    accounts[0] = new SavingsAccount(101, 1500.0, "Fatima", 0.05);
    accounts[1] = new CheckingAccount(102, 1000.0, "Amna", 200.0);
    accounts[2] = new InvestmentAccount(103, 2000.0, "Muhammad", 12, 0.03);

    // Perform operations
    for (int i = 0; i < 3; ++i) {
        accounts[i]->displayInfo();
        accounts[i]->deposit(500);
        accounts[i]->withdraw(200);
        accounts[i]->displayInfo();
        std::cout << "----------------------------------" << std::endl;
    }

    // Compare accounts
    if (*accounts[0] > *accounts[1]) {
        std::cout << "Savings account has a higher balance than checking account." << std::endl;
    } else if (*accounts[0] < *accounts[1]) {
        std::cout << "Checking account has a higher balance than savings account." << std::endl;
    } else {
        std::cout << "Both accounts have the same balance." << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete accounts[i];
    }

    return 0;
}
