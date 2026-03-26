#pragma once

class Matrix {
private:
    int rows;
    int cols;
    double* data;

public:
    Matrix(int r, int c);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    // Move Constructor - בנאי הזזה
    Matrix(Matrix&& other2) noexcept;
    Matrix();

    // Move Assignment Operator - אופרטור השמה בהזזה
    Matrix& operator=(Matrix&& other) noexcept;

    int getRows() const;
    int getCols() const;


    double& operator()(int row, int col);
    double operator()(int row, int col) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix hadamard(const Matrix& other) const;

    Matrix operator*(double scalar) const;
    Matrix operator+(double scalar) const;

    Matrix transpose() const;

    void randomize(double min, double max);
    void fillZero();

    void applyReLU();
    Matrix reluDerivative() const;

    bool operator==(const Matrix& other) const;
    void print() const;
};