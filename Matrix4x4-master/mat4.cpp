#include "mat4.h"

// This constructor initializes the 2d float array with v along
// the diagnal [(0, 0), (1, 1), (2, 2), (3, 3)]. The rest of
// the matrix will be zeros.
mat4::mat4(float v){
    this->m = new float[4][4];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(i == j)
                diag[i][j]=v;
}

// Copy Constructor. Initilaizes this matrix with the values of the
// passed in matrix.
mat4::mat4(mat4& m){
    this->m = *m;
}

// Adds the values of m to this matrix.
void mat4::add(mat4 m){
    for(int i = 0; i < (sizeof(this->m)/sizeof(int)); i++)
        for(int j = 0; j < (sizeof(this->m[i])/sizeof(int)); j++)
            this->m[i][j] = this->m[i][j] + m[i][j];
}

// Subtracts the values of m from this matrix
void mat4::subtract(mat4 m){
    for(int i = 0; i < (sizeof(this->m)/sizeof(int)); i++)
        for(int j = 0; j < (sizeof(this->m[i])/sizeof(int)); j++)
            this->m[i][j] = this->m[i][j] - m[i][j];
}

// Multiplies this matrix and m together.
// If you are unfamiliar with the algorithm of multiplying matrices,
// go to this site for an introduction:
// https://www.mathsisfun.com/algebra/matrix-multiplying.html
void mat4::multiply(mat4 m){
    int rowSum = 0;
    float[][] copy = *this->m;
    int rows = sizeof(copy)/sizeof(int);
    int cols = (sizeof(copy[0])/sizeof(int));
    this->m = new float[rows][sizeof(m[0])/sizeof(int)];
    int row = 0;
    int col = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            rowSum = rowSum + (copy[i][j] + m[j][i]);
        }
        this->m[row][col] = rowSum;
        if(col < cols - 2) col++;
        else {
            row++;
            col = 0;
        }
    }
}

// Multiplies m1 and m2 and returns the result.
mat4 mat4::multiply(mat4 m1, mat4 m2){
    mat4 m;
    m = m1.multiply(m2);
    return m;
}

// Adds m1 and m2 and returns the result.
mat4 mat4::add(mat4 m1, mat4 m2){
    mat4 m;
    m = m1.add(m2);
    return m;
}

// subtracts m2 from m1 and returns the result.
mat4 mat4::subtract(mat4 m1, mat4 m2){
    mat4 m;
    m = m1.subtract(m2);
    return m;
}