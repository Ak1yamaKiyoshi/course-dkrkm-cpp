#include <iostream> // для вводу та виводу 
#include <Windows.h> // для кодування

using namespace std; 

void shift (int array[], int len) {
  int j = 0, temp;
  // Рахуємо скільки в масиві є додатніх парних елементів
  for (int i = 0; i < len; i++) {
    if (array[i] % 2 == 0 && array[i] > 0) {
      j++;
    }
  }
  // Йдемо по масиву поки не перемістимо всі додатні парні елементи
  for (int i = 0, s = 0; s < j; i++) {
    if (array[i] % 2 == 0 && array[i] > 0) {
      temp = array[i];
      array[i] = array[s];
      array[s] = temp;
      s++;
    }
  }
}

int sumBeforeZero (int array[], int len) {
  int sum = 0;
  int i = 0;
  // Проходимо по масиву поки він не закінчиться або не знайдемо нуль
  while (array[i] > 0 && i < len) {
    // Рахуємо суму
    sum += array[i];
    i++;
  }
  return sum;
}

int main() {
  SetConsoleOutputCP(65001); // Встановлення кодування
  SetConsoleCP(65001); // Встановлення кодування
  
  int len; // Довжина масиву
  int sum = 0;
  int option; // Змінна варіанту меню
  
  cout << "Введіть довжину масиву: ";
  cin >> len;
  
  int array[len]; // Створення масиву введеної довжини  

  // Введеня елементів масиву 
  for (int i = 0; i < len; i++) {
    cout << "Введіть елемент масиву: ";
    cin >> array[i];
  }

  cout << "\n  1. Порахувати суму до першого 0 масиву\n  2. Перемістити всі парні додатні масиву вліво\n 3.  Завершити виконання програми";
  cin >> option;

  switch (option) {
    case 1:
      // Підрахунок суми елементів масиву до першого нуля 
      sum = sumBeforeZero(array, len);
      
      if (sum != 0) {
        cout << "Сумма елементів до першого 0: " << sum << endl;
      }
      else {
        cout << "Не було знайдено жодного додатнього елемнту до 0" << endl;
      }
      break;
    case 2:  
      // Переміщення парних елементів вліво 
      shift(array, len);

      // Виведення елементів масиву 
      for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
      }
      break;
    default:
      cout << "Виконання програми завершено";
      break;
  }

  return 0;
}