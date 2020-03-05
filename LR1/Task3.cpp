#include <iostream>
#include <string>

using namespace std;

void ChangeArgument(string a) {
    a = "Argument changed!";
}

void ChangeReferenceArgument(string& a) {
    a = "Argument changed be reference!";
}

void ChangePtrArgument(string* a) {
    *a= "Argument changed be prt!";
}

int main() {
    string myArg = "Argument stay same";

    cout << "Try to change normal argument" << endl;
    ChangeArgument(myArg);
    cout << myArg << endl;

    cout << "Try to change reference argument" << endl;
    ChangeReferenceArgument(myArg);
    cout << myArg << endl;

    cout << "Try to change prt argument" << endl;
    string* ptrToArg = &myArg;
    ChangePtrArgument(ptrToArg);
    cout << myArg << endl;

    return 0;
}