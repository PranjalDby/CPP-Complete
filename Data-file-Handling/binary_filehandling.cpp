#include <iostream>
#include<fstream>
using namespace std;

int main(){

    fstream fout("binary2.dat", ios::out | ios::binary);

    // long int number;
    // cout << "enter your number = " << endl;
    // cin >> number;
    // if(fout.good()){
    //     // we need to cast the numbers to char * equi
    //     const char *data = reinterpret_cast<char *>(&number);
    //     fout.write(data, sizeof(long int));
    //     fout.close();
    //     fstream fin("binary.dat", ios::in | ios::binary);
    //     cout << "Readed data is = " << endl;
    //     long int *p = new long int();
    //     fin.read(reinterpret_cast<char*>(p),sizeof(long int));
    //     fin.close();
    //     cout << *p << endl;
    // }
    int n;
    cout << "Enter the size of an array: " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int *ptr;
    ptr = new int[n];
    fout.write(reinterpret_cast<char *>(arr), sizeof(int) * n); // writting 'n' elements to the file
    fout.close();
    fstream in("binary2.dat", ios::in | ios::binary);
    if(in){
        in.read(reinterpret_cast<char *>(ptr), sizeof(int) * n);
        in.close();
        cout << "Printing array:\n";
        for (int i = 0; i < n; i++)
        {
            cout << ptr[i] << " ";
        }
    }
    return 0;
}