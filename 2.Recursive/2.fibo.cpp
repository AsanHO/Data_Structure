#include <iostream>
using namespace std;
// 321
int fibo(const int& x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int a = 0;
    int b = 1;
    int next = 0;
    for (int i = 0; i < x; i++) {
        // cout << "a : " << a << "b : " << b << endl;
        next = a + b;
        a = b;
        b = next;
    }
    return a;
}

int fibo_reculsive(const int& x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    return fibo_reculsive(x - 1) + fibo_reculsive(x - 2);
}
int main() {
    for (int i = 0; i < 14; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < 14; i++) {
        cout << fibo(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 14; i++) {
        cout << fibo_reculsive(i) << " ";
    }
    cout << endl;
    return 0;
}