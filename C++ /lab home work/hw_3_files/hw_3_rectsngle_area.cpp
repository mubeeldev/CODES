#include <iostream>

using namespace std;

int main() {
    cout <<"find the rectangle area"<< endl;

    int angle_a ;
    int angle_b;

    int area;
    int perimeter;

    //collecting angle values from the user
    cout << "Enter a and b : ";
    cin >> angle_a >> angle_b;

    //calculation the area and perimeter of the angle
    cout << endl;
    area = angle_a * angle_b;
    perimeter = 2*(angle_a + angle_b);


    //printing the result of given angle
    cout <<" Area Of Rectangle =  "<< area <<"\n"<<" Perimeter Of Rectangle = "<< perimeter << "\n";
    return 0;
}