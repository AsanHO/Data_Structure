/*
3.binary_search.cpp
*/

#include <iostream>
#include <numeric>
using namespace std;
// 321

int main() {
    int arr[101];
    iota(arr, arr + 101, 1);
    int target = 77;

    int left = 0;
    int right = 100;
    int target_idx;
    int test = 0;
    while (true) {
        int compare = arr[(left + right) / 2];
        cout << compare << endl;
        if (target == arr[compare]) {
            target_idx = compare;
            break;
        }
        if (target > arr[compare]) {
            left = (left + right) / 2;
        } else {
            right = (left + right) / 2;
        }
        cout << left << " " << right << endl;
        test += 1;
        if (test == 10) break;
    }
    cout << target_idx << endl;
    return 0;
}