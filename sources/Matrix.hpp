/**
 * Matrix
 * @author talko
 * @date 01/04/2022
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

namespace zich {

    class Matrix {

    public:
        int mat_row, mat_col;
        vector<double> data;

        // Constructor
        Matrix(vector<double> &vec, int row, int col){
            if (row > 0){
                mat_row = row;
            }
            if (col > 0){
                mat_col = col;
            }
            if(mat_col * mat_row != vec.size()){
                throw invalid_argument("invalid data");
            } else {
                data = vec;
            }
        }

        Matrix(Matrix& other){
            if (other.mat_row > 0){
                mat_row = other.mat_row;
            }
            if (other.mat_col > 0){
                mat_col = other.mat_col;
            }
            data = other.data;
        }

        // Destructor
        ~Matrix(){};

        double get_size_of_mat();

        // Operators

        /**
         * -------------------
         * Calculate Operators
         * -------------------
         */

        // Plus
        Matrix operator+(Matrix const&);

        Matrix operator+();

        // Minus
        Matrix operator-(const Matrix&);

        Matrix operator-();

        // Add
        Matrix operator+=(const Matrix&);

        // Reduce
        Matrix operator-=(const Matrix&);

        // Multiply
        Matrix operator*=(const Matrix&);

        Matrix operator*=(double);

        // Increase by 1
        Matrix operator++();

        // Reduce by 1
        Matrix operator--();

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
        bool operator>(Matrix&);

        // Greater Equal
        bool operator>=(Matrix&);

        // Lower
        bool operator<(Matrix&);

        // Lower Equal
        bool operator<=(Matrix&);

        // Equal
        bool operator==(Matrix&);

        // Not Equal
        bool operator!=(Matrix&);

        // Output
        friend ostream& operator<<(ostream&, const Matrix&);

    };
}
