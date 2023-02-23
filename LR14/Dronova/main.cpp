#include <iostream> // для вводу та виводу 
#include <Windows.h> // для кодування

using namespace std; 


//  стиснути масив, видалив з нього усі елементи, модуль яких знаходиться в інтервалі [a,b]. 
// Елементи, що задовольняють вказаній умові замінити ну-лями та розмістити в кінці масиву.
void shift (int array[], int len) 
{
  int a, b;
  cout << "ВВедіть інтервал a < num < b, а та б через пробіл: ";
  cin >> a >> b;


  int j = 0, temp;
  for (int i = 0; i < len; i++) {
    if (a <= array[i] && b >= array[i]) {
      j++;
    }
  }
  // Елементи, що задовольняють вказаній умові замінити ну-лями та розмістити в кінці масиву.
  for (int i = 0, s = len-1; s > j; i++) {
    if (a <= array[i] && b >= array[i]) {
      array[i] = array[s];
      array[s] = 0;
      s--;
    }
  }
}


int sumBetweenFirstLastPositive (int array[], int len) {
  int positiveC = 0;
  int sum=0, flag=0;
  for (int i=0; i<len; i++) {
    if (array[i]>0) positiveC++;
  }
  int i = 0;
  while (positiveC>0 && i < len) {
    if (array[i]>0) {
      flag=1; positiveC--;
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

  cout << "\n  1. Порахувати суму до між першим та останнім додатнім елементом масиву\n  2. стиснути масив\n 3.  Завершити виконання програми";
  cin >> option;

  switch (option) {
    case 1:
      // Підрахунок суми елементів масиву між першим та останнім додатнім елементом
      sum = sumBetweenFirstLastPositive(array, len);
      cout << "Сумма елементів між першим та  останнім додатнім елементом: " << sum << endl;
      break;
    case 2:  
      // стиснути масив
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