#include <iostream> // для вводу та виводу 
#include <Windows.h> // для кодування

using namespace std; 

// б) перетворити масив таким чином, 
// щоб спочатку розташовувались усі до-датні елементи, 
// а потім – усі від’ємні (елементи, які дорівнюють 0, рахувати додатними).
void shift (int array[], int len) 
{
  int j = 0, temp;
  // Рахуємо скільки в масиві є від'ємних елементів
  for (int i = 0; i < len; i++) {
    if (array[i] > 0) {
      j++;
    }
  }
  // Йдемо по масиву поки не перемістимо всі від'ємні елементи
  for (int i = 0, s = 0; s < j; i++) {
    if (array[i] > 0 ) {
      // заміна двох елементів масиву місцями
      temp = array[i];
      array[i] = array[s];
      array[s] = temp;
      s++;
    }
  }
}

/* суму елементів масиву, розташованих між першим та останнім нульови-ми елементами;*/
int sumBetweenFirstLastZero (int array[], int len) {
  int zerosC = 0;
  int sum=0, flag=0;
  // рахуємо скільки у масиві нульових елементів 
  for (int i=0; i<len; i++) {
    if (array[i]==0) zerosC++;
  }
  int i = 0;
  // йдемо масивом поки не закінчаться нульові елементі 
  while (zerosC>0 && i < len) {
    if (array[i]==0) {
      flag=1; zerosC--;
    }
    if (flag==1) 
      sum+=array[i];
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

  cout << "\n  1. Порахувати суму до між першим та останнім нулем масиву\n  2. Перемістити всі від'ємні елементи масиву праворуч\n 3.  Завершити виконання програми";
  cin >> option;

  switch (option) {
    case 1:
      // Підрахунок суми елементів масиву між першим та останнім нулем 
      sum = sumBetweenFirstLastZero(array, len);
      cout << "Сумма елементів між першим та останнім нулем: " << sum << endl;
      break;
    case 2:  
      // Переміщення від'ємних елементів ліворуч (а парних праворуч)
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