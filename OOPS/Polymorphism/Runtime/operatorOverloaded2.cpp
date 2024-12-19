#include <iostream>
using namespace std;

//conversion operator.

class Fraction{
    public:
        int n, d;
        Fraction(int n,int d){
            this->n = n;
            this->d = d;
        }
        //conversion operator so that is convert int to float
        operator float(){
            return (float)n / (float)d;
        }
};
class Circle{
    float radius;
    public:
    Circle(){
        radius = 0.0f;
    }
    Circle(float r) : radius(r) {};

    //Binary operator:non-static member function
    Circle operator+=(float value){
        radius += value;
        return *this;
    }
    // unary operator:non-static member: no parameter but compulsory int datatype is required;
    Circle operator++(int){
        radius += 1.0;
        return *this;
    }
    Circle operator--(int){
        radius -= 1;
        return *this;
    }
    //unary prefix operator
    Circle& operator++(){
        radius += 1;
        return *this;
    }
    void operator-(){
        radius *= -1;
    }
    void display()
    {
        cout << "Radius = " << radius << endl;
    }
};
class Rectangle{
    int l, b;
    public:
        Rectangle(){
            l = 0;
            b = 0;
        }
        Rectangle(int length,int breadth){
            l = length;
            breadth = breadth;
        }
        int getLength() const {
            return l;
        }

        void setLength(int length) {
            l = length;
        }

        int getBreadth() const {
            return b;
        }

        void setBreadth(int breadth) {
            b = breadth;
        }
        //binary operator
        // Rectangle operator+(int v);
        // Rectangle operator+(int v){
        //     l += v;
        //     b += v;
        //     return *this;
        // }
        // Rectangle operator+(Rectangle &obj){
        //     Rectangle res;
        //     res.l = obj.l + l;
        //     res.b = obj.b + b;
        //     return res;
        // }
        //using friend function
        friend void operator++(Rectangle &obj,int);
        friend Rectangle operator+(Rectangle &obj,int);
        int area()
        {
            return l * b;
        }
};
//overloading operator as non-member function
Rectangle operator+(Rectangle &r,int v){
    r.setLength(r.getLength() + v);
    r.setBreadth(r.getBreadth() + v);
    return r;
}
void operator++(Rectangle &ob,int){
    ob = ob + 1;
}
Rectangle operator+(Rectangle &r,Rectangle &r2){
    Rectangle r3;
    int b = r.getBreadth() + r2.getBreadth();
    r3.setBreadth(b);
    int l = r.getLength();
    r2.getLength();
    r3.setLength(l);
    return r;
}

int main()
{

    //     Fraction f(30, 45);
    //     float v = f;
    //     // cout << v;
    //     Circle cir;
    //     cir += 1;
    //     cir += 20.2;
    //     cir++;
    //     cir--;
    //     cir--;
    //     ++cir;
    //     -cir;
    // cir.display();
    Rectangle r,r2;
    r = r + 10;
    r = r + 20;
    r2 = r2 + 100;
    Rectangle r3;
    r3 = r + r2;
    r3++;
    cout << r3.area() << endl;
    return 0;
}