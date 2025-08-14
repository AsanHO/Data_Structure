#pragma once

#include <cassert>
#include <iomanip>
#include <iostream>

#include "Queue.h"

// Double Ended Queue (덱, dequeue와 구분)
template <typename T>
class Deque : public Queue<T> {
    typedef Queue<T> Base;

   public:
    Deque(int capacity) : Queue<T>(capacity) {}

    T& Front() { return Base::Front(); }

    T& Back() { return Base::Rear(); }

    void PushFront(const T& item) {
        if (Base::IsFull()) Base::Resize();
        if (!Base::IsEmpty()) {
            for (int i = Base::rear_ + 1; i > Base::front_; i--) {
                Base::queue_[i] = Base::queue_[i - 1];
            }
        }

        Base::queue_[Base::front_ + 1] = item;
        std::cout << Base::queue_[Base::front_ + 1] << " 넣었다." << std::endl;
        Base::rear_++;
        Base::Print();
    }

    void PushBack(const T& item) { Base::Enqueue(item); }

    void PopFront() { Base::Dequeue(); }

    void PopBack() {
        assert(!Base::IsEmpty());

        // TODO:
        Base::queue_[Base::rear_] = '*';
        Base::rear_--;
    }

   private:
    // Queue와 동일
};
