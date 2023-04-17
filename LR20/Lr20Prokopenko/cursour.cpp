#include "cursour.h"
#include <iostream>

/*
Поле first - ціле позитивне число, координата курсора / покажчика по горизонталі; 
поле second - ціле позитивне число, координата курсора по вертикалі. 
Реалізувати метод changex() - зміна горизонтальної координати курсору; 
реалізувати метод changey() - зміна вертикальної координати курсора. 
Методи повинні перевіряти вихід за кордон екрана.
*/
/* Constructor without parameters. 
    sets resolution (width, heigth) to 1080 720 
    sets cursour pos to 0 0 
*/

/*
TODO: Handle wrond cursour position (in set_something)
TODO: Change = to methods in constructor 
*/


Cursour::Cursour() {
    this->height = 720;
    this->width = 1080;
    this->first = 0;
    this->second = 0; 
    std::cout << "Cursour constructor without any parameters called\n";
};

/* Constructor with only cursour pos, without resolution (width, height) */
Cursour::Cursour(int first, int second) {
    this->height = 720;
    this->width = 1080;

    if (Cursour::checkIfCursourInScreen(first, second)) {
        this->first = first;
        this->second = second; 
    } else {
        this->first = 0;
        this->second = 0;
        std::cout << "Constructor. Cursour set to zero, because it's not on the screen\n";     
    }
};


/* Constructor with all parameters, pos and resolution (width, height, first, second )*/
Cursour::Cursour(int first, int second, int width, int height) {
    this->height = height;
    this->width = width;
    if (Cursour::checkIfCursourInScreen(first, second)) {
        this->first = first;
        this->second = second; 
    } else {
        this->first = 0;
        this->second = 0;
        std::cout << "Constructor. Cursour set to zero, because it's not on the screen\n";     
    }
    std::cout << "Cursour constructor with all parameters (x, y, height, width) called\n";
};

Cursour::~Cursour() {
    std::cout << "Cursour destructor called\n";
};

int Cursour::getX() {
    return this->first;
};
int Cursour::getY() {
    return this->second;
};

void Cursour::changeX(int x) {
    if (Cursour::checkIfCursourInScreen(x, this->second))
        this->first = x;
    else 
        std::cout << "ChangeX failed, cursour out of screen\n";
};

void Cursour::changeY(int y) {
    if (Cursour::checkIfCursourInScreen(this->first, y))
        this->second = y;
    else std::cout << "ChangeX failed, cursour out of screen\n";
};

void Cursour::pos() {
    std::cout << "pos = [" << this->getX() << ", " << this->getY() << "]\n"; 
}; 

bool Cursour::checkIfCursourInScreen(int first, int second) {
    /* if x and y >= 0, and x and y < width and height return true, otherwise false */
    return ( (first >= 0 && second >= 0) ? (first <= this->width && second <= this->height) ? true : false : false );
};