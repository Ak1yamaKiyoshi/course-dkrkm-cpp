#include <iostream> // для вводу та виводу значень 
#include <windows.h> // для встановлення кодування
#include <math.h> // для sqrt()

using namespace std;

// Робимо функцію Y що повертає результат обчислень за завданням
float Y(int x) {
  return (x-1)*(x-1);
}

// Робимо функцію Z що повертає результат обчислень за завданням
float Z(int x) {
  return 1/(2+ x*x);
}

// Робимо функцію YZ що повертає результат обчислень за завданням
float* YZ(int x) {
  static float out[2]; // зазначаємо статичний масив
  // Статичний масив потрібен бо функції не повертають локальні значення
  out[0] = Z(x);
  out[1] = Y(x);
  return out;
}

int main() {
  SetConsoleOutputCP(65001); // Встановлення кодування виводу консолі
  SetConsoleCP(65001); // Встановлення кодування консолі

  // option - змінна варіанту для меню
  // x - змінна яку ми передаємо у функції
  int x, option = 1;

  // Меню 
  cout << "\n  menu:\n  1. Y\n  2. Z\n  3. both 1 and 2\n  4 or else. stop program\n";
  cout << "option: "; 
  cin >> option;

  switch (option) {
    case 1:
      cout << "enter x:";
      cin >> x;
      cout << "Y:" << Y(x) << endl;
      break;
    case 2:
      cout << "enter x:";
      cin >> x;
      cout << "Z:" << Z(x) << endl;
      break;
    case 3:
      cout << "enter x:";
      cin >> x;
      cout << "YZ:" << "\n  x1:" << YZ(x)[0] << "\n  x2:" << YZ(x)[1] << endl;
      break;
    default:
      cout << "Програма завершила своє виконання" << endl;
      break;
  }
  return 0;
}

