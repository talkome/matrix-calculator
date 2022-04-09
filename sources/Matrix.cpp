/**
 * Matrix
 * @author talko
 * @date 01/04/2022
 */

#include "Matrix.hpp"
using namespace std;
using namespace zich;


double Matrix::get_size_of_mat() {
    double sum = 0;
    for (double i : data) {
        sum += i;
    }
    return sum;
}

 /**
       * -------------------
       * Calculate Operators
       * -------------------
       */

 // Plus
Matrix Matrix::operator+(const Matrix &M) {
     for (unsigned long i = 0; i < data.size(); ++i) {
         data[i] = data[i] + M.data[i];
     }

     return Matrix(data, mat_row, mat_col);
 }

Matrix Matrix::operator+() {
    return Matrix(data, mat_row, mat_col);
}

// Increase
Matrix Matrix::operator+=(const Matrix &M) {
    for (unsigned long i = 0; i < data.size(); ++i) {
        data[i] += M.data[i];
    }
    return *this;
}

Matrix Matrix::operator++() {
    for (double & i : data) {
        i += 1;
    }
    return *this;
}

// Minus
Matrix Matrix::operator-(const Matrix &M) {
    for (unsigned long i = 0; i < data.size(); ++i) {
        data[i] = data[i] - M.data[i];
    }
    return Matrix(data, mat_row, mat_col);
}

Matrix Matrix::operator-() {
    return Matrix(data, mat_row, mat_col);
}

// Reduce
Matrix Matrix::operator-=(const Matrix &M) {
    for (unsigned long i = 0; i < data.size(); ++i) {
        data[i] -= M.data[i];
    }
    return *this;
}

Matrix Matrix::operator--() {
    for (double & i : data) {
        i -= 1;
    }
    return *this;
}

// Multiply
Matrix Matrix::operator*(const Matrix& M) {
    for (unsigned long i = 0; i < data.size(); ++i) {
        data[i] = data[i] * M.data[i];
    }
    return *this;
}

Matrix Matrix::operator*(double scalar) {
    for (double & i : data) {
        i = i * scalar;
    }
    return *this;
}

Matrix zich::operator*(double scalar, Matrix &M) {
    for (double & i : M.data) {
        i = i * scalar;
    }
    return Matrix(M.data, M.mat_row, M.mat_col);
}

Matrix Matrix::operator*=(double scalar) {
    for (double & i : data) {
        i *= scalar;
    }
    return *this;
}

Matrix Matrix::operator*=(const Matrix &M) {
    for (unsigned long i = 0; i < data.size(); ++i) {
        data[i] *= M.data[i];
    }
    return *this;
}

/**
 * ------------------
 * Comparing Operator
 * ------------------
 */

bool Matrix::operator>(Matrix& M){
    return this->get_size_of_mat() > M.get_size_of_mat();
}

bool Matrix::operator>=(Matrix& M){
    return this->get_size_of_mat() >= M.get_size_of_mat();
}

bool Matrix::operator<(Matrix& M){
    return this->get_size_of_mat() < M.get_size_of_mat();
}

bool Matrix::operator<=(Matrix& M){
    return this->get_size_of_mat() <= M.get_size_of_mat();
}

bool Matrix::operator==(Matrix& M){
    return this->get_size_of_mat() == M.get_size_of_mat();
}

bool Matrix::operator!=(Matrix& M){
    return this->get_size_of_mat() != M.get_size_of_mat();
}

            /**
            * ------------------
            * Printing Operator
            * ------------------
            */

ostream& zich::operator<<(ostream &out, const Matrix& M){
    for (unsigned long i = 0; i < M.mat_row; ++i) {
        out << "[ ";
        for (unsigned long j = 0; j < M.mat_col; ++j) {
            out << M.data[i * size_t(M.mat_col) + j] << " ";
        }
        out << ']' << endl;
    }
    return out;
}
