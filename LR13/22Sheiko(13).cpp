#include <iostream> // блібліотека для функцій вводу та виводу, у цьому коді використовується для std::cout та std::cin
#include <windows.h> // бібліотека для взаємодії з операційною системою windows, у цьому коді використовується для виводу у консоль українською мовою


// тип float - це дійсні числа, наприклад: -1.222, 3.1468
// float Z (int x) - сигнатура функції, де:
// float - тип даних яка повертає функція
// Z - назва функції 
// (int x) параметри функції
// int - тип параметру х який приймає функція
// функція може приймати декілька параметрів різних типів 
// результатом ділення може бути тип float, тому функція повертає float ( можливо замінити на double )
float Z (int x) 
{
    //  формула: 
    /*    1
     *  ----
     *   7x
    */
    // повертає пораховану формулу
    return ( 1 / 7 * x);

}

// тип float - це дійсні числа, наприклад: -1.222, 3.1468
// float Z (int x) - сигнатура функції, де:
// float Y (int x) - сигнатура функції, де:
// float - тип даних яка повертає функція
// Y - назва функції 
// (int x) параметри функції
// int - тип параметру х який приймає функція
// функція може приймати декілька параметрів різних типів 
// результатом ділення може бути тип float, тому функція повертає float ( можливо замінити на double 
float Y (int x) 
{
    //    формула: 
    /*       1
     *  ----------
     *   4 + x^3
    */
    // повертає пораховану формулу
    return ( 1 / ( 4 + x * x * x));

}   


// Головна функція ( Саме вона виконується у коді, якщо головної функції не буде, то і код виконуватись не буде )
// Головна функція не очікує ніяких параметрів. 
// У разі правильного виконання програми повертаємо тип int ( ціле число ), а саме 0
int main(void) 
{

    SetConsoleCP(65001); // Встановлюємо кодування консолі
    SetConsoleOutputCP(65001); // Встановлюємо кодування виводу консолі ( інакше українські літери будуть відображатись не коректно )

    int firstParameter;  // змінна для значення Х для першої функції 
    int secondParameter; // змінна для значення Х для другої функції 

    // std::cout - вивід 
    // std::cin - ввід 

    std::cout << "Введіть значення Х для першої формули: "; // Виводимо повідомлення
    std::cin >> firstParameter; // Вводимо у консоль перше значення Х у змінну firstParameter
    
    std::cout << "\nВведіть значення Х для першої формули: "; // Виводимо повідомлення
    std::cin >> secondParameter;// Вводимо у консоль дргуе значення Х у змінну secondParameter
    
    // Виводимо повідомлення з результатами
    // "\n" - виводить текст на новий рядок
    std::cout << "\nРезультат виконання першої функції: " 
              << Z(firstParameter) // Викликаємо першу функцію, та передаємо туди значення змінної firstParameter
              << "\nРезультат виконання другої функції: " 
              << Y(secondParameter); // Викликаємо другу функцію, та передаємо туди значення змінної secondParameter

    return 0; // Повертаємо 0 - це значить що програма виконана успішно 
}