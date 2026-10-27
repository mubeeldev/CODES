#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Rectangle {
    private:
        int length;
        int width;
    public:
        Rectangle() {
            cout << "Enter length: " ;
            cin >> this->length;
            cout << "Enter width: ";
            cin >> this->width;
            
        }
        friend int area(Rectangle);
};
int area(Rectangle r) {
    return r.length * r.width   ;
}
int main() {
    Rectangle rect;
    cout << "Area of rectangle: " << area(rect) << endl;
    system("pause > 0");
}