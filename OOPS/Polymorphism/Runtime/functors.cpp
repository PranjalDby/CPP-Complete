// functors are classes in cpp that act as like a function. it overloads the operator();
#include<algorithm>
#include <iostream>
using namespace std;
class increment{
    public:
        int i;
        increment(int e){
            this->i = e;
        }
        //overloading operator function so that it can be called on objects of increment
        int operator()(int toadd){
            return i + toadd;
        }
};
int main()
{
    int arr[] = {10, 20, 34, 45, 66};
    int n = sizeof(arr)/sizeof(0);
    increment i(4);
    i.i = i(5);
    cout << i.i << endl;
    transform(arr, arr + n, arr, increment(5));
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
        return 0;
}