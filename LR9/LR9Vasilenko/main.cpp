#include <iostream> // для базового вводу та виводу 
#include <windows.h> //Для встановлення кодировки

using namespace std;

int main(){
    SetConsoleCP(65001); //встановлюємо кодування
    SetConsoleOutputCP(65001); //встановлюємо кодування
   
    int len; // довжина масиву 

    cout << "Введіть довжину масиву:"; //
    cin >> len; 
    float array[len]; // оголошення псевдодинамічного масиву 

    // введення масиву 
    for (int i = 0; i < len; i++){ 
        cout << "Введіть " << i << " елемент:"; 
        cin >> array[i];
    }

    // мінімальне значення та поточне число  
    float min, num;
    int minIndex;  // індекс мінімального значення 
    int j = 0, i;// індекси

    while (j < len) { // поки j < довжини масиву 
        for (i = j; i < len; i++) { // і = j, поки i < довжини масиву i++ 
            if (i == j || min < array[i]) { // якщо і == j або мінімальне менше за поточний елемент масиву 
                min = array[i]; // запам'ятовуємо мінімальне число 
                minIndex = i; // запам'ятовуємо його індекс 
            }
        }
        num = array[minIndex]; // робимо заміну 
        array[minIndex] = array[j];
        array[j] = num;
        j++;
    }

    // виведення масиву 
    cout << "Масив:\n";
    for (i = 0; i < len; i++)
        cout << array[i] << " ";

    return 0;
}