#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Aarea{
    private:
        int area;
        int length;
        int width;
    public:
        Aarea(int l, int w) : length(l), width(w) {}
        friend int getArea(Aarea a);
};

int getArea(Aarea a) {
    return a.area =  a.length * a.width;
}
int main(){
    cout << "Enter length and width of rectangle: ";
    int length, width;
    cin >> length >> width;
    Aarea rect(length, width);
    cout << "Area of rectangle: " << getArea(rect) << endl;
}