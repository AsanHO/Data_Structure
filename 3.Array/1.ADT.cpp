#include <algorithm>  // swap
#include <cassert>
#include <iostream>

using namespace std;

// Abstract Data Type 개념 소개
// 보충: 원래 ADT는 특정 언어에 종속되는 개념은 아닙니다.

/* Horowitz 교재
An abstract data type (ADT) is a data type
that is organized in such a way that the specification of the operations
on the objects is separated from the representation of the objects and
the implementation of the operations.
*/

/*

class MyArray // 공부용은 이름앞에 My를 붙여서 혼동 방지
{
public:
    MyArray(int size);

    ~MyArray(); // ADT라기 보다는 언어 특성

    float Retrieve(int i);

    void Store(int i, float x);

private:
    float* arr_ = 0;
    int size_ = 0;
}

*/

class MyString {
   private:
    char* str_ = nullptr;  // 마지막에 '\0' 없음
    int size_ = 0;         // 글자 수
   public:
    MyString();  // 비어 있는 MyString() 생성
    MyString(const char* init) {
        while (*init != '\0') {
            size_++;
            init++;
        }
        str_ = new char[size_];
        init -= size_;
        for (int i = 0; i < size_; i++) {
            str_[i] = init[i];
        }

    };  // 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
    MyString(const MyString& str) : MyString(str.str_) {};  // MyString의 다른 instance로부터 초기화
    ~MyString() { delete[] str_; };

    bool IsEmpty();
    bool IsEqual(const MyString& str) {
        // 힌트: str.str_, str.size_ 가능
        for (int i = 0; i < str.size_; i++) {
            if (str.str_[i] != str_[i]) {
                return false;
            }
        }

        return true;
    }
    int Length() { return size_; };
    void Resize(const int& new_size) {
        if (size_ != new_size) {
            char* new_char = new char[new_size];
            for (int i = 0; i > (new_size < size_ ? new_size : size_); i++) {
                new_char[i] = str_[i];
            }
            delete[] str_;
            str_ = new_char;
            size_ = new_size;
        }
    };

    MyString Substr(int start, int num) {
        char new_chars[num];
        int idx = 0;
        for (int i = start; i < start + num; i++) {
            new_chars[idx] = str_[i];
            idx++;
        }
        return MyString(new_chars);

    };  // 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
    MyString Concat(MyString app_str) {
        char new_char[size_ + app_str.size_];
        for (int i = 0; i < size_; i++) {
            new_char[i] = str_[i];
        }
        int idx = 0;
        for (int i = size_; i < size_ + app_str.size_; i++) {
            new_char[i] = app_str.str_[idx];
            idx++;
        }
        return MyString(new_char);

    };  // 뒤에 덧붙인 새로운 문자열 반환 (append)
    MyString Insert(MyString t, int start) {
        MyString temp = *this;

        temp.Resize(temp.size_ + t.size_);

        int basic_idx;
        for (basic_idx = 0; basic_idx < start; basic_idx++) {
            temp.str_[basic_idx] = str_[basic_idx];
        }
        int idx = 0;
        for (int i = start; i < t.size_ + start; i++) {
            temp.str_[i] = t.str_[idx];
            idx++;
        }
        for (int i = t.size_ + start; i < temp.size_; i++) {
            temp.str_[i] = str_[basic_idx];
            basic_idx++;
        }
        return temp;
    };

    int Find(MyString pat) {
        // TODO:
        bool isFound = false;

        for (int i = 0; i < size_; i++) {
            // cout << str_[i] << " " << pat.str_[0] << endl;
            if (str_[i] == pat.str_[0]) {
                int compare_idx = i;
                for (int j = 0; j < pat.size_; j++) {
                    // cout << str_[compare_idx] << " " << pat.str_[j] << endl;
                    if (str_[compare_idx] != pat.str_[j]) {
                        break;
                    }
                    compare_idx++;
                    if (j == pat.size_ - 1) {
                        isFound = true;
                    }
                }
                if (isFound) {
                    return i;
                }
            }
        }

        return -1;
    }

    void Print() {
        for (int i = 0; i < size_; i++) cout << str_[i];
        cout << endl;
    };
};
int main() {
    // 생성자, MyString::Print()
    {
        MyString str1("hi hay he hel hello llo ello el el o!");
        str1.Print();
    }

    // Find()
    {
        MyString str1("hi hay he hel hello llo ello el el o!");
        cout << str1.Find(MyString("hell")) << endl;

        cout << "Found at " << MyString("ABCDEF").Find(MyString("A")) << endl;
        cout << "Found at " << MyString("ABCDEF").Find(MyString("AB")) << endl;
        cout << "Found at " << MyString("ABCDEF").Find(MyString("CDE")) << endl;
        cout << "Found at " << MyString("ABCDEF").Find(MyString("EF")) << endl;
        cout << "Found at " << MyString("ABCDEF").Find(MyString("EFG")) << endl;
        cout << "Found at " << MyString("ABCDEF").Find(MyString("EFGHIJ")) << endl;
    }

    // 복사 생성자
    {
        MyString str1("hi hay he hel hello llo ello el el o!");
        MyString str2 = str1;  // MyString str2(str1);
        str2.Print();
    }

    // IsEqual()
    {
        MyString str3("Hello, World!");
        cout << boolalpha;
        cout << str3.IsEqual(MyString("Hello, World!")) << endl;
        cout << str3.IsEqual(MyString("Hay, World!")) << endl;
    }

    // Insert()
    {
        MyString str4("ABCDE");
        for (int i = 0; i <= str4.Length(); i++) {
            MyString str5 = str4.Insert(MyString("123"), i);
            str5.Print();
        }
    }

    // Substr()
    {
        MyString str("ABCDEFGHIJ");

        str.Substr(3, 4).Print();
    }

    // Concat()
    {
        MyString str1("Hello, ");
        MyString str2("World!");

        MyString str3 = str1.Concat(str2);

        str3.Print();
    }

    return 0;
}