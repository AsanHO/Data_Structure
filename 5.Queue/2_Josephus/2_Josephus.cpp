#include <iostream>

#include "../../shared/Queue.h"

using namespace std;

int main() {
    int n = 4, k = 3;  // set n and k to the desired values

    Queue<int> q(n + 1);
    q.SetDebugFlag(true);

    // 처음에 n명 추가 (1, 2, ..., n)
    for (int i = 1; i <= n; i++) q.Enqueue(i);
    q.Print();

    // 마지막 한 명이 남을 때까지 반복
    while (q.Size() != 1) {
        // k-1 명은 맨 앞에서 뒤로 보내기
        for (int i = 0; i < k - 1; i++) {
            int survivor = q.Front();
            q.Dequeue();
            q.Enqueue(survivor);
        }

        // k 번째 사람 처형
        int victim = q.Front();
        q.Dequeue();
        cout << "Executed " << victim << endl;
        q.Print();
        cout << "size : " << q.Size() << endl;
    }

    // 최후의 생존자 번호
    cout << "Survivor: " << q.Front() << endl;

    return 0;
}