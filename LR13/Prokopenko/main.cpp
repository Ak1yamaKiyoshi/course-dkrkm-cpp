#include <iostream> // для вводу та виводу значень 
#include <windows.h> // для встановлення кодування
#include <math.h> // для sqrt()

using namespace std;

// Робимо функцію X що повертає результат обчислень за завданням
float X(int x) {
  return (3*x)/(1-sqrt(x));
}

// Робимо функцію Z що повертає результат обчислень за завданням
float Z(int x) {
  return (1/2*x);
}

// Робимо функцію ZX що повертає результат обчислень за завданням
float* ZX(int x) {
  static float out[2]; // зазначаємо статичний масив
  // Статичний масив потрібен бо функції не повертають локальні значення
  out[0] = (3*x)/(1-sqrt(x));
  out[1] = (1/2*x);
  return out;
}

int main() {
  SetConsoleOutputCP(65001); // Встановлення кодування виводу консолі
  SetConsoleCP(65001); // Встановлення кодування консолі

  // option - змінна варіанту для меню
  // x - змінна яку ми передаємо у функції
  int x, option = 1;

  // Меню 
  cout << "\n  menu:\n  1. (3*x)/(1-sqrt(x))\n  2. (1/2*x)\n  3. both 1 and 2\n  4 or else. stop program\n";
  cout << "option: "; 
  cin >> option;

  switch (option) {
    case 1:
      cout << "enter x:";
      cin >> x;
      cout << "X:" << X(x) << endl;
      break;
    case 2:
      cout << "enter x:";
      cin >> x;
      cout << "Z:" << Z(x) << endl;
      break;
    case 3:
      cout << "enter x:";
      cin >> x;
      cout << "ZX:" << "\n  x1:" << ZX(x)[0] << "\n  x2:" << ZX(x)[1] << endl;
      break;
    default:
      cout << "Програма завершила своє виконання" << endl;
      break;
  }
  return 0;
}

