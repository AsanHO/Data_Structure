#include <iostream>

using namespace std;
// Declare isSorted function if not declared in a header
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

bool print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return true;
}

using namespace std;
// 321
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size + 1; i++) {
        int target_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                target_idx = j;
            }
        }
        if (i < target_idx) {
            int temp = arr[i];
            arr[i] = arr[target_idx];
            arr[target_idx] = temp;
        }

        print(arr, size);
        if (isSorted(arr, size)) {
            break;
        }
    }
    cout << "선택 정렬 완료" << endl;
}

int main() {
    for (int x = 1; x <= 3; x++) {
        for (int y = 1; y <= 3; y++) {
            for (int z = 1; z <= 3; z++) {
                int arr[3] = {x, y, z};
                selection_sort(arr, 3);
            }
        }
    }

    return 0;
}