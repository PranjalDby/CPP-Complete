#include<iostream>
using namespace std;

class Coin{
    int balance;
    int account_number;
    string nomineeName;

public:
    int curr_amount;
    Coin(int acc_no):curr_amount(0),account_number(acc_no){
        balance = 0;
    }
    void addAmount(int amount){
        balance += amount;
    }
    void addAmount(int amount,string name){
        nomineeName = name;
        balance += amount;
        cout << "Nominee Name " << name << " Added to your account\n"
             << "Amount added = " << amount << "\n"
             << "Current Balance = " << balance << endl;
    }
    int withDraw(int withdrawnAmount){
        int withdrawn = balance - withdrawnAmount;
        if (balance > withdrawnAmount && withdrawn >= 5000)
        {
            cout << "Withdrawn Successfully.\n"
                 << "Current Balance = " << (withdrawn) << endl;

            balance = withdrawn;
            return 0;
        }
        else{
            cout << "Not Enough Money Left.\n";
            return -1;
        }
    }
    void display(){
        cout << "Account Number = " << account_number << "\n"
            << "Nominee Name = " << nomineeName << "\n"
            << "Balance = " << balance << endl;
    }
};
int main(){
    Coin shader(12400237);
    shader.addAmount(45000);
    shader.withDraw(15000);
    shader.withDraw(15000);
    shader.withDraw(5000);
    shader.addAmount(50000, "Pranjal Dubey");
    shader.display();
}