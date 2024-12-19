#include<iostream>
using namespace std;


//constructor overloading
class construct{
    public:
        float radii;
        //defualt contructor
        construct(){
            radii = 0;
        }
        //construct
        construct(float r):radii(r){
            cout << "constructor called\n";
        }
        //we can't overload static functiom
        // static float getArea(construct &c){
        //     return 3.14 * c.radii * c.radii;
        // }
        // float getArea(construct &c2){
        //     return 3.14 * c2.radii * c2.radii;
        //     ;
        // }
        void check(int = 0, int = 3);
};

// function that can't be overloaded
//function on differ with its return type
// int foo(){
//     return 10;
// }
// char foo(){
//     return 'f';
// }
int main()
{
    construct c(2.45);
    // cout << "Radii = " << r;
}