#include <iostream>
#include <string>

using namespace std;

int main() {

    const int No_STUDENTS = 50;
    const double CONVERSION = 2.54;
    const char BLANK = ' ';

    signed int temprature = 33.5; //floating point to interger, what will happen?
    unsigned short int salary = 5255;
    string name = "Mohammed Alhassan";

    cout<<"NO OF STUDENTS = "<<No_STUDENTS<<" CONVERSION = "<<CONVERSION<<" BLANK = "<<BLANK<<endl;
    cout<<"temperature = "<<temprature<<endl;
    cout<<"salary = "<<salary<<endl;
    cout<<"name = "<<name<<endl;

    return 0;
}