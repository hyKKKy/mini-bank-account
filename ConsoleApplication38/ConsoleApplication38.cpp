#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

class Account {
private:
    char* name;
    int number;
    int percent;
    double balance;
    double dollar_balance;
    double eur_balance;
    const int Dollar_NBU = 40;
    const int Eur_NBU = 45;
    static int count;
public:
    Account() : Account(nullptr, 0, 0) {
    }

    Account(char* value, int Number, double Balance) : percent(0), dollar_balance(0), eur_balance(0) {
        int len = strlen(value) + 1;
        name = new char[len];
        name = strcpy(name, value);
        number = Number;
        balance = Balance;
        count++;
    }

    Account(const Account& obj) : Account(obj.name, obj.number, obj.balance) {
    }

    ~Account() {
        delete[] name;
        count--;
    }

    bool CheckBalance() {
        return balance > 0 == 1;
    }

    static int GetCount() {
        return count;
    }

    void ChangeUserName(char* new_name) {
        delete[] name;
        int len = strlen(new_name) + 1;
        name = new char[len];
        name = strcpy(name, new_name);
    }

    void SetPercent(int value) {
        percent = value;
        std::cout << "You've set " << percent << "%" << std::endl;
    }

    void UsePercent() {
        if (CheckBalance()) {
            balance += (balance * percent) / 100;
        }
        else {
            balance += (balance * (percent + 1)) / 100;
        }
    }

    void Withdraw(double value) {
        balance -= value;
    }

    void Deposit(double value) {
        balance += value;
    }

    void ExchangeDol(int grn_sum) {
        if (balance < grn_sum) {
            std::cout << "Error!" << std::endl;
        }
        else {
            Withdraw(grn_sum);
            dollar_balance = grn_sum / Dollar_NBU;
        }  
    }

    void ExchangeEur(int grn_sum) {
        if (balance < grn_sum) {
            std::cout << "Error!" << std::endl;
        }
        else {
            Withdraw(grn_sum);
            eur_balance = grn_sum / Eur_NBU;
        }
    }

    double GetEurBalance() const {
        return eur_balance;
    }

    double GetDollarBalance() const {
        return dollar_balance;
    }

    double GetBalance() const {
        return balance;
    }

    int GetUserNumber() const {
        return number;
    }

    char* GetUserName() const {
        return name;
    }

    void Print() {
        std::cout << "Your balance is " << GetBalance() << " grn" << std::endl;
        std::cout << "Your balance is " << GetDollarBalance() << " $" << std::endl;
        std::cout << "Your balance is " << GetEurBalance() << " eur" << std::endl;
    }

    std::string GetBalanceInWords() const {
        return std::to_string(balance);
    }
};

int Account::count = 0;

int main() {
    char name[] = "Dmytro";
    char name2[] = "Ivan";

    Account acc1(name, 67381, 10000);

    Account acc2 = acc1;

    std::cout << acc1.GetUserName() << std::endl;
    acc1.Print();
    std::cout << std::endl;

    acc1.ChangeUserName(name2);

    std::cout << acc1.GetUserName() << std::endl;

    acc1.Deposit(5000);
    acc1.Print();
    std::cout << std::endl;
    system("pause");
    system("cls");

    acc1.SetPercent(5);
    acc1.UsePercent();
    acc1.Print();
    std::cout << std::endl;

    std::cout << "Your balance is " << acc1.GetBalanceInWords() << std::endl;

    system("pause");
    system("cls");

    acc1.ExchangeEur(4500);
    acc1.Print();
    std::cout << std::endl;

    acc1.ExchangeDol(8000);
    acc1.Print();
    std::cout << std::endl;

    system("pause");
    system("cls");

    acc2.Withdraw(3000);
    acc2.Print();
    std::cout << std::endl;

    std::cout << Account::GetCount() << std::endl;

    system("pause");
    system("cls");
}