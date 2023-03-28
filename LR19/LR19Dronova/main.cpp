#include <iostream>
#include <cstring>

using namespace std;

class Product{
private:
    char* name;  // поле класса, которое представляет название виробу
    char* type;  // поле класса, которое представляет шифр виробу
    int number;  // поле класса, которое представляет количество виробу

public:
    Product(const char* name, const char* type, int number) {  // (2) Class constructor with 3 fields 
        this->name = new char[strlen(name) + 1]; 
        strcpy(this->name, name); 

        this->type = new char[strlen(type) + 1]; 
        strcpy(this->type, type); 
        
        this->number = number; 
        cout << "Product class constructor called\n"; // (7) print when constructor is called 
    }


    Product() {  // (2) Class constructor with no fields 
        this->name = new char[50](); // initialize with zeros 
        this->type = new char[50](); // initialize with zeros 
        cout << "Product class constructor called\n"; // (7) print when constructor is called 
    }


    ~Product() {  // (3) Class destructor 
        delete[] name; 
        delete[] type; 
        cout << "Product class destructor called\n"; // (7) print when destructor is called 
    }

    
    /* (4) Prints to console product name, type and number 
    */
    void info() const { std::cout << " Name: " << name << " type: " << type << " number: " << number << std::endl; }


    /* (4) set name
    * @param name name of product to set 
    * @return void 
    */
    void setName(const char* name) {
        strcpy(this->name, name); 
    }


    /* (4) set product type  
    * @param type type of product to set 
    * @return void 
    */
    void setType(const char* type) {
        strcpy(this->type, type); 
    }


    /* (4) set product number  
    * @param number number of product to set  
    * @return void 
    */
    void setNumber(int number) {
        this->number = number; 
    }

};


int main() {

    Product product1;
    product1.setName("Keyboard");
    product1.setType("SHA256");
    product1.setNumber(5);
    product1.info(); 
    delete &product1; // (7) demo programm to show how works constructor && destructor


    /* (6) Pointer to class object  */
    /* (8) pointer on class object use */
    Product* product = new Product();
    product->setName("Mouse");
    product->setType("DEF456");
    product->setNumber(15);
    product->info();

    /* (5) pointer to member function (method) */
    /* (8) pointer on member function use */
    void (Product::*info)() const; // make signature 
    info = &Product::info; // copy method 
    (product1.*info)(); // call method 

    delete product; // (7) demo program to show how works constructor && destructor
    
    return 0;
}
