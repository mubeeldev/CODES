#include <iostream>
using namespace std;


int main() {
    cout <<"Line 1:";
    cout << "A\nB\nc\n" <<endl;

    cout << "Line 2: ";
    cout <<"A\tB\tC\t" << endl;

    cout << "Line 3: ";
    cout <<"A\\B\\C\\" << endl;

    cout << "Line 4: ";
    cout <<"\'A\'"<<"\t"<<"\"B\"" << endl;

    cout<<"--------------------------------------------------------------------------"<<endl;

    int value = 10,x,y,z;

    x = value++;
    cout<< "x = "<< x <<endl;

    y = ++value;
    cout << "y = "<< y << endl;

    z = --value;
    cout <<"z = "<< z << endl;

    cout<<"--------------------------------------------------------------------------"<<endl;

    int fahrenheit;
    int celsius;

    cout << "Enter Temprature in fahrenheit: ";
    cin >> fahrenheit;

    cout <<endl;
    celsius = 5/9 *(fahrenheit-32);
    cout << "fahrenheit: "<< fahrenheit << " degree F"<<endl;
    cout << "celsius: "<< celsius << " degree C° "<<endl;

    cout<<"--------------------------------------------------------------------------"<<endl;

   



    



    return 0;
}