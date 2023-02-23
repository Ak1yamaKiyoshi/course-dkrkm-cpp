#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

struct Date {
    int day; // 0 - 31
    int month; // 0 - 12
    int year; 
};

struct dtp {
    string area; // Район ДТП;
    string name; // ПІБ власника  авто, що скоїв ДТП;
    int num; // Кількість постраждалих.
    Date date; // Дата 
};

// заповнення файлу структури з рядку з файлу 
dtp fill(string line) {
    dtp obj;
    string buffer;
    string date;

    buffer = line.substr(1);
    buffer = buffer.substr(0, buffer.find(','));
    obj.area = buffer;

    buffer = line.substr(buffer.length()+3);
    buffer = buffer.substr(0, buffer.find(','));
    obj.name = buffer;

    buffer = line.substr(obj.name.length()+2 + obj.area.length()+2+1);
    buffer = buffer.substr(0, buffer.find(','));

    obj.num = stoi(buffer);
    buffer = line.substr(line.find('{', 1));
    
    date = buffer;
    buffer = date.substr(0, buffer.find(','));
    buffer = buffer.substr(1);
    obj.date.day = stoi(buffer);

    buffer = date.substr(buffer.length()+1+2, buffer.find(','));
    buffer = buffer.substr(0, buffer.find(','));
    obj.date.month = stoi(buffer);

    buffer = date.substr(date.length()-5);
    buffer = buffer.substr(0, buffer.find('}'));
    obj.date.year = stoi(buffer);

    return obj;
}

int listSize=0;
dtp list[20];

void read() {
    string line; // буфер для запису рядків з файлу 
    ifstream file; // відкриття файлу під запис 
    listSize=0; // змінна розміру для кількості рядків у файл
    file.open("Dronovadata.txt", ios::in); // відкриття файлу під читання
    if (file.is_open()) { // якщо файл відкритий 
        while(getline(file, line)) 
            listSize++; 
        file.close(); // закриття файлу, бо ми поки рахували його пройшли повністю 
        file.open("Dronovadata.txt", ios::in); // відкриття файлу 
        int i = 0; // змінна для того аби рухатись по масиву структур f0 (оголошений глобально)
        while (getline(file, line))
        {   
            list[i] = fill(line); // передаємо рядок у функцію яка повертає заповнену структуру  
            listSize++;
            i++;
        }
        file.close(); // закриваємо файл
    }
}


// Створення нового об'єкту структури dtp
dtp add() 
{
    dtp obj; 
    fstream file;

    cout << ">| Введіть район дтп: ";
    cin.sync(); getline(cin, obj.area);
    cout << ">| Введіть ім'я власника авто що скоїв дтп: ";
    cin.sync(); getline(cin, obj.name);
    cout << ">| Введіть кількість постраждалих: ";
    cin.sync(); cin >> obj.num; 
    cout << ">| Введіть дату через пробіл - день місяць рік\n>|-наприклад: 29 10 2022 \n>|-Ввід: ";
    cin.sync(); cin >>  obj.date.day >> obj.date.month >> obj.date.year;
    cout << endl;
    //{"Synelnikovskiy", "Hto to tam",   3, {21, 8, 2022}}
    file.open("Dronovadata.txt", ios::app); // відкриваємо файл у режимі додавання app 
    if (file.is_open()) { // якщо файл відкритий 
        file  << 
        "{"   << obj.area << 
        ", "  << obj.name << 
        ", "  << obj.num << 
        ", {" << obj.date.day << 
        ", "  << obj.date.month << 
        ", "  << obj.date.year << 
        "}"   << endl;
        file.close(); // закриваємо файл 
    }
    return obj;
}

// Виведення об'єкту dtp
void print(dtp obj) 
{
    cout << "<| Район дтп: ";
    cout << obj.area << endl;
    cout << "<| Ім'я власника авто що скоїв дтп: ";
    cout << obj.name << endl;
    cout << "<| Кількість постраждалих: ";
    cout << obj.num << endl; 
    cout << "<| Дата: ";
    cout << " " << obj.date.day << " " << obj.date.month << " " << obj.date.year << endl;
}

// Кількість постраждалих у ДТП в районі Х за у період часу від А до В(дата).
void injuries(dtp list[20], int listSize)  
{
    dtp obj;
    string area;
    Date dateA;
    Date dateB;

    cout << ">| Введіть район дтп: ";
    cin.sync(); getline(cin, area);
    cout << ">| Введіть дату А через пробіл - день місяць рік\n>|-Ввід: ";
    cin.sync(); cin >> dateA.day >> dateA.month >> dateA.year;
    cout << ">| Введіть дату Б через пробіл - день місяць рік\n>|-Ввід: ";
    cin.sync(); cin >> dateB.day >> dateB.month >> dateB.year;

    for (int i=0; i<listSize; i++) {
        obj=list[i];
        if (obj.area == area) 
            if (obj.date.day >= dateA.day && obj.date.month >= dateA.month && obj.date.year >= dateA.year) 
                if (obj.date.day <= dateB.day && obj.date.month <= dateB.month && obj.date.year <= dateB.year) {
                    cout << "<| Кількість постраждалих: ";
                    cout << obj.num << endl; 
                }
    }   
}


// ПІБ винуватців ДТП, де постраждалих найбільша кількість та ДТП, де не було постраждалих.
void name(dtp list[20], int listSize) {
    dtp obj;
    int max=0;
    for (int i=0; i<listSize; i++) {
        obj=list[i];
        if (max < obj.num) 
            max = obj.num;
    }

    for (int i=0; i<listSize-1; i++) {
        obj=list[i];
        if (obj.num == 0 || obj.num == max) {
            cout << "<| Ім'я власника авто що скоїв дтп: ";
            cout << obj.name << endl;
        }
    }   
}


// int callMenu(struct Student * studentList)
int menu() {
    int option;

    cout << endl << "____________________________" << endl
    << "1. Вивести кількість постраждалих у ДТП в районі Х за у період часу від А до В(дата)." << endl
    << "2. Вивести ПІБ винуватців ДТП, де постраждалих найбільша кількість та ДТП, де не було постраждалих." << endl 
    << "3. Вихід з программи" << endl
    << "4. Створити ДТП" << endl;
    cin >> option;

    switch (option) {
    
    case 1: // Вивести кількість постраждалих у ДТП в районі Х за у період часу від А до В(дата).
        read();
        injuries(list, listSize);
        break;
    case 2: // Вивести ПІБ винуватців ДТП, де постраждалих найбільша кількість та ДТП, де не було постраждалих.
        read();
        name(list, listSize);
        break;
    case 3: // Вихід з программи
        return -1;
    case 4: //  Створити ДТП
        add();
        break;    
    }
    
    return 1; // Код корректного завершення функції
}

int main()
{
    SetConsoleCP(65001); 
    SetConsoleOutputCP(65001) ; // Встановлення кодування

    
    int ans = 0;
    while (ans != -1) {
        ans = menu();
    }
    
    return 0;
}
