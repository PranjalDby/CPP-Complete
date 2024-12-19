#include<iostream>
using namespace std;


class Base{
    public:
        string name;
        Base(string n){
            name = n;
        }
        virtual void display(){
            cout << "Name in Base class = " << name << endl;
        }
};
class child :public Base{
    public:
        int roll_no;
        child(string n,int roll) : Base(n),roll_no(roll){}

        void display() override {
            cout << "Name of base  = " << name << " Roll no = " << roll_no << endl;
            ;
        }

};

/// @brief 
/// virtual table and vptr
/// @return 

class base2{
    public:
        void fun_1(){
            cout << "Base-1\n";
        }
        virtual void func_2(){
            cout << "base -2 \n";

        }
        virtual void func_3(){
            cout << "base - 3\n";
        }
        virtual void fun_4(int x = 40){
            cout << "base-4\n";
        }
};
class derived2:public base2{
    public:
        void fun_1(){
            cout << "DD\n";
        }
        void func_2(){
            cout << "DD2\n";
        }
        void fun_4(int x){
            cout << "Value of x= " << x << "\n";
        }
};
int main()
{
    base2 *ptr = new derived2();
    ptr->fun_1(); //early-binding because of non-virtual function
    ptr->func_2();
    // ptr->func_4(44); illegal,becuase of pointer is type of base class but function is of derived class.
    ptr->fun_4();
}