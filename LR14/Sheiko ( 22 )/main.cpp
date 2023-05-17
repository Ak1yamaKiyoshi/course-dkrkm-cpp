#include <iostream> // блібліотека для функцій вводу та виводу, у цьому коді використовується для std::cout та std::cin
#include <windows.h> // бібліотека для взаємодії з операційною системою windows, у цьому коді використовується для виводу у консоль українською мовою



/*
У одномірному масиві, який складається з n дійсних елементів, обчислити:
а) суму елементів масиву, розташованих до останнього додатного елементу;
б) стиснути масив, видалив з нього усі елементи, модуль яких знаходиться в інтервалі [a,b]. 
Елементи, що задовольняють вказані умові, замінити нулями та розмістити в кінці масиву.
*/  

//  стиснути масив, видалив з нього усі елементи, модуль яких знаходиться в інтервалі [a,b]. 
// Елементи, що задовольняють вказаній умові замінити ну-лями та розмістити в кінці масиву.
// void shrinkArray (int array[], int len)  - сигнатура функції 
// void - функція нічого не повертає 
// shrinkArray - назва функції 
// Функція приймає масив із типом int 
// а також його довжину 
void shrinkArray (int array[], int len) 
{
    int a, b; // а - початок інтернвалу, b - кінець інтервалу 

    // std::cout - вивід 
    // std::cin - ввід 

    // просимо користувача ввести інтервал 
    std::cout << "\nВведіть інтервал а та б через пробіл: ";
    std::cin >> a >> b; // Вводимо а, а потім b;

    int c = len-1; // с - індекс останнього числа ( для переміщення значень  )
    for (int i = 0; i < len; i++) { // проходимось по всьому масиву 
        if (a <= array[i] && b >= array[i]) { // якщо число у потрібному нам діапазоні 
            array[i] = array[c]; // присвоюємо числу з діапазону значення числа з кінця масиву
            array[c--] = 0; // у кінці масиву ставимо 0 
            // таким чином ми прибираємо число з діапазону, але всі інші числа залишаються у масиві 
        }
    }
}

// Вивід масиву 
void print(int *array, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " "; 
    }
}

// а) суму елементів масиву, розташованих до останнього додатного елементу;
int sumBeforeLastPositiveElementInArray(int *array, int len) {
    int sum = 0;
    bool flag = false; 
    for (int i = len - 1; i >= 0; i--)  {
        if (array[i] > 0) flag = true;
        if (flag) sum += array[i];
    }
    return sum;
}


// Головна функція ( Саме вона виконується у коді, якщо головної функції не буде, то і код виконуватись не буде )
// Головна функція не очікує ніяких параметрів. 
// У разі правильного виконання програми повертаємо тип int ( ціле число ), а саме 0
int main(void) {

    SetConsoleCP(65001); // Встановлюємо кодування консолі
    SetConsoleOutputCP(65001); // Встановлюємо кодування виводу консолі ( інакше українські літери будуть відображатись не коректно )

    int len = 7; // довжина масиву 
    int array[] = { 1, 2, 3, 4, -200, -3000, -4000}; // масив 

    // рахуємо суму до останнього додатнього числа 
    std::cout << "\n Сума елементів до останнього додатнього числа: " 
    << sumBeforeLastPositiveElementInArray(array, len) << "\n";

    std::cout << "\n"; // виводимо \n щоб далі виводити з нового рядку
    print(array,len); // виводимо масив у консоль 
    shrinkArray(array, len); // стискаємо масив 

    std::cout << "\n Стиснутий масив: "; // виводимо \n щоб далі виводити з нового рядку
    print(array, len); // виводимо масив у консоль 

    return 0;
}