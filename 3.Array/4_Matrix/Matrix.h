#pragma once

class Matrix {
   private:
    float* values_ = nullptr;
    int num_rows_ = 0;
    int num_cols_ = 0;

   public:
    Matrix(int num_rows, int num_cols);

    Matrix(const Matrix& b);

    ~Matrix();

    void SetValue(int row, int col, float value);
    void SetValue1DemensionIdx(int idx, float value);
    float GetValue(int row, int col) const;
    float GetValue1DemensionIdx(int idx) const;

    Matrix Add(const Matrix& b);

    Matrix Transpose();

    void Print();
};
