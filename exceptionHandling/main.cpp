#include<iostream>
using namespace std;

void throwAnyException(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = n;
    if(index > n){
        throw '0';
    }
    int a = 10;
    int divide = 0;
    if (divide == 0){
        throw "Zero Division Error.";
    }
}
int main(){
    int denominator = 0;
    // cout << "Enter denominator: ";
    // cin >> denominator;
    // try
    // {
    //     int numerator = 10;
       
    //     double res;
    //     if(denominator == 0){
    //         //throwing an exception to the catch block
    //         throw runtime_error("Zero Division Error\n");
    //         //after throw keyword below lines are become inaccessible
    //         cout << "Fuck you My project manager\n";
    //         ;
    //     }
    //     res = (double) numerator / denominator;
    //     cout << "Result after division: " << res << endl;
    // }
    // catch(runtime_error &e){

    //     cout << "Exception: " << e.what();
    // }

    //catch-all block demostration
    try{
        // throwAnyException();
            try{
                int res = -1 * 10;
                if(res < 0){
                    throw "negtive value";
                }
            }
            catch(const char *exp){
                cout << "Handle exception thrown by inner try-block\n: " << exp << "\n";
                cout << ((~6) + 3) << "\n";
            }

            throwAnyException();
    }
    catch(const char *exp){
        cout << "Handled exception thrown by outer try: " << exp << "\n";
    }
    catch(int x){
        //there is no implicit type conversion happend in exception - handling
        cout << "Index out of bound\n";
    }
    catch (...)
    {
        cout << "Handle all exception of any type\n";
    }
}