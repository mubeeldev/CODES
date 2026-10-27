#include <iostream>
#include "class.h"

myc::myc(){}
myc::myc(int xx){
    this->x = xx;
}
void myc::print(){
    std::cout << this->x << std::endl;
}