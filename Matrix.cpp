
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.hpp"


using namespace std;
namespace zich{
    Matrix::Matrix(){
        this->col = 1;
        this->row = 1;
    }
    Matrix::Matrix(vector<double> & vec, int row, int col){
        this->col = col;
        this->row = row;
    }
    Matrix Matrix::operator+(const Matrix& mat2){
        Matrix mat;
        return mat;
    }
    Matrix Matrix::operator+=(int scalar)const{
        Matrix mat;
        return mat;
    }
    Matrix Matrix::operator+(){
        Matrix mat;
        return mat;
    }
    Matrix Matrix::operator-(const Matrix& mat2){
        Matrix mat;
        return mat;
    }
    Matrix Matrix::operator-=(int scalar) const{
        Matrix mat;
        return mat;
    }
    Matrix Matrix::operator-(){  
        Matrix mat;
        return mat;
    }

    bool Matrix::operator<(const Matrix& mat2){
        return true;
    }
    bool Matrix::operator>(const Matrix& mat2){
        return true;
    }
    bool Matrix::operator<=(const Matrix& mat2){
        return true;
    }
    bool Matrix::operator>=(const Matrix& mat2){
        return true;
    }
    bool Matrix::operator==(const Matrix& mat2){
        return true;
    }
    bool Matrix::operator!=(const Matrix& mat2){
        return true;
    }

    Matrix Matrix::operator++() const{
        Matrix mat;
        return mat;
    }
    Matrix Matrix::operator--() const{
        Matrix mat;
        return mat;
    }

    Matrix Matrix::operator--(int num) const{
         Matrix mat;
        return mat;
    }
    
    Matrix Matrix::operator++(int num) const{
         Matrix mat;
        return mat;
    }
            
    Matrix Matrix::operator*=(double scalar) const{
        Matrix mat;
        return mat;
    }


    Matrix Matrix::operator*(const Matrix& mat2){
        Matrix mat;
        return mat;
    }

    Matrix operator*(double scalar, Matrix &mat){
        Matrix m;
        return m;   
    }

   istream& operator>>(istream& os,const Matrix &mat){ // operator input >>
        return os;
    }
    
    ostream& operator<<(ostream& os,const Matrix &mat){ // opreator output <<
        return os;
    }  


}
