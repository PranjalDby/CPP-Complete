#include <iostream>
using namespace std;


class String{
    public:
        string value;
        String(){
            value = "";
        }
        //basic data type to class
        String operator+(int num){
            value = value + to_string(num);
            return *this;
        }

        friend int operator+(const String& str, int num);
        string operator*(int times){
            string res = "";
            for (int i = 0; i < times;i++){
                res += value;
            }
            return res;
        }
        String operator+(string other){
            value += other;
            return *this;
        }
        String operator=(string s){
            value += s;
            return *this;
        }
};
int operator+(int n,const String &str){
    int sum = stoi(str.value) + n;
    return sum;
}
class Test{
    int *pt;
    public:
        Test(){
            pt = new int;
        }
        void setV(int n){
            *pt = n;
        }
        Test& operator=(Test &t2){
            cout << "Operator called\n";
            if (this != &t2)
            {
                *(this->pt) = *(t2.pt);
            }
            return *this;
        }
        friend void display(Test &t1);
};
void display(Test &t1){
    cout << *(t1.pt) << endl;
}
int main()
{
    String s;
    s = "MultiVerse";
    s + " Pranjal";
    cout << "String is = " << s.value << endl;
    cout << "Class to basic type = \n";
    // int res = 33 + s;
    // cout << "Resultant = " << res << endl;

    cout << "Multiverse = " << (s * 45) << endl;
    Test t1;
    t1.setV(40);
    Test t2;
    t2 = t1;
    t1.setV(100);
    display(t2);
    return 0;
}