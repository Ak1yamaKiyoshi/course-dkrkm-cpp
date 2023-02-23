#include <iostream> // ввід вивід з консолі та ввід у файли
#include <string.h> // робота з рядками substr(), getline, string, 
#include <windows.h> // SetConsoleOutputCP, SetConsoleCP встановлення кодування
#include <fstream> // робота з файлами, ifstream, ofstream, fstream, open(), close()


using namespace std;


struct goods {
  string name; // Назва  
  int shops[3]; // Магазини де є товар
  int price; // Ціна 
  string producer; // Виробник  
  int variety; // Гатунок товару  
  int gmo; // Наявність ГМО 0 ні 1 так 
};


// бере заповнений файл структур та записує його у файл (ім'я файлу також передавати у функцію)
void __write (string filename, goods obj) {
  ofstream ofs; // файл для запису 
  ofs.open(filename, ios::out); // відкритя файлу для запису (out)
  if (ofs.is_open()) { // перевірка чи файл відкритий 
    // запис даних структури у файл 
    ofs << "name=" << obj.name << endl; 
    ofs << "shops=" << obj.shops[0] 
    << obj.shops[1] << obj.shops[2] <<endl;
    ofs << "price=" << obj.price << endl;
    ofs << "producer=" << obj.producer << endl;
    ofs << "variety=" << obj.variety << endl;
    ofs << "gmo=" << obj.gmo << endl;
    ofs.close(); // закриття файлу 
  }
}

// функція яка повертає об'єкт (структури) типу goods
// Бере ім'я файлу з якого читає структуру
goods __read (string filename) {
  goods obj; // Об'єкт структури
  ifstream ifs; // файл для читання 
  string line;
  // open бере два аргументи, 1й ім'я файлу, 2й тип відкриття (out, in, app)
  ifs.open(filename, ios::in); // відкриття файлу для читання (in)
  if (ifs.is_open()) { // перевірка чи відкритий файл 
    getline(ifs, line); // читання рядку файлу
    obj.name = line.substr(5); // привласнення значення рядку від 5 символу змінній структури name 
    getline(ifs, line);
    // stoi - переквід string у int 
    obj.price = stoi(line.substr(6));
    getline(ifs, line);
    line = line.substr(6);
    // stoi - переквід string у int 
    obj.shops[0] = stoi(line.substr(0, 1));
    obj.shops[1] = stoi(line.substr(1, 1));
    obj.shops[2] = stoi(line.substr(2));
    getline(ifs, line);
    obj.producer = line.substr(9);
    getline(ifs, line);
    line = line.substr(8);
    // stoi - переквід string у int 
    obj.variety = stoi(line);
    getline(ifs, line);
    // stoi - переквід string у int 
    obj.gmo = stoi(line.substr(4));
    ifs.close(); // закриття файлу
  }
  return obj;
}

// функція повертає об'єкт типу (структури) goods '
// Заповнення об'єкту структури
goods make () { 
  goods obj; // об'єкт структури goods  
  cout << "Введіть назву товару: ";
  cin.sync(); // Синхронізація вводу 
  getline(cin, obj.name);
  cout << "Введіть назву номери кіосків де є товар: ";
  cin.sync(); // Синхронізація вводу 
  for (int i = 0; i < 3; i++) {
    cout << "номер: "; 
    cin >> obj.shops[i];
  }
  cout << "Введіть ціну: ";
  cin.sync(); // Синхронізація вводу 
  cin >> obj.price;
  cout << "Введіть виробника: ";
  cin.sync(); // Синхронізація вводу 
  getline(cin, obj.producer);
  cout << "Введіть гатунок: ";
  cin.sync(); // Синхронізація вводу 
  cin >> obj.variety;
  cout << "Введіть наявність гмо 0 ні 1 так: ";
  cin.sync(); // Синхронізація вводу 
  cin >> obj.gmo;

  return obj;
}
// Функція яка шукає файли програми
string __scanGoods() {
  string out; // рядок з номерами товарів 
  ifstream ifs; // файл для читання
  int count = 0;
  for (int i = 0; i < 100; i++) { // цикл для пошуку файлів програми по типу "goods1.txt"
    // open бере два аргументи, 1й ім'я файлу, 2й тип відкриття (out, in, app)
    ifs.open("goods" + to_string(i) + ".txt", ios::in); // відкриття файлу для читання (in)
    if (ifs.is_open()) { // перевірка чи відкритий файл 
      // to string перетворює int, float, double на string
      out +="." +  to_string(i); // доповнення рядку з номерами 
      count++;
    }
    ifs.close(); // закриття файлу 
  }
  out +="." +  to_string(count);
  return out; // Повертає string з номерами товарів 
}


