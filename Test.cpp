#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.hpp"
#include "doctest.h"

using namespace std;
using namespace zich;


TEST_CASE("Good input") {
    vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat1(identity, 3,3);
    Matrix mat2(arr, 3,3);

    vector<double> vec = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix ans(vec, 3,3);
    CHECK((mat1 == ans));

    vector<double> vec1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix ans1(vec1, 3,3);            
    CHECK(((3*mat1) == ans1));

    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix ans2(vec2, 3,3);
    CHECK(((-mat1) == ans2));

    vector<double> vec3 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix ans3(vec3, 3,3);
    CHECK(((mat1+ mat2) == ans3));

    vector<double> vec4 = {-3, 0, 0, 0, -3, 0, 0, 0, -3};
    Matrix ans4(vec4, 3,3);
    mat1 *=3; 
    CHECK((mat1 == ans4));


    vector<double> vec5 = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix ans5(vec5, 3,3);
    CHECK(((mat1- mat2) == ans5));

    vector<double> vec6 = {-3, 0, 0, 0, -3, 0, 0, 0, -3};
    Matrix ans6(vec6, 3,3);
    CHECK(((-mat2) == ans6));

    vector<double> vec7 = {12, 0, 0, 0, 12, 0, 0, 0, 12};
    Matrix ans7(vec7, 3,3);
    CHECK(((4*mat2) == ans7));

    vector<double> vec8 = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    Matrix ans8(vec8, 3,3);
    mat2+=2;
    CHECK(((mat2) == ans8));
    
    vector<double> vec9 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix ans9(vec9, 3,3);
    CHECK(((mat2+mat1) == ans9));

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    vector<double> m1 = {2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0};
    vector<double> m2 = {3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0};
    Matrix mat3(m1, 4,3);
    Matrix mat4(m2, 5,4);

    vector<double> vec10 = {6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 6};
    Matrix ans10(vec10, 4,4);
    CHECK(((mat4 * mat3) == ans10) );// Multiply matrix that the col number of mat4 == the row number of mat3
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(double i = 0; i < 100; i++){  
        vector<double> m3 = {i, 0, 0, i+1 , i, i, 0, 0, i};
        vector<double> m4 = {i, 0, i, 0, i, 0, i, i, 0};
        Matrix mat5(m3,3,3);
        Matrix mat6(m4, 3,3);

            
        vector<double> m3_plus_one = {i+1, 1, 1, i+2, i+1, i+1, 1, 1, i+1};
        Matrix ans11(m3_plus_one, 3,3);
        CHECK(((mat5++)==ans11)); // check ++ operator


        vector<double> m4_minus_unary = {-i, 0, -i, 0, -i, 0, -i, -i, 0};
        Matrix ans12(m4_minus_unary, 3,3);
        CHECK(((-mat6)==ans12)); // check - unary

        vector<double> m3_mul_scalar = {(2)*i, 0, 0, (2)*(i+1), 2*i, 2*i, 0, 0, 2*i};
        Matrix ans13(m3_mul_scalar, 3,3);
        CHECK(((2*mat6)==ans13)); // check mat5*scalar

        CHECK((mat5 != mat6)); //check !=

    ///////////////////////////////////////////////////////////////////////////////

        vector<double> m5 = {i, 0, 0, i+1 , i, i, 0, 0, i};
        vector<double> m6 = {i+1, 1, 1, i+2, i+1, i+1, 1, 1, i+1};
        Matrix mat7(m5,3,3);
        Matrix mat8(m6, 3,3);

        CHECK((mat8 > mat7)); // check >
        CHECK((mat8 < mat7)); // check <

        Matrix ans14(m5, 3,3);
        CHECK(((+mat5) == ans14)); // check + unary

    }

}

TEST_CASE("Bad input") {
    vector<double> identity = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    vector<double> arr = {5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5};
    Matrix mat1(identity, 3,3);
    Matrix mat2(arr, 4,4);
    CHECK_THROWS(Matrix mat11(arr, 0,-1)); // the size of the matrix need to be a positive numbers
    CHECK_THROWS(Matrix mat11(arr, -5,-1)); // the size of the matrix need to be a positive number


    CHECK_THROWS(bool ans = (mat1 == (mat2))); //2 matrix with diffrent size
    CHECK_THROWS(bool ans =(mat1 == (mat2))); //2 matrix with diffrent size
    CHECK_THROWS(bool ans = (mat1 <= (mat2))); //2 matrix with diffrent size
    CHECK_THROWS(bool ans =(mat1 < (mat2))); //2 matrix with diffrent size
    CHECK_THROWS(bool ans =(mat1 > (mat2))); //2 matrix with diffrent size
    CHECK_THROWS(bool ans = (mat1 != (mat2))); //2 matrix with diffrent size

    CHECK_THROWS(((mat1) + mat2)); //2 matrix with diffrent size
    CHECK_THROWS(((mat1) - mat2)); //2 matrix with diffrent size

    CHECK_THROWS(((mat1) * mat2)); //the col number of mat1 != the row number of mat2 -The condition for doubling matrixs

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<double> vec1 = {6, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 6, 0, 0};
    vector<double> vec2 = {10, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 10, 0};
    Matrix mat3(vec1, 5,3);
    Matrix mat4(vec2, 5,4);

    CHECK_THROWS(bool ans =(mat3 >= mat4)); //2 matrix with diffrent size
    CHECK_THROWS(bool ans = (mat3 == mat4)); //2 matrix with diffrent size
    CHECK_THROWS(bool ans = (mat3 <= mat4)); //2 matrix with diffrent size
    CHECK_THROWS(bool ans =(mat3 < mat4)); //2 matrix with diffrent size
    CHECK_THROWS(bool ans =(mat3 > mat4)); //2 matrix with diffrent size
    CHECK_THROWS(bool ans =(mat3 != mat4)); //2 matrix with diffrent size

    CHECK_THROWS(((mat3) + mat4)); //2 matrix with diffrent size
    CHECK_THROWS(((mat3) - mat4)); //2 matrix with diffrent size

    CHECK_THROWS(((mat3) * mat4)); //the col number of mat3 != the row number of mat4 -The condition for doubling matrixs

    ///////////////////////////////////////////////////////////////////////////////////////////////

    vector<double> vec3 = {2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0};
    vector<double> vec4 = {3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0};
    Matrix mat5(vec3, 4,3);
    Matrix mat6(vec4, 5,4);

    CHECK_THROWS(((mat5) + mat6)); //2 matrix with diffrent size
    CHECK_THROWS(((mat5) - mat6)); //2 matrix with diffrent size


    CHECK_THROWS(((mat5) * mat6)); //the col number of mat3 != the row number of mat4 -The condition for doubling matrixs

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<double> vec5 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    vector<double> vec6 = {5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5};
    Matrix mat7(vec5, 4,3);
    Matrix mat8(vec6, 4,4);

    CHECK_THROWS(((mat7) + mat8)); //2 matrix with diffrent size
    CHECK_THROWS(((mat7) - mat8)); //2 matrix with diffrent size


    CHECK_THROWS(((mat7) * mat8)); //the col number of mat3 != the row number of mat4 -The condition for doubling matrixs

}
