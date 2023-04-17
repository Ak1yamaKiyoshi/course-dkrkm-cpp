#include "student.cpp"


int main() {

    /* Об'єкт  класу, демонстрація конструктора без параметрів */
    Student student; /* Конструктор без параметрів */
    student.set_name("Prokopenko"); /* Зміна імені */
    student.set_course(21); /* Зміна курсу. */
    student.set_sex(false); /* Зміна статі. див. this.sex. false == male, true == female */
    student.info(); /* Вивід данних студента з об'єкту класу */
    delete &student; /* Виклик деструктора класу */ 


    /* Вказівник на об'єкт класу Student, а також демонстрація роботи конструктора з параметрами */
    Student* student1 = new Student("Prokopenko1", 20, false);
    student1->info(); /* Вивід данних студента з вказівника на об'єкт класу */

    void (Student::*info)(); /* Створюємо вказівник типу Student::*info */
    info = &Student::info; /* Привласнюємо цьому вказівнику адресу функції Student::info */
    (student1->*info)(); /* Викликаємо функцію info з вказівника на об'єкт класу Student */

    delete student1; /* Виклик деструктора класу Student */

    return 0;
}