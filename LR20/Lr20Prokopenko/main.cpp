#include "cursour.cpp"


int main() {

    /* Об'єкт  класу, демонстрація конструктора без параметрів */
    Cursour cursour; /* Конструктор без параметрів */
    cursour.changeX(10);
    cursour.changeY(10);
    cursour.pos(); 
    delete &cursour; /* Виклик деструктора класу */ 

    /* Конструктор зі всіма параметрами */
    Cursour* cursour1 = new Cursour(240, 530, 1000, 1000); 
    cursour1->pos(); /* Виклик функії pos() з вказівника на об'єкт класу Cursour */
    cursour1->changeX(1331131); /* Демонстрація неправильно введених координат курсору */ 
    cursour1->changeY(1331131); /* Демонстрація неправильно введених координат курсору */ 

    void (Cursour::*pos)(); /* Створюємо вказівник типу Cursour::*pos */
    pos = &Cursour::pos; /* Привласнюємо цьому вказівнику адресу функції Cursour::pos */
    (cursour1->*pos)(); /* Викликаємо функцію pos з вказівника на об'єкт класу Cursour */

    delete cursour1; /* Виклик деструктора класу Cursour */

    /* Об'єкт  класу, демонстрація конструктора з двома параметрами */
    Cursour *cursour2 = new Cursour(200, 300); 
    cursour2->pos(); 
    delete &cursour2; /* Виклик деструктора класу */ 
    
    /* Демонстрація створення курсора на неправильній позиції (позиція курсора стане 0) */
    Cursour *cursour3 = new Cursour(130313131, 31232100, 10, 10); 
    cursour3->pos(); 
    delete &cursour3; /* Виклик деструктора класу */ 

    return 0;
}