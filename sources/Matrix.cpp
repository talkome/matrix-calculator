/**
 * Matrix
 * @author talko
 * @date 01/04/2022
 */

#include "Matrix.hpp"
using namespace std;
using namespace zich;

double Matrix::get_size() const{
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
     if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
         throw invalid_argument("The matrices are not the same size");
     }

     Matrix result = *this;
     for (unsigned long i = 0; i < M.data.size(); ++i) {
         result.data[i] = data[i] + M.data[i];
     }
     return result;
 }

Matrix Matrix::operator+() const{
    Matrix result(this->data, this->mat_row, this->mat_col);
    return result;
}

// Increase
Matrix Matrix::operator+=(const Matrix &M) {
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    for (unsigned long i = 0; i < M.data.size(); ++i) {
        data[i] += M.data[i];
    }
    return *this;
}

Matrix Matrix::operator++() {
    for (unsigned long i = 0; i < this->data.size(); ++i) {
        this->data[i] += 1;
    }
    return *this;
}

Matrix Matrix::operator++(const int i) {
    Matrix result = *this;
    for (unsigned long i = 0; i < this->data.size(); i++) {
        this->data[i] += 1;
    }
    return result;
}

// Minus
Matrix Matrix::operator-(const Matrix &M) {
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }

    Matrix result = *this;
    for (unsigned long i = 0; i < M.data.size(); ++i) {
        result.data[i] = data[i] - M.data[i];
    }

    return result;
}

Matrix Matrix::operator-() const{
    vector<double> new_data;
    new_data = this->data;
    for (unsigned long i = 0; i < new_data.size(); ++i) {
        if(new_data[i] != 0){
            new_data[i] *= (-1);
        }
    }
    Matrix result(new_data, this->mat_row, this->mat_col);
    return result;
}

// Reduce
Matrix Matrix::operator-=(const Matrix &M) {
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    for (unsigned long i = 0; i < data.size(); ++i) {
        data[i] -= M.data[i];
    }
    return *this;
}

Matrix Matrix::operator--() {
    for (unsigned long i = 0; i < this->data.size(); ++i) {
        this->data[i]--;
    }
    return *this;
}

Matrix Matrix::operator--(const int i) {
    Matrix result = *this;
    for (unsigned long i = 0; i < this->data.size(); i++) {
        this->data[i]--;
    }
    return result;
}

// Multiply
Matrix Matrix::operator*(const Matrix& M) {
    if(this->mat_col != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }

    vector<double> new_data;
    unsigned long new_size = size_t(this->mat_row * M.mat_col);
    new_data.resize(new_size);
    for (int i = 0; i < this->mat_row; i++){
        for (int j = 0; j < M.mat_col; j++){
            for (int k = 0; k < this->mat_col; k++){
                unsigned long sum = size_t(M.mat_col * i + j);
                new_data[sum] += this->data[size_t(this->mat_col * i + k)] * M.data[size_t(M.mat_col * k + j)];
            }
        }
    }

    Matrix result(new_data, this->mat_row, M.mat_col);
    return result;
}

Matrix Matrix::operator*(double scalar) {
    Matrix result = *this;
    for (unsigned long i = 0; i < result.data.size(); ++i) {
        result.data[i] = this->data[i] * scalar;
    }

    return result;
}

Matrix zich::operator*(double scalar, Matrix &M) {
    Matrix result = M;
    for (unsigned long i = 0; i < result.data.size(); ++i) {
        result.data[i] = M.data[i] * scalar;
    }
    return result;
}

Matrix Matrix::operator*=(double scalar) {
    for (unsigned long i = 0; i < this->data.size(); ++i) {
        this->data[i] *= scalar;
    }
    return *this;
}

Matrix Matrix::operator*=(const Matrix &M) {
    if(this->mat_col != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }

    vector<double> new_data;
    unsigned long new_size = size_t(this->mat_row * M.mat_col);
    new_data.resize(new_size);
    for (int i = 0; i < this->mat_row; i++){
        for (int j = 0; j < M.mat_col; j++){
            for (int k = 0; k < this->mat_col; k++){
                unsigned long sum = size_t(M.mat_col * i + j);
                new_data[sum] += this->data[size_t(this->mat_col * i + k)] * M.data[size_t(M.mat_col * k + j)];
            }
        }
    }

    this->data = new_data;
    this->mat_col = M.mat_col;
    return *this;
}

/**
 * ------------------
 * Comparing Operator
 * ------------------
 */

bool Matrix::operator>(const Matrix& M) const{
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    return this->get_size() > M.get_size();
}

bool Matrix::operator>=(const Matrix& M) const{
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    return this->get_size() >= M.get_size();
}

bool Matrix::operator<(const Matrix& M) const{
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    return this->get_size() < M.get_size();
}

bool Matrix::operator<=(const Matrix& M) const{
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    return this->get_size() <= M.get_size();
}

bool Matrix::operator==(const Matrix& M) const{
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    for (unsigned long i = 0; i < this->data.size(); ++i) {
        if (this->data[i] != M.data[i]){
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& M) const{
    if(this->mat_col != M.mat_col || this->mat_row != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }
    return !(*this == M);
}

            /**
            * ------------------
            * Printing Operator
            * ------------------
            */

ostream& zich::operator<<(ostream &out, const Matrix& M){
    for (unsigned long i = 0; i < M.mat_row; ++i) {
        out << "[";
        for (unsigned long j = 0; j < M.mat_col; ++j) {
            if(j != M.mat_col -1) {
                out <<  M.data[i * size_t(M.mat_col) + j] << " ";
            } else {
                out <<  M.data[i * size_t(M.mat_col) + j];
            }
        }
        out << ']' << endl;
    }
    return out;
}

istream& zich::operator>>(istream &in, const Matrix& M){
    string s;
    in >> s;
    stringstream test(s);
    string segment;
    vector<string> segments_list;
    vector<string> elements;
    vector<double> vec;

    int size = 1;
    while(getline(test, segment, ',')) {
        segments_list.push_back(segment);
        cout << segment << endl;
    }

    size = segments_list.size();
    for (unsigned long i = 0; i < size;i++){
        stringstream n(segments_list[i]);

        while(getline(n, segment, ' ')) {
            elements.push_back(segment);
        }

        for (unsigned long j = 0; i < elements.size();i++){
            vec.push_back(stod(elements[j]));
        }

        elements.clear();
    }

    int col = 1;
    int vec_size = (int) vec.size();

    if(size > 0 && vec_size > 0){
        if((vec_size / size) > 0) {
            col = vec_size/size;
        }
    } else {
        throw invalid_argument("invalid column");
    }

    Matrix result(vec,size,col);
    return in;
}