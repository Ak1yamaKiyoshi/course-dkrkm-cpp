#include "student.h"
#include <malloc.h>
#include <iostream>


Student::Student() {
    this->name = new char[50](); 
    std::cout << "\nClass constructor without parameters called\n";
};

Student::Student(char *name, int course, bool sex) {
    this->name = new char[50](); 
    Student::set_name(name);
    Student::set_course(course);
    Student::set_sex(sex);
    std::cout << "\nClass constructor with parameters called\n";
};

Student::~Student(){
    delete[] this->name;
    std::cout << "\nClass destructor called\n";
};

char *Student::get_name(){
    return this->name;
};

int Student::get_course(){
    return this->course;
};

bool Student::get_sex(){
    return this->sex;
};

void Student::set_name(char *name){
    strcpy(this->name, name);
};

void Student::set_course(int course){
    this->course = course;
};

void Student::set_sex(bool sex){
    this->sex = sex;
};

void Student::info() {
    std::cout 
    << "\nStudent course " << this->get_course() 
    << "\nStudent name " << this->get_name()
    << "\nStudent sex " << ((this->get_sex() == false) ? "male" : "female");
};