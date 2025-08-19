#include <iostream>

#include "../../shared/SinglyLinkedList.h"

using namespace std;

struct Term {
    float coef;
    int exp;
};

class LinkedPolynomial : public SinglyLinkedList<Term> {
   public:
    typedef SinglyLinkedList<Term>::Node Node;

    void NewTerm(float coef, int exp) {
        // TODO:
        // 같은 항이 없을 때와 있을 때를 구분해야한다.
        if (SinglyLinkedList::IsEmpty()) {
            SinglyLinkedList::PushFront(Term{coef, exp});
            return;
        }
        if (SinglyLinkedList::Back().exp < exp) {
            SinglyLinkedList::PushBack(Term{coef, exp});
            return;
        }
        if (SinglyLinkedList::Front().exp > exp) {
            SinglyLinkedList::PushFront(Term{coef, exp});
            return;
        }
        // exp 바로 앞의 노드 확인,
        Node* temp = first_;
        Node* target;
        while (temp->item.exp < exp) {
            target = temp;
            temp = temp->next;
        }
        SinglyLinkedList::InsertBack(target, Term{coef, exp});
    }

    float Eval(float x) {
        float result = 0.0f;

        // TODO:
        Node* temp = first_;
        while (temp) {
            result += temp->item.coef * std::powf(x, float(temp->item.exp));
            temp = temp->next;
        }

        return result;
    }

    LinkedPolynomial Add(const LinkedPolynomial& poly) {
        // this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
        // 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

        LinkedPolynomial temp;

        Node* i = this->first_;
        Node* j = poly.first_;

        while (i && j) {
            if (i->item.exp == j->item.exp) {
                float sum = i->item.coef + j->item.coef;
                if (sum != 0.0f) {
                    temp.NewTerm(sum, i->item.exp);
                }
                i = i->next;
                j = j->next;
            } else if (i->item.exp > j->item.exp) {
                temp.NewTerm(j->item.coef, j->item.exp);
                j = j->next;
            } else {
                temp.NewTerm(i->item.coef, i->item.exp);
                i = i->next;
            }
        }
        while (i) {
            temp.NewTerm(i->item.coef, i->item.exp);
            i = i->next;
        }
        while (j) {
            temp.NewTerm(j->item.coef, j->item.exp);
            j = j->next;
        }
        return temp;
    }

    void Print() {
        bool is_first = true;  // 더하기 출력시 확인용

        if (IsEmpty()) cout << "비었어유" << endl;
        // TODO:
        Node* temp = first_;

        while (temp) {
            cout << temp->item.coef << "x^" << temp->item.exp << " ";
            temp = temp->next;
        }

        cout << endl;
    }

   private:
};

int main() {
    using namespace std;

    LinkedPolynomial p1;

    // exp가 작은 항부터 추가한다고 가정
    p1.NewTerm(1.0f, 0);  // 1 * x^0 = 1
    p1.NewTerm(1.5f, 1);  // 1.5 * x^1
    p1.NewTerm(2.0f, 2);  // 2 * x^2

    p1.Print();  // 1 + 1.5*x^1 + 2*x^2

    cout << p1.Eval(0.0f) << endl;  // 1 + 1.5*0 + 2*0^2 = 1
    cout << p1.Eval(1.0f) << endl;  // 1 + 1.5*1 + 2*1^2 = 4.5
    cout << p1.Eval(2.0f) << endl;  // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

    cout << endl;

    // Add() Test1
    cout << "Add() Test" << endl;
    {
        LinkedPolynomial p1;  // max_degree는 기본값으로 설정

        // exp가 작은 항부터 추가한다고 가정
        p1.NewTerm(1.0f, 0);
        p1.NewTerm(1.5f, 1);
        p1.NewTerm(2.0f, 2);

        p1.Print();  // 1 + 1.5*x^1 + 2*x^2

        LinkedPolynomial p2;

        // exp가 작은 항부터 추가한다고 가정
        p2.NewTerm(1.0f, 1);
        p2.NewTerm(3.0f, 2);
        p2.NewTerm(5.0f, 7);
        p2.NewTerm(2.0f, 11);

        p2.Print();  // 1*x^1 + 3*x^2 + 5*x^7 + 2*x^11

        cout << endl;

        LinkedPolynomial psum = p1.Add(p2);
        psum.Print();  // 1 + 2.5*x^1 + 5*x^2 + 5*x^7 + 2*x^11

        cout << endl;
    }

    // Add() Test2
    cout << "Add() Test2" << endl;
    {
        LinkedPolynomial p1;  // max_degree는 기본값으로 설정

        // exp가 작은 항부터 추가한다고 가정
        p1.NewTerm(1.0f, 0);
        p1.NewTerm(1.5f, 1);
        p1.NewTerm(2.0f, 2);
        p1.NewTerm(5.0f, 7);
        p1.NewTerm(3.5f, 10);
        p1.NewTerm(5.5f, 20);
        p1.NewTerm(5.0f, 1000);

        p1.Print();  // 1 + 1.5*x^1 + 2*x^2 + 5*x^7 + 3.5*x^10 + 5.5*x^20 + 5*x^1000

        LinkedPolynomial p2;

        // exp가 작은 항부터 추가한다고 가정
        p2.NewTerm(3.2f, 0);
        p2.NewTerm(1.0f, 1);
        p2.NewTerm(3.0f, 2);
        p2.NewTerm(2.0f, 11);

        p2.Print();  // 3.2 + 1*x^1 + 3*x^2 + 2*x^11

        cout << endl;

        LinkedPolynomial psum = p1.Add(p2);
        psum.Print();  // 4.2 + 2.5*x^1 + 5*x^2 + 5*x^7 + 3.5*x^10 + 2*x^11 + 5.5*x^20 + 5*x^1000

        cout << endl;
    }

    return 0;
}
