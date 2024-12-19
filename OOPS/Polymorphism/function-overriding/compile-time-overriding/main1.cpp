#include<iostream>

using namespace std;


//early-binding or compile time binding

class Parent{
    public:
        void print_name(){
            cout << "Parent Name called\n";
        }
};
class child:public Parent{
    public:
        string name;
        child(string n){
            name = n;
        }
        void print_name(){
            cout << "derived class name = " << name << endl;
        }
};
class base{
    public:
        void display(){
            cout << "Displaying the method of Base class\n";
        }
        //making destructor dynamice so that it can be called at runtime to deallocates the memory not only itself but the memory of its child also.
         ~base() { cout << "Base class destructor\n"; }
};

class derived:public base{
    public:
        // overriding the base class display function
        // here override keyword tells the compiler that this function is overriden from parent class or declared as a virtual function;
        void display()
        {
            cout << "Base class display()\n";
        }
        ~derived() {
            cout << "Derived class destructor\n";
        };
};
int main()
{
    // child childp("Pranjal");
    // childp.print_name();
    base *ptr = new derived();
    ptr->display();
    delete ptr;
}