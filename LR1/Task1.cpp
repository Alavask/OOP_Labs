#include <iostream>
#include <string>

//void IOCompileError() {
//    string input;
//    cin >> input;
//    cout << input << endl;
//}

void IOWithFullNamespace() {
    std::string input;
    std::cin >> input;
    std::cout << input << std::endl;
}

using namespace std;

void IOWithoutNamespace() {
    string input;
    cin >> input;
    cout << input << endl;
}

int main() {
    cout << "Test with namespace" << endl;
    IOWithFullNamespace();

    cout << "Test without namespace" << endl;
    IOWithoutNamespace();

    cout << "Uncomment next function to make CE" << endl;
    //IOCompileError();

    return 0;
}


