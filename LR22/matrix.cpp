#include <iostream> // Бібліотека для вводу та виводу 
#include <cstdlib>  // Бібліотека для генерації випадкових чисел 
#include <ctime>    // Бібліотека для роботи з часом
#include "matrix.h"
#include <stdio.h>


MatrixUtils::MatrixUtils(int size) {
    this->size = size;
    matrix = new int *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
}


/// @brief Створює двовимірний масив з випадковими значеннями
/// @return Вказівник на створений масив
void MatrixUtils::createMatrix() {
    int **matrix = new int *[this->size]; // Створення нового двовимірного масиву, який буде містити вказівники на рядки матриці.
    for(int i = 0; i < this->size; i++){ // Початок циклу для ітерації по рядках матриці.
        matrix[i] = new int[this->size]; // Створення нового одновимірного масиву в кожному вказівнику рядка матриці.
        for(int j = 0; j < this->size; j++) // Занулення значень елементів матриці.
            matrix[i][j] = 0; 
    }
    this->matrix = matrix; 
}


/// @brief Виводить матрицю на екран
void MatrixUtils::printMatrix(){
    for(int i = 0; i < this->size; i++){   // Початок циклу для ітерації по рядках матриці.
        for(int j = 0; j < this->size; j++){ // Початок циклу для ітерації по елементах кожного рядка матриці.
            printf("%3d", this->matrix[i][j]); // Виводимо елементи матриці через пробіл
        }
        std::cout << std::endl; // Перехід на новий рядок
    }
}


/// @brief Виводить злагоджену матрицю на екран
void MatrixUtils::printSmoothedMatrix(){
    for(int i = 0; i < this->size; i++){   // Початок циклу для ітерації по рядках матриці.
        for(int j = 0; j < this->size; j++){ // Початок циклу для ітерації по елементах кожного рядка матриці.
            printf("%3d", this->smoothedMatrix[i][j]); // Виводимо елементи матриці через пробіл
        }
        std::cout << std::endl; // Перехід на новий рядок
    }
}


/// @brief Заповнює матрицю випадковими числами від 0 до 75
void MatrixUtils::fillMatrixWithRandom(){
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел зі значенням часу
    for(int i = 0; i < this->size; i++){  
        for(int j = 0; j < this->size; j++)
            this->matrix[i][j] = rand() % 76; // Генеруємо випадкове число від 0 до 75 і записуємо в елемент матриці
    }
}


/// @brief Згладжує матрицю шляхом обчислення середнього значення сусідніх елементів
/// @return Вказівник на нову матрицю згладжених значень
void MatrixUtils::smoothMatrix(){
    int **smoothed_matrix = new int *[this->size];
    // очаток першого циклу, що ітерується по рядках матриці.
    for(int i = 0; i < this->size; i++){
        /* Створення нового двовимірного масиву smoothed_matrix, який буде містити згладжену матрицю. Він має такий же розмір, як і вхідна матриця. */
        smoothed_matrix[i] = new int[this->size]; // Виділення пам'яті для кожного стовпця smoothed_matrix для зберігання елементів згладженої матриці.
        /*  Початок другого циклу, що ітерується по стовпцях матриці.*/
        for(int j = 0; j < this->size; j++){
            int sum_neighbors = 0;  // Змінна для зберігання суми сусідніх елементів 
            int count_neighbors = 0; // Кількість сусідніх елементів 
            
            /* Ці два цикли перебирають всі сусідні рядки та стовпці елемента (i, j). 
            Це означає, що ми розглядаємо кожен елемент, який оточує поточний елемент (i, j).*/
            for(int k = i-1; k <= i+1; k++)
                for(int l = j-1; l <= j+1; l++)
                    /* Умова if перевіряє, чи сусідній елемент (k, l) знаходиться всередині межі матриці. 
                    Це гарантує, що ми не виходимо за межі матриці при доступі до сусідніх елементів. 
                    Умова також перевіряє, що (k, l) не є самим елементом (i, j),
                     оскільки ми хочемо обчислити середнє значення сусідів, а не самого елемента. */
                    if(k >= 0 && k < this->size && l >= 0 && l < this->size && (k != i || l != j)){
                        /* арахування суми значень сусідніх елементів matrix[k][l] та підрахунок їх кількості. 
                        Значення сусідів додаються до sum_neighbors, а лічильник count_neighbors збільшується на 1. */
                        sum_neighbors += this->matrix[k][l];
                        count_neighbors++;
                    }
            /* Після завершення циклів підрахунку сусідів, значення для згладженої матриці smoothed_matrix[i][j] обчислюється, поділивши sum_neighbors на count_neighbors. 
            Це дозволяє отримати середнє значення сусідніх елементів для поточного елемента (i, j).*/
            smoothed_matrix[i][j] = sum_neighbors / count_neighbors;
        }
    }
    this->smoothedMatrix = smoothed_matrix;
}


MatrixUtils::~MatrixUtils() {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
        delete[] smoothedMatrix[i];
    }
    delete[] matrix;
    delete[] smoothedMatrix;
}





