#include <iostream>
using namespace std;

void printMe(){
    cout << "Hello My name is Galvin..\n";
}
int main()
{
    int a = 10;
    auto func = [&]()
    {
        cout << "Hello world\n";
        return;
    };
    func();
    return 0;
}