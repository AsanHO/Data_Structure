#pragma once

#include <stdint.h>

#include <cassert>

template <typename T>
class SinglyLinkedList {
   public:
    struct Node {
        T item = T();
        Node* next = nullptr;
    };

   protected:
    Node* first_ = nullptr;
    bool print_debug_ = false;

   public:
    SinglyLinkedList() {}

    SinglyLinkedList(const SinglyLinkedList& list) {
        // TODO: 연결 리스트 복사
        std::cout << "here" << std::endl;
        Node* temp = list.first_;
        while (temp) {
            PushBack(temp->item);

            temp = temp->next;
        }
    }

    ~SinglyLinkedList() { Clear(); }

    void Clear()  // 모두 지워야(delete) 합니다.
    {
        // TODO: 모두 삭제
    }

    bool IsEmpty() { return first_ == nullptr; }

    int Size() {
        int size = 0;

        Node* temp = first_;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }

        return size;
    }

    T Front() {
        assert(first_);

        return first_->item;
    }

    T Back() {
        assert(first_);
        Node* temp = first_;
        Node* target;
        while (temp) {
            target = temp;
            temp = temp->next;
        }
        return target->item;  // TODO: 수정
    }

    Node* Find(T item) {
        Node* pointer = first_;
        while (pointer) {
            if (pointer->item == item) return pointer;
            pointer = pointer->next;
        }
        return nullptr;
    }

    void InsertBack(Node* node, T item) {
        // TODO: 1 2 3 100 4 5
        Node* nextNode = node->next;
        Node* newNode = new Node{item, nextNode};
        node->next = newNode;
    }

    void Remove(Node* n) {
        assert(first_);

        // 하나 앞의 노드를 찾아야 합니다.
        // TODO:
        Node* pointer = first_;
        while (pointer) {
            if (pointer->next == n) {
                pointer->next = pointer->next->next;
                delete n;
                break;
            }
            pointer = pointer->next;
        }
    }

    void PushFront(T item) {
        // first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

        // if (first_ == nullptr) {
        // }
        // 새로운 노드 만들기
        // TODO:
        Node* temp = new Node{item, first_};
        // 연결 관계 정리
        // TODO:
        first_ = temp;
    }

    void PushBack(T item) {
        if (first_) {
            // TODO:
            Node* temp = first_;

            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node* newNode = new Node{item, nullptr};
            temp->next = newNode;
        } else {
            // TODO:
            std::cout << "PB : empty" << std::endl;

            first_ = new Node{item, nullptr};
        }
    }

    void PopFront() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopFront()" << endl;
            return;
        }

        assert(first_);

        // TODO: 메모리 삭제
    }

    void PopBack() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopBack()" << endl;
            return;
        }
        // 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.
        assert(first_);
        Node* temp = first_;
        Node* target;
        Node* nextLastNode;
        while (temp) {
            if (target) {
                nextLastNode = target;
            }
            target = temp;
            temp = temp->next;
        }
        // TODO: 메모리 삭제
        // std::cout << target->item << std::endl;
        // std::cout << nextLastNode->item << std::endl;
        nextLastNode->next = nullptr;
        delete target;
    }

    void Reverse() {
        // TODO:
        if (!first_) {
            return;
        }
        Node* a;
        Node* b;
        Node* c;
        a = first_;
        b = NULL;

        while (a != NULL) {
            c = b;
            b = a;
            a = a->next;
            b->next = c;
        }
        first_ = b;
    }

    void SetPrintDebug(bool flag) { print_debug_ = flag; }

    void Print() {
        using namespace std;

        Node* current = first_;

        if (IsEmpty())
            cout << "Empty" << endl;
        else {
            cout << "Size = " << Size() << " ";

            while (current) {
                if (print_debug_) {
                    // cout << "[" << current << ", " << current->item << ", " << current->next << "]";

                    // 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
                    cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", " << current->item << ", " << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
                } else {
                    cout << current->item;
                }

                if (current->next)
                    cout << " -> ";
                else
                    cout << " -> NULL";

                current = current->next;
            }
            cout << endl;
        }
    }
};