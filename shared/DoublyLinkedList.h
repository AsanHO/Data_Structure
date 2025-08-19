#pragma once

#include <stdint.h>

#include <algorithm>
#include <cassert>

template <typename T>
class DoublyLinkedList {
   public:
    struct Node {
        T item = T();

        Node* left = nullptr;
        Node* right = nullptr;

        // 참고: prev/next가 아니라 left/right
    };

   protected:
    Node* first_ = nullptr;

   public:
    DoublyLinkedList() {}

    ~DoublyLinkedList() { Clear(); }

    void Clear()  // 모두 지워야(delete) 합니다.
    {
        Node* ptr = first_;
        while (ptr) {
            Node* target = ptr;
            ptr = ptr->right;
            delete target;
        }
    }

    bool IsEmpty() { return first_ == nullptr; }

    int Size() {
        int size = 0;

        // TODO:
        Node* ptr = first_;
        while (ptr) {
            size++;
            ptr = ptr->right;
        }

        return size;
    }

    void Print() {
        using namespace std;

        Node* current = first_;
        Node* last;

        if (IsEmpty())
            cout << "Empty" << endl;
        else {
            cout << "Size = " << Size() << endl;

            cout << " Forward: ";
            // TODO:
            while (current) {
                cout << current->item << " ";
                if (current->right == nullptr) {
                    last = current;
                }
                current = current->right;
            }
            cout << endl;
            cout << "Backward: ";
            // TODO:
            while (last) {
                cout << last->item << " ";
                last = last->left;
            }
            cout << endl;
        }
    }

    Node* Find(T item) {
        Node* ptr = first_;
        while (ptr) {
            if (ptr->item == item) {
                return ptr;
            }
            ptr = ptr->right;
        }
        return nullptr;  // TODO:
    }

    void InsertBack(Node* node, T item) {
        if (IsEmpty()) {
            PushBack(item);
        } else {
            Node* nextNode = node->right;
            Node* newNode = new Node{item, node, nextNode};
            nextNode->left = newNode;
            node->right = newNode;
        }
    }

    void PushFront(T item) {
        // TODO:
        Node* newNode = new Node{item, nullptr, first_};
        if (IsEmpty()) {
            first_ = newNode;
            return;
        }
        first_->left = newNode;
        first_ = newNode;
    }

    void PushBack(T item) {
        // TODO:

        Node* newNode = new Node{item, nullptr, nullptr};
        if (IsEmpty()) {
            first_ = newNode;
        }
        Node* last = first_;
        while (last->right) {
            last = last->right;
        }
        newNode->left = last;
        last->right = newNode;
    }

    void PopFront() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopFront()" << endl;
            return;
        }

        assert(first_);

        // TODO:
    }

    void PopBack() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopBack()" << endl;
            return;
        }

        // 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

        assert(first_);
        assert(first_);
        Node* temp = first_;
        Node* target;
        Node* nextLastNode;
        while (temp) {
            if (target) {
                nextLastNode = target;
            }
            target = temp;
            temp = temp->right;
        }
        // TODO: 메모리 삭제
        // std::cout << target->item << std::endl;
        // std::cout << nextLastNode->item << std::endl;
        nextLastNode->right = nullptr;
        delete target;
        // TODO:
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
            a = a->right;
            b->left = a;
            b->right = c;
        }
        first_ = b;
    }

    T Front() {
        assert(first_);

        return first_->item;  // TODO:
    }

    T Back() {
        assert(first_);
        Node* ptr = first_;
        while (ptr->right) {
            ptr = ptr->right;
        }
        return ptr->item;
    }
};