
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace zich{
    class Matrix{
        private:
            vector<vector<double>> vec;
            int row;
            int col;

        public:
            Matrix();
            Matrix(vector<double> & vec, int row, int col);
            Matrix operator+(const Matrix& mat2) const; //return a new mat= mat+mat2
            Matrix operator+=(int scalar); //change the mat - mat += scalar 
            Matrix operator+() const; // Unary Operation
            Matrix operator-(const Matrix& mat2) const; // return a new mat=mat-mat2
            Matrix operator-=(int scalar); //change the mat - mat-=scalar
            Matrix operator-() const; // unary operation

            bool operator<(const Matrix& mat2) const ; //return true is mat1 < mat2
            bool operator>(const Matrix& mat2) const; //return true if mat1> mat2
            bool operator<=(const Matrix& mat2) const; //return true if mat1<= mat2
            bool operator>=(const Matrix& mat2) const; //return true if mat1>= mat2
            bool operator==(const Matrix& mat2) const; //return true if mat1== mat2
            bool operator!=(const Matrix& mat2) const; //return true if mat1!=mat2
            
            Matrix operator++(); // return a mat++
            Matrix operator--(); //return a mat--
            Matrix operator--(int num); //return a --mat
            Matrix operator++(int num); // return a ++mat
            
            Matrix operator*=(double scalar); //change the mat *=scalar
            Matrix operator*=(Matrix&  mat); //change the mat *=mat 

            friend Matrix operator*(double scalar,Matrix&  mat);   //change the mat=scalar*mat
            friend Matrix operator*(Matrix&  mat, double scalar);   // change the mat = mat*scalar

            Matrix operator*(const Matrix& mat2) const; // return a mew mat = mat*mat2

            friend ostream& operator<<(ostream& os,const Matrix &mat);// opreator output <<
            friend istream& operator>>(istream& os,const Matrix &mat); // operator input >>

    };

}
