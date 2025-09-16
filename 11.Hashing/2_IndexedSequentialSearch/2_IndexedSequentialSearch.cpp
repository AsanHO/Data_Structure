#include <iostream>

using namespace std;

int SequentialSearch(int arr[], int start, int stop, int x) {
    for (int i = start; i < stop; i++) {
        if (arr[i] == x) return i;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 8, 13, 22, 45, 55, 75, 88};
    /*
    1 was found at 0 (0,3)
    2 was found at 1 (0,3)
    8 was found at 2 (0,3)
    13 was found at 3 (3,6)
    22 was found at 4 (3,6)
    45 was found at 5 (3,6)
    55 was found at 6 (6,9)
    75 was found at 7 (6,9)
    88 was found at 8 (6,9)
    */
    int n = sizeof(arr) / sizeof(arr[0]);

    int keys[] = {1, 13, 55};
    int kn = sizeof(keys) / sizeof(keys[0]);

    int indices[] = {0, 3, 6, n};  // 마지막에 n 하나 더 추가

    for (int x : {1, 2, 8, 13, 22, 13, 45, 55, 75, 88, 99, -1, 47, 101, 1000, 7, 10, 50, 60}) {
        if (x < arr[0] || x > arr[n - 1])
            cout << x << " was not found" << endl;
        else {
            // TODO:
            int start = 0;
            for (; start < kn - 1; start++) {
                // 51 => 6 9
                if (keys[start] <= x && x < keys[start + 1]) {
                    break;
                }
            }

            cout << x << " was founded at " << SequentialSearch(arr, indices[start], indices[start + 1], x) << endl;
        }
    }

    return 0;
}
