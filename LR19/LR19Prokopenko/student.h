#pragma once
#include <string.h>

/* Student class, that contains basic student info like name, course and sex. */
class Student
{
private:
    char *name; /* student name, cannot be bigger than 50 charachters long */
    int course; /* student course, can be any number  */
    bool sex; /* student sex, false - male, true - female */ 
public:
    /* Class constructor without parameters */
    Student();
    /* Class constructor with parameters */
    Student(char *name, int course, bool sex);
    /* Class destructor */
    ~Student();
    /* get student name, returns this->name */
    char *get_name();
    /* get student course, returns this->course */
    int get_course();
    /* get student sex, returns this->sex */
    bool get_sex();
    /* set student name, this->name = name */
    void set_name(char *name);
    /* set student course, this->course = course */
    void set_course(int course);
    /* set student sex, this->sex = sex */
    void set_sex(bool sex);
    /* Prints student info */
    void info();
};
