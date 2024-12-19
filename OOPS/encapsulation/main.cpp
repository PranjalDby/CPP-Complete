#include <iostream>
using namespace std;

//information hiding as well as data protection
class Car{
    int price;
    static int chassis_no;

    public:
        int capacity;
        string color;

        //accessing member variable using friend function
        friend void access_price(Car &obj);
        friend void set_price(Car &obj, int data);
};
void set_price(Car &obj1,int p){
    obj1.price = p;
}
void access_price(Car &obj){
    cout << "Chassis No = " << obj.chassis_no << endl;
    cout << "Price of car = " << obj.price << " Rs" << endl;
}
int Car::chassis_no = 2032;
int main()
{
    Car honda;
    set_price(honda, 12000000);
    access_price(honda);
    return 0;
}