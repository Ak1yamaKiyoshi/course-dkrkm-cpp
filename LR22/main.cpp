#include "matrix.cpp"
#include <iostream>


int main() {
    int size = 10; // Задаємо початковий розмір матриці 
    MatrixUtils matrixUtils(size); // Створюємо матрицю із заданим розміром 
    matrixUtils.fillMatrixWithRandom(); // Заповнюємо випадковими числами від 0 до 75 

    std::cout << "Original matrix:" << std::endl; 
    matrixUtils.printMatrix(); // Виводимо цю матрицю 


    matrixUtils.smoothMatrix(); // Злагоджуємо матрицю
    std::cout << "Smoothed matrix:" << std::endl;
    matrixUtils.printSmoothedMatrix(); // Виводимо злагоджену матрицю 

    return 0;
}