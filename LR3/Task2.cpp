#include <iostream>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))

int main2(){
    int num1;
    int num2;

    cout << "input two int:" << endl;
    cin >> num1 >> num2;
    cout << "min : " << min(num1, num2) << endl;

    double number1;
    double number2;

    cout << "input two double" << endl;
    cin >> number1 >> number2;
    cout << "min : " << min(number1, number2) << endl;

    char a;
    char b;

    cout << "input two char" << endl;
    cin >> a >> b;
    cout << "min : " << min(a, b) << endl;

    return 0;
}