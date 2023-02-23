#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

struct family {
    // 0 звичайний
    // 1 малозабезпечений 
    // 2 чорнобилець 
    // 3 інвалідність 
    // 5 багатодітний
    int category; 
    int num; // кількість членів сім'ї
    string area; // район 
    // 0 особистий дім
    // 1 багатоповерхівка
    // 2 барак 
    // 3 без помешкання
    int homeType; 
};

// Виведення даних сім'ї
void printFamily(family f) 
{
    cout << "Категорія: ";
    switch(f.category) {
        case 0:
            cout << "Звичайна категорія"; break;
        case 1:
            cout << "Малозабезпечена категорія"; break;
        case 2:
            cout << "Чорнобильска категорія"; break;
        case 3:
            cout << "Категорія з інавлідністю"; break;
        case 4:
            cout << "Багатодітна категорія"; break;
    }
    cout << endl << "Кількість членів сім'ї: " << f.num << endl;
    cout << "Район проживання: " << f.area << endl;
    cout << "Тип помешкання: ";
    switch (f.homeType)
    {
    case 0:
        cout <<"Особистий дім "; break;
    case 1:
        cout <<"Багатоповерхівка "; break;
    case 2:
        cout <<"Барак "; break;
    case 3:
        cout <<"Без помешкання "; break;
    }
    cout << endl;
}

// функція 1 Перелік сімей з найбільною кількістю мешканців району Х
void printByArea(family f[], int fLen) 
{
    string area; // Шуканий район 
    int largestFamily = 0; // Найбільша кількість членів сім'ї у відповідному районі 
    // Введення шуканого району 
    cout << "Введіть район(латинськими літерами):"; 
    getline(cin, area);
    
    // Пошук максимальної кількості членів сім'ї у структурах(сім'ях) відповідного району 
    for (int i = 0; i < fLen; i++) 
        if (f[i].area == area) // перевірка чи підходить район 
            if (f[i].num > largestFamily)  // перевірка чи кількість членів сім'ї більша за максимальну 
                largestFamily = f[i].num; // оновлення максимальної кількількості членів сім'ї

    for (int i = 0; i < fLen; i++) 
        if (f[i].area == area && f[i].num == largestFamily)  {
            cout << "\nCім'я номер "<<i << endl; 
            printFamily(f[i]);
        }
}

// функція 2 Перелік сімей з помешкання виду Х категорії Х
void printByHouseAndCategory(family f[], int fLen) 
{
    int category, houseType; // номер категорії та типу домівки для пошуку 
    // Введення шуканих категорії та домівки
    cout << "Введіть категорію:"; 
    cin >> category;
    cout << "Введіть тип житла:"; 
    cin >> houseType;
    
    // Перебір структур масиву структур f 
    for (int i = 0; i < fLen; i++) 
        if (f[i].homeType == houseType && f[i].category == category)  { // перевірка структури на відповідність шуканим категорії та типу домівки
            cout << "\nCім'я номер "<<i << endl; // Виведення номеру сім'ї у масиві структур
            printFamily(f[i]);// Вивід даних сім'ї у консоль 
        }
}


int main()
{
    SetConsoleCP(65001); // Встановлення кодування
    SetConsoleOutputCP(65001); // Встановлення кодування

    int f1Len = 7; // Довжина масиву структур
    // Масив структур 
    family f1[] = 
    {
        {1, 2, "Obolon", 0}, 
        {3, 4, "Obolon", 0},
        {3, 4, "Obolon", 0}, 
        {2, 3, "Obolon", 1}, 
        {2, 3, "Obolon", 1}, 
        {4, 6, "Obolon", 1},
        {4, 6, "Obolon", 1},
    };
    // Функції з завдання 
    //printByArea(f1, f1Len);
    printByHouseAndCategory(f1, f1Len);

    return 0;
}
