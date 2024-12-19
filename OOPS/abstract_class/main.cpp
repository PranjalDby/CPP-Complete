#include<iostream>

using namespace std;

class Shape{
    public:
        //pure-virtual functions
        string name;
        Shape(string n){
            name = n;
        };
        virtual void draw() = 0;
        //this creates an abstract class
};

class Sqaure:public Shape{
    public:
        int s;
        Sqaure(int s):Shape("Square"){
            this->s = s;
        }
        void draw(){
            cout << "Drawing\n";
            cout << "Area = " << s * s << endl;
        }
};
int main()
{
    Sqaure sq(20);
    Shape *s = &sq;
    s->draw();
    cout << "Name = " << s->name;
}