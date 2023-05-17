#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

class MatrixUtils {
private:
    int **matrix;
    int size;
    int **smoothedMatrix;

public:
    MatrixUtils(int size);
    ~MatrixUtils();
    void createMatrix();
    void printMatrix();
    void printSmoothedMatrix();
    void fillMatrixWithRandom();
    void smoothMatrix();
};

#endif // MATRIX_UTILS_H