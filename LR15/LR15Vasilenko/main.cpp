#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>

using namespace std;

int main()
{
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);

  fstream file; 
  int rows;
  string line;
  string maxLine;

  char row[100];
  char elemToSearch=' ';
  int count = 0;
  int maxCount = 0;

  cout << "Введіть кількість рядків: ";
  cin >> rows;

  // Відкриття файлу для запису (ios::out)
  file.open("lr15VasilenkoData.txt", ios::out); 
  if (file.is_open()) { // Якщо файл відкритий
    for (int i = 0; i < rows; i++) { // Записуємо стільки рядків у файл скільки ввів користувач
      cout << "Введіть рядок (латинськими літерами):" << endl; 
      cin.sync(); // Потрібно для того щоб у буфері не залишалось \n 
      getline(cin, line); // Запис рядку з консолі до масиву char 
      file << line << endl; // Запис рядку з масиву у файл 
    }
    file.close(); // Закриваємо файл після роботи з ним 
  }

  // Відкриття файлу для читання (ios::out)
  file.open("lr15VasilenkoData.txt", ios::in);
  if (file.is_open()) { // Якщо файл відкритий
    while (getline(file, line)) { // Читаємо рядок з файлу 
        strcpy(row, line.c_str()); // Записуємо рядок у масив чарів 
        count = 0;
        for (int i = 0; i < line.length(); i++) { // йдемо циклом поки не закінчиться рядок 
          if (row[i] == elemToSearch) {
            count++;
          } // додаємо 1 до count кожного разу як знаходимо пробіл
      }
      if (maxCount < count)  { // запам'ятовуємо рядок з найбільшим значенням знайдених елементів (пробіл)
        maxCount = count;
        maxLine = line;
      }
    }
    file.close();
  }

  if (maxCount == 0) {
    cout << "Не було знайдено жодного шуканого елементу у всіх рядках" << endl;
  }
  else {
    cout << "Найбільше слів (" << maxCount << ") у рядку:\n" << maxLine << endl; 
  }

  return 0;
}