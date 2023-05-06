#include "array.h"
#include <iostream>


Array::Array() {
    this->arr = nullptr;
    this->lenght = 0;
    std::cout << "Array created" << std::endl;
};


Array::Array(int len, int *array) {
    this->arr = array;
    this->lenght = len;
    std::cout << "Array created" << std::endl;
};

Array::~Array() {
    if (this->arr != nullptr) 
        this->lenght = 0;
        delete this->arr;
        this->arr = nullptr; 
    std::cout << "Array deleted" << std::endl;
};

void Array::enter() {
    std::cout << "Enter " << this->lenght << " numbers: ";
    for (int i = 0; i < this->lenght; i++) 
        std::cin >> this->arr[i];
};

/* 1. Кількість елементів масиву, що лежать в діапазоні від А до В включно. */ 
int Array::count(int a, int b) {
    int counter = 0; // лічильник 
    for (int i = 0; i < this->lenght; i++) 
        // якщо число у заднанному діапазоні, інкрементуємо лічільник
        if (this->arr[i] >= a && this->arr[i] <= b) counter++;
    return counter;
};


/* 2. Суму елементів масиву, розташованих після останнього максимального елемента. */
int Array::sumAfterLastMax() {
    int max = 0; // максимальне число 
    int sum = 0; // сума
    for (int i = 0; i < this->lenght; i++) {
        if (this->arr[i] >= max) { // якщо поточне число == або більше максимального 
            max = this->arr[i]; // оновлюємо максимальне число 
            // скидуємо суму до 0 ( щоб рахувало нову суму після кожного максимального числа)
            sum = 0 - this->arr[i]; 
        }
        // рахуємо суму 
        sum += this->arr[i];
    }
    return sum;
};


void Array::set(int len, int *array) {
    this->lenght = len;
    this->arr = array;
};

// Вивід масиву 
void Array::print() {
    for (int i = 0; i < this->lenght; i++)
        std::cout << this->arr[i] << " ";
};