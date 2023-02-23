#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h> 

using namespace std;

int main()
{
    SetConsoleCP(65001); // Ukranian localization for input
    SetConsoleOutputCP(65001); // Ukranian localization for output

    fstream file; // file
    string line; // buffer for reading lines from file 
    int rows; // rows in file 
    char c; // specific character
    string lessSpecCharStr; // string that contains minimum amount of specific characters in the end of the words
    // counters 
    int minCounter = 9999999; // counter for words that ends with specific character
    int nowCounter; // current (in cycle) counter for words that ends with specific character

    // entering no of rows
    cout << "Введіть кількість рядків у файлі: ";
    cin >> rows; 
    // opening the file 
    cout << "Введіть рядки" << endl;
    file.open("Novofastovskiy.txt", ios::out);
    if (file.is_open()) { // check if file is opened
        // entering lines in file  
        for (int i = 0; i < rows; i++) {
            cout << "рядок #" << i << ": " << endl;  
            cin.sync();
            getline(cin, line);
            file << line << endl;
        }        
        file.close(); 
    }

    // find specific chara
    cout << " Введіть символ на який повинні закінчуватись слова які будуть рахуватись\n--символ: ";
    cin >> c;
    file.open("Novofastovskiy.txt", ios::in);
    if (file.is_open()) { // check if file is opened
        while(getline(file, line)) {
            nowCounter = 0;
            for (int i=0; i<=line.length(); i++) { // check every element
                if (isalpha(line[i]) && line[i] == c && line[i-1] == ' ') {
                    nowCounter++;
                }
            }
            if (nowCounter < minCounter && nowCounter > 0) {
                minCounter = nowCounter;
                lessSpecCharStr = line; // saving line for later
            }
        }
        file.close(); 
    }

    if (minCounter != 0) {
        cout << "Рядок з найменшою кількістю слів які закінчуються на шуканий елемент" << endl
        << lessSpecCharStr << endl;
    }
    else {
        cout << " Не було знайдено жодного слова у всіх рядках який би закінчувався на шуканий елемент" << endl;
    }

    return 0;
}
