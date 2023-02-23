#include <iostream>
#include <string.h>
#include <windows.h>

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

int listSize=0;
dtp list[20];


// Створення нового об'єкту структури dtp
dtp add() 
{
    dtp obj; 
    cout << ">| Введіть район дтп: ";
    cin.sync(); getline(cin, obj.area);
    cout << ">| Введіть ім'я власника авто що скоїв дтп: ";
    cin.sync(); getline(cin, obj.name);
    cout << ">| Введіть кількість постраждалих: ";
    cin.sync(); cin >> obj.num; 
    cout << ">| Введіть дату через пробіл - день місяць рік\n>|-наприклад: 29 10 2022 \n>|-Ввід: ";
    cin.sync(); cin >>  obj.date.day >> obj.date.month >> obj.date.year;
    cout << endl;
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
    << "3. Вихід з программи" << endl;
    cin >> option;

    switch (option) {
    
    case 1: // Вивести кількість постраждалих у ДТП в районі Х за у період часу від А до В(дата).
        injuries(list, listSize);
        break;
    case 2: // Вивести ПІБ винуватців ДТП, де постраждалих найбільша кількість та ДТП, де не було постраждалих.
        name(list, listSize);
        break;
    case 3: // Вихід з программи
        return -1;
    }
    return 1; // Код корректного завершення функції
}

int main()
{
    SetConsoleCP(65001); 
    SetConsoleOutputCP(65001) ; // Встановлення кодування
    list[0] = {"Synelnikovskiy", "Petrov Peter", 3, {12, 5, 2022}};
    list[1] = {"Synelnikovskiy", "Oleg Oleg",    0, {5, 6, 2022}};
    list[2] = {"Synelnikovskiy", "Hto to tam",   4, {3, 7, 2022}};
    list[3] = {"Synelnikovskiy", "Hto to tam",   3, {21, 8, 2022}};
    listSize = 5;
    
    int ans = 0;

    while (ans != -1) {
        ans = menu();
    }

    return 0;
}
