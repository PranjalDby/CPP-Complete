#include<iostream>

using namespace std;

class Test{
    public:
        Test(){
            cout << "Constructor called\n";
        }
        ~Test(){
            cout << "Destructor called of class: " << this;
        }
};
int main()
{
    // when exception is thrown the scope of enclosing try-block or element's inside the try block got destroyed

    try{
        Test t;
        int res = 10;
        int d = 0;
        if (d == 0){
            throw "Zero";
        }
    }
    catch(const char *exp){
        cout << "\nZero division Error\n";
    }
}