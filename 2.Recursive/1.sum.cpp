#include <iostream>
using namespace std;
// 321
int get_sum_with_recursive(int x) {
    if (x == 0) {
        return 0;
    }
    return x + get_sum_with_recursive(x - 1);
}
int get_sum_with_recursive(int arr[], int size) {
    if (size == -1) return 0;
    int item = arr[size - 1];
    cout << item << endl;
    return item + get_sum_with_recursive(arr, size - 1);
};
int main() {
    cout << get_sum_with_recursive(10) << endl;
    int arr[10] = {1, 3, 2, 1, 2, 3, 4, 5, 7, 2};
    cout << get_sum_with_recursive(arr, 10) << endl;
    return 0;
}