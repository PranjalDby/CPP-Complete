#include <iostream>
#include<fstream>
using namespace std;

int main(){
    int n;
    cin >> n;

    cout << "Enter the array element: " << endl;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    fstream file1("sample.dat", ios::out | ios::binary);
    if (!file1) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    // putting the data into file;
    file1.write(reinterpret_cast<char*>(arr), n * sizeof(int));
    file1.close();

    file1.open("sample.dat", ios::in | ios::binary);
    if (!file1) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }
    int max = INT_MIN;
    int min = INT_MAX;
    int* readArr = new int[n];
    file1.read(reinterpret_cast<char*>(readArr), n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (max < readArr[i]) {
            max = readArr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (min > readArr[i]) {
            min = readArr[i];
        }
    }
    
    
    delete[] readArr;
    cout << "Max is = " << max << " Minimum is = " << min<< endl;
    return 0;
}