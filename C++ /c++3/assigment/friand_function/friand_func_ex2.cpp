#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Box{
    private:
        double length;
        double breadth;
        double height;
    public:
        Box(): length(0), breadth(0), height(0) {}
        Box insert_data( Box b);
        friend int print_valume (Box);
};
Box Box::insert_data(Box b){
    cout << "Enter length: ";
    cin >> this->length;
    cout << "Enter breadth: ";
    cin >> this->breadth;
    cout << "Enter height: ";
    cin >> this->height;
    return b;
}
int print_valume(Box b){
    return b.length * b.breadth * b.height;
}

int main(){
    Box box1;
    box1.insert_data(box1);
    cout << "Volume of box1: " << print_valume(box1) << endl;
    system("pause > 0");    
}