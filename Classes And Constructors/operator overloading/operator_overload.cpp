#include <iostream>
using namespace std;

class Complex{
    private:
        float real, imag;

    public:

        Complex() : real(0), imag(0) {};
        Complex(float r,float i) {
            real = r;
            i = imag;
        }
        //freind function 
        //overload binary + operator
        friend Complex operator+(const Complex &obj1,const Complex &obj2){
            Complex res;
            res.real = obj1.real + obj2.real;
            res.imag = obj1.imag + obj2.imag;
            return res;
        }
        // basic to class type;
        friend Complex operator+(Complex &obj1,int num)
        {
            Complex res;
            res.imag = obj1.imag + num;
            res.real = obj1.real + num;
            return res;
        }
    
        void display(){
            if(imag < 0){
                cout << "Complex Number: " << real << imag << "i";
            }
            else{
                cout << "Complex Number: " << real << "+" << imag;
            }
        }
};
class Count{
    public:
        int count;
        Count() : count(0) {};
        //overloading ++
        void operator++(int){
            count+=1;
        }
        // Overloading prefix ++
        void operator++() {
            ++count;
        }
        void display(){
            cout << count;
        }

        //class to basic type
        operator int(){
            return count;
        }
};
int main()
{
    // Complex c1(2.0f, 3.4f);
    // Complex c2(1.0f, -3.4f);
    // // Complex result = c1 + c2;
    // c1 = c1 + 2;
    // c1.display();
    Count c1;
    c1++;
    ++c1;
    // c1.display();
    int c = c1;
    cout << c;
    return 0;
}