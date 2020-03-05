#include <iostream>

using namespace std;

namespace real {
    int plus(int a, int b) {
        return a + b;
    }
}

namespace ring2 {
    int plus(int a, int b) {
        return (a + b) % 2;
    }
}

int main() {
    cout << "Try plus function from real" << endl;
    cout << "8+5=" << real::plus(8, 5) << endl;

    cout << "Try plus function from ring2" << endl;
    cout << "8+5=" << ring2::plus(8, 5) << endl;

    return 0;
}