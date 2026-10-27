#include <iostream>
using std::string;
using std::cout;
using std::endl;

class classB;
class classA {
    private:
        int numA;
    public:
        classA ( int a ){
            // this constructore to assign numA = a
            this->numA = a;
        }
        friend int add(classA, classB);
};
class classB {
    private:
        int numB;
        friend int add(classA,classB);
    public:
        classB( int b ){
            //this constructore to assign numb = b
            this->numB = b;
        }
    };

//acces members of the a classes
// wiite friend function to add numA and numB
int add(classA const a, classB  const b){
    return a.numA + b.numB;
}
int main(){
    classA objA(6);
    classB objB(10);
    std::cout << add(objA, objB) << std::endl;  
    system("pause > 0");
}