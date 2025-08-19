#include <iostream>

#include "../../shared/SinglyLinkedList.h"

using namespace std;

int main() {
    SinglyLinkedList<int> list;

    list.SetPrintDebug(false);

    // list.PushBack(5);
    list.Print();
    list.PushFront(3);
    list.Print();
    list.PushBack(4);
    list.Print();
    list.PushFront(2);
    list.Print();
    list.PushFront(1);
    list.Print();
    list.PushBack(5);

    // 12345
    list.Print();

    // copy constructor
    {
        SinglyLinkedList<int> list2 = list;  // copy constructor
        list2.SetPrintDebug(false);
        list2.Print();
    }

    cout << "리버스" << endl;
    list.Reverse();
    list.Print();
    SinglyLinkedList<int> s1 = SinglyLinkedList<int>();
    SinglyLinkedList<int> s2 = SinglyLinkedList<int>();
    s2.PushBack(5);
    s1.Reverse();
    s1.Print();
    s2.Reverse();
    s2.Print();

    SinglyLinkedList<int>::Node* temp = list.Find(3);
    cout << temp->item << endl;
    list.InsertBack(temp, 1000);
    list.Print();

    list.InsertBack(temp, 50);
    list.Print();
    list.Remove(temp);
    list.Print();
    list.Print();
    cout << "PopFront()/Back() 테스트" << endl;
    for (int i = 0; i < 5; i++) {
        // list.PopFront();n
        // list.Print();
        list.PopBack();
        list.Print();
        if (!list.IsEmpty()) cout << list.Front() << " " << list.Back() << endl;
    }

    // // Edge case 테스트 주의

    return 0;
}
