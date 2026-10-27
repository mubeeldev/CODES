#include <iostream>
#include "CreateAnDestroy.h"
using std::cout;
void create(void);
CreateAnDestroy::CreateAnDestroy(int ID, string messageString){
    objectID = ID;
    message = messageString;
    cout << "object " << objectID << " constractore runs   " << message << "\n";
}
//distractore
CreateAnDestroy::~CreateAnDestroy(){
    cout <<(objectID == 1 || objectID == 6 ? "\n" : "");
    cout << "Object " << objectID << " destractore runs  " << message << "\n";
}
void create(void);
CreateAnDestroy first(1,"(global befor main)");
int main(){
    cout << "\nMAIN FUNCTION EXECUTION BEGINS"<< "\n";
    CreateAnDestroy second(2, "(local automatic in main)");
    static CreateAnDestroy third(3,"(local static in main)");

    create();

    cout << "\nMAIN FUNCTION EXECUTION BEGINS"<< "\n";
    CreateAnDestroy furth(4, "(local automatic in main)");
    cout << "\nMAIN FUNCTION EXECUTION BEGINS"<< "\n";

    
    return 0;
}
void create(void){
    cout << "\nMAIN FUNCTION EXECUTION BEGINS"<< "\n";
    CreateAnDestroy fifth(5,"(local automatic create)");
    static CreateAnDestroy sixth(6,"(local static create)");
    CreateAnDestroy seventh(7,"(local automatic in create)");
    cout << "\nMAIN FUNCTION EXECUTION BEGINS"<< "\n";
    
}