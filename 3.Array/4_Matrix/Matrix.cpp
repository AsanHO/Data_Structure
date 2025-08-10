#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols) {
    // TODO:
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    values_ = new float[num_rows_ * num_cols_];
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix& b) {
    // TODO:
    num_cols_ = b.num_cols_;
    num_rows_ = b.num_rows_;
    for (int i = 0; i < num_cols_ * num_rows_; i++) {
        values_[i] = b.GetValue1DemensionIdx(i);
    }
}

Matrix::~Matrix() {
    // TODO:
    delete[] values_;
}

void Matrix::SetValue(int row, int col, float value) {
    /*
    3x4일때,
    0 = 0,0
    1 = 0,1
    2 = 0,2
    3 = 0,3
    4 = 1,0
    5 = 1,1
    6 = 1,2
    7 = 1,3
    11 = 2,3
    */
    cout << row << col << num_cols_ * row + col << value << endl;
    values_[num_cols_ * row + col] = value;
}

void Matrix::SetValue1DemensionIdx(int idx, float value) {
    values_[idx] = value;
}

float Matrix::GetValue(int row, int col)
    const  // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    return values_[num_cols_ * row + col];
}
float Matrix::GetValue1DemensionIdx(int idx) const { return values_[idx]; };

Matrix Matrix::Transpose() {
    Matrix temp(num_cols_, num_rows_);  // num_cols_, num_rows_ 순서 주의

    // TODO:
    for (int r = 0; r < num_cols_; r++) {
        for (int c = 0; c < num_rows_; c++) {
            temp.SetValue(r, c, GetValue(c, r));
        }

        cout << endl;
    }

    return temp;
}

Matrix Matrix::Add(const Matrix& b) {
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Matrix temp(num_rows_, num_cols_);

    // TODO:
    for (int i = 0; i < num_cols_ * num_rows_; i++) {
        temp.SetValue1DemensionIdx(i,
                                   (values_[i] + b.GetValue1DemensionIdx(i)));
    }

    return temp;
}

void Matrix::Print() {
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++) cout << GetValue(r, c) << " ";

        cout << endl;
    }
}
