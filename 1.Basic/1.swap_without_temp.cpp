#include <iostream>
using namespace std;
int main() {
    int a = 2;
    int b = 3;
    a = a + b;  // 5
    b = a - b;  // 2
    a = a - b;  // 3

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}