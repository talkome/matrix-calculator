/**
 * Matrix
 * @author talko
 * @date 01/04/2022
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

namespace zich {

    class Matrix {

    public:
        int mat_row, mat_col;
        vector<double> data;

        // Constructor
        Matrix(vector<double> vec, int row, int col){
            if (row <= 0){
                throw invalid_argument("Invalid Row");
            } else {
                mat_row = row;
            }

            if (col <= 0){
                throw invalid_argument("Invalid Column");
            } else {
                mat_col = col;
            }

            if(mat_col * mat_row != vec.size()){
                throw invalid_argument("invalid Data");
            } else {
                data = move(vec);
            }
        }

        Matrix(Matrix& other){
            mat_row = other.mat_row;
            mat_col = other.mat_col;
            data = other.data;
        }

        // Destructor
        ~Matrix(){};

        double get_size() const;

        // Operators

        /**
         * -------------------
         * Calculate Operators
         * -------------------
         */

        // Plus
        Matrix operator+(const Matrix&);

        Matrix operator+() const;

        // Minus
        Matrix operator-(const Matrix&);

        Matrix operator-() const;

        // Add
        Matrix operator+=(const Matrix&);

        // Reduce
        Matrix operator-=(const Matrix&);

        // Multiply
        Matrix operator*=(const Matrix&);

        Matrix operator*=(double);

        // Increase by 1
        Matrix operator++();

        Matrix operator++(const int);

        // Reduce by 1
        Matrix operator--();

        Matrix operator--(const int);

        // Multiply
        Matrix operator*(const Matrix&);

        Matrix operator*(double);

        friend Matrix operator*(double, Matrix&);

        /**
         * ------------------
         * Comparing Operator
         * ------------------
         */

        // Greater
        bool operator>(const Matrix&) const;

        // Greater Equal
        bool operator>=(const Matrix&) const;

        // Lower
        bool operator<(const Matrix&) const;

        // Lower Equal
        bool operator<=(const Matrix&) const;

        // Equal
        bool operator==(const Matrix&) const;

        // Not Equal
        bool operator!=(const Matrix&) const;

        // input
        friend ostream& operator<<(ostream&, const Matrix&);

        // Output
        friend istream& operator>>(istream&, const Matrix&);

    };
}
