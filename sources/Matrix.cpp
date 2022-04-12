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
    Matrix result(this->data, this->mat_row, this->mat_col);
    for (unsigned long i = 0; i < result.data.size(); ++i) {
        if(result.data[i] != 0){
            result.data[i] *= (-1);
        }
    }

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

Matrix Matrix::operator--(const int x) {
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
    unsigned long new_size = (unsigned long)this->mat_row * (unsigned long)M.mat_col;
    new_data.resize(new_size);
    for (unsigned long i = 0; i < this->mat_row; i++){
        for (unsigned long j = 0; j < M.mat_col; j++){
            for (unsigned long k = 0; k < this->mat_col; k++){
                unsigned long sum = (unsigned long)M.mat_col;
                unsigned long a = (unsigned long)this->mat_col;
                unsigned long b = (unsigned long)M.mat_col;
                new_data[sum*i+j] += this->data[a*i+k] * M.data[b*k+j];
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

Matrix zich::operator*(double scalar, Matrix& M) {
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

Matrix Matrix::operator*=(const Matrix& M) {
    if(this->mat_col != M.mat_row){
        throw invalid_argument("The matrices are not the same size");
    }

    vector<double> new_data;
    unsigned long new_size = (unsigned long)this->mat_row * (unsigned long)M.mat_col;
    new_data.resize(new_size);
    for (unsigned long i = 0; i < this->mat_row; i++){
        for (unsigned long j = 0; j < M.mat_col; j++){
            for (unsigned long k = 0; k < this->mat_col; k++){
                unsigned long sum = (unsigned long)M.mat_col;
                unsigned long a = (unsigned long)this->mat_col;
                unsigned long b = (unsigned long)M.mat_col;
                new_data[sum*i+j] += this->data[a*i+k] * M.data[b*k+j];
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
            out << M.data[i * (unsigned long)M.mat_col + j];
            if(j < M.mat_col -1){
                out << " ";
            }
        }
        out << "]";
        if(i < M.mat_row-1){
            out << '\n';
        }
    }

    return out;
}

istream& zich::operator>>(istream& in, Matrix& M){
    string input;

    getline(in,input);

    if (input[0] != '[' || input[input.length()-1] != ']' ){
        throw invalid_argument("Invalid Input");
    }

    vector<string> elements_list;
    stringstream stream1(input);

    while(stream1.good()) {
        string element;
        getline(stream1, element, ',');
        elements_list.push_back(element);
    }

    for(unsigned long i = 0; i < elements_list.size(); i++){
        string curr_elem = elements_list[i];
        string full_elem;

        if(i > 0){
            if (curr_elem[0] != ' ' || curr_elem[1] != '[' || curr_elem[curr_elem.length()-1] != ']'){
                throw invalid_argument("Invalid Input");
            }

            for (unsigned long j = 2; j < curr_elem.length()-1; j++){
                full_elem.push_back(curr_elem[j]);
            }

            elements_list[i] = full_elem;

        } else {
            if (curr_elem[0] != '[' || curr_elem[curr_elem.length()-1] != ']'){
                throw invalid_argument("Invalid Input");
            }

            for (unsigned long j = 1; j < curr_elem.length()-1; j++){
                full_elem.push_back(curr_elem[j]);
            }

            elements_list[i] = full_elem;
        }
    }

    int row = elements_list.size();
    vector<string> numbers_list;


    stringstream stream2(elements_list[0]);
    while(stream2.good()) {
        string number;
        getline(stream2, number, ' ');
        numbers_list.push_back(number);
    }

    int col = numbers_list.size();

    for(unsigned long i = 1; i < elements_list.size(); i++){
        stringstream stream3(elements_list[i]);
        while(stream3.good()) {
            string number;
            getline(stream3, number, ' ');
            numbers_list.push_back(number);
        }
    }

    int size = numbers_list.size();
    if(size != col * row){
        throw invalid_argument("Invalid InputA");
    }

    vector<double> new_data;
    new_data.resize((unsigned long)size);

    try {
        for (unsigned long i = 0; i < size; i++){
            double data = stod(numbers_list[i]);
            new_data[i] = data;
        }

    } catch(exception e){
        throw invalid_argument("Invalid Input");
    }

    Matrix new_matrix(new_data, row, col);
    return in;
}