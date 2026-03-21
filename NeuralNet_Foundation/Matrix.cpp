#include <iostream>
#include "Matrix.h"
#include <random>
#include <cmath> // For std::abs
Matrix:: Matrix(int r, int c): rows(r), cols(c) {
  data=new double[r*c];
    for (int i=0; i<r*c; i++) {
        data[i]=0.0;
    }

}
Matrix::Matrix(const Matrix& other) {
    rows=other.rows;
    cols=other.cols;
    int totalSize=rows*cols;
    data=new double[totalSize];
    for (int i = 0; i < totalSize; i++) {
        data[i] = other.data[i];
    }




}
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    if (rows != other.rows or cols != other.cols) {

        delete[] data;
        rows = other.rows;
        cols = other.cols;
        data = new double[rows * cols];
    }


    int total = rows * cols;
    for (int i = 0; i < total; i++) {
        data[i] = other.data[i];
    }

    return *this;
}
double& Matrix::operator()(int row, int col) {
    if (row >= rows || row < 0 || col >= cols || col < 0)  {
        throw std::out_of_range("Matrix index out of bnds!");
    }
    return data[row*cols+col];
}

double Matrix::operator()(int row, int col) const {
   if (row >= rows || row < 0 || col >= cols || col < 0)  {
        throw std::out_of_range("Matrix index out of bonds!");
    }


    return data[row * cols + col];
}
Matrix Matrix::operator+(const Matrix& other) const {
    if (other.rows!=rows or other.cols!=cols ) {
        throw std::invalid_argument("Addition failed: Matrix dimensions mismatch!");
    }
    Matrix sum_matrix=Matrix(other.rows,other.cols);
    int totalsize=0;
    totalsize=rows*cols;
    for (int i=0; i<totalsize; i++) {
        sum_matrix.data[i]=other.data[i]+data[i];
    }
    return sum_matrix;
}
Matrix Matrix::operator*(double scalar) const {
    int totalsize=0;
    totalsize=rows*cols;
    Matrix Scalar_product_matrix=Matrix(rows,cols);
    for (int i=0; i<totalsize; i++) {
        Scalar_product_matrix.data[i]=scalar*data[i];

    }
    return Scalar_product_matrix;

}
Matrix Matrix::operator*(const Matrix& other) const {

    if (this->cols != other.rows) {
        throw std::invalid_argument("Illegal multiplication: this->cols must equal other.rows.");
    }
    Matrix T=other.transpose();
    Matrix res(this->rows, other.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum=0;
            for (int k = 0; k < this->cols; k++) {
                sum += (*this)(i, k) * T(j,k);
            }
            res(i,j)=sum;


        }

    }

    return res;
}
void Matrix::applyReLU() {
    for (int i=0; i<this->rows*cols; i++) {
        if (data[i]<0.0) {
            data[i]=0.0;
        }
    }
}
Matrix Matrix::transpose() const {
    Matrix T=Matrix(cols,rows);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++ ) {
            T(j,i)=(*this)(i,j);
        }

    }
    return T;

}
Matrix::~Matrix() {
    delete[] data;
}
void  Matrix:: print() const {
for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
        std::cout << data[i*cols+j] << " ";
    }
    std::cout<<std::endl;
}
}
int Matrix::getRows() const {
    return rows;
}
int Matrix::getCols() const {
    return cols;
}
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Subtraction failed: Matrix dimensions mismatch!");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] - other.data[i];
    }

    return result;
}

Matrix Matrix::hadamard(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Hadamard failed: Matrix dimensions mismatch!");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows * other.cols; i++) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}
Matrix Matrix::operator+(double scalar) const {
    Matrix result(rows,cols);
    for (int i=0; i<rows*cols; i++) {
        result.data[i] = data[i] + scalar;
    }
    return result;
}
void Matrix::randomize(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min, max);
    for (int i=0; i<rows*cols; i++) {
        data[i] = dist(gen);
    }
}
void Matrix:: fillZero() {
    for (int i=0; i<rows*cols; i++) {
        data[i]=0.0;
    }
}
Matrix Matrix::reluDerivative() const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++) {
        if (data[i] > 0) {
            result.data[i] = 1.0;
        } else {
            result.data[i] = 0.0;
        }
    }

    return result;
}
bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    double epsilon = 1e-9;
    for (int i=0; i<other.rows*other.cols; i++) {
        if (std::abs(data[i] - other.data[i]) > epsilon) {
            return false;
        }

    }
    return true;
}