//1) Вивести перелік усіх кіос-ків, де в наявності товар Х із вмістом ГМО.
void outShops () {
  string goodsNums = __scanGoods(); // пошук файлів програми (по типу goods1.txt)
  int beg=0, end=0; // змінні для формування назви файлу 
  string num, name;  // num для формування назви файлу (та читання файлу __read) name назва шуканого товару
  goods obj; // файл об'єкту для читання та перевірок
  int shops[30]; // масив з номерами кіосків
  int counter = 0; // лічильник кіосків у масиві shops
  int flag= 0; // змінна для перевірки чи записували ми кіоск у масив 

  for (int i = 0; i < 30; i++) { // Заповнення масиву нулями  
    shops[i] = 0;
  }

  cout << "Введіть назву товару (латинськими літерами): ";
  cin.sync(); // Синхронізація вводу
  getline(cin, name); // Запис назви шуканого товару

  for (int x = 0; x < 6; x++) { 
    // Перетворення string для назви файлу 
    num = goodsNums[end+1];
    if (beg+2 < end) 
      num += goodsNums[end+2];
    beg = goodsNums.find(".", end);
    end = goodsNums.find(".", beg+1); 
    obj = __read("goods" + num + ".txt"); // Читання файлу 
    if (obj.name == name) { // Якщо шукане ім'я та ім'я товару співпадають
      if (obj.gmo == 1) { // якщо у товарі є гмо (згідно з завдання)
        for (int i = 0; i < 3; i++) { // проходимось по кожному кіоску товару
          for (int c = 0; c < 30; c++) { // перевіряємо чи записали ми поточний кіоск товару
            if (obj.shops[i] == shops[c]) { 
              flag = 1;
              break;
            }
          }
          if (flag == 0) { // якщо ми ще не записували кіоск з таким номером то записуємо 
            shops[counter] = obj.shops[i];
            counter++; // лічильник кіосків 
          }
        }
      }
    }
  }
  // вивід всіх кіосків у яких є цей товар з вмістом гмо
  cout << "Товар " << name << " є у кіосках з номерами: ";
  for (int i = 0; i < counter; i++) {
    cout << " " << shops[i];
  }
  cout << "\n";
}


//2) Вивести перелік товарів  ґа-тунку Y з ціною
void outVariety () {
  string goodsNums = __scanGoods(); // пошук файлів програми (по типу goods1.txt)
  int beg=0, end=0; // змінні для формування назви файлу 
  string num; // для формування назви файлу (та читання файлу __read) 
  int variety;  //  шуканий гатунок
  goods obj; // файл об'єкту для читання та перевірок

  cout << "Введіть номер гатунку: ";
  cin.sync(); // Синхронізація вводу
  cin >> variety; // Запис назви шуканого товару

  int len =  goodsNums.find(".", goodsNums.length()-3);


  for (int x = 0; x < stoi(goodsNums.substr(len+1)); x++) { 
    // Перетворення string для назви файлу 
    num = goodsNums[end+1];
    if (beg+2 < end) 
      num += goodsNums[end+2];
    beg = goodsNums.find(".", end);
    end = goodsNums.find(".", beg+1); 
    obj = __read("goods" + num + ".txt"); // Читання файлу 
    if (obj.variety == variety) { // Якщо гатунок товару співпадає з шуканим гатунком 
      cout << "Товар: " << obj.name << " за ціною: " << obj.price << endl; 
    }
  }
}


int main() {
  SetConsoleCP(65001); // встановлення кодування
  SetConsoleOutputCP(65001); // встановлення кодування
  //goods obj;
  //obj = make();
  //__write("goods7.txt", obj);

  //outShops();
  outVariety();
  return 0;

}