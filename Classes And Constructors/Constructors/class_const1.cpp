#include <iostream>
using namespace std;


class Wall{
    public:
        int length,breadth;
        //if we can't define any constructor then default constructor is defined
        //2 nd parameterized constructor 
        Wall(int l,int b){
            length = l;
            breadth = b;
        }

        //copy constructor

        Wall(Wall &obj2){
            length = obj2.length;
            breadth = obj2.breadth;
        }
};
int main()
{
    //using copy constructor
    Wall w1(34, 56);
    Wall w2 = w1;
    cout << w2.length << " " << w2.breadth << endl;
    return 0;
}