#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

void grades( const int *, int ); // function prototype 
double avrage(int, int, int); // function prototype

int main() {
    srand( time(0) );
    int array[10]; // array of 10 element
/*  for(int i = 0; i < 10; i++){
        cout << "Enter 10 int numbers : ";
        cin >> array[i];
    } */
    int i = 0; // counter base
/*    while (i < 10){
        cout << "Enter int numbers "<< i+1 << ": ";
        cin >> array[i];
        i++;
    } */
/*    do{
        cout << "Enter int numbers "<< i+1 << ": ";
        cin >> array[i];
        i++;
    } while (i < 10); */
    
/*    char string[5][15]; // 2D array of 5 char
    for(int i = 0; i < 5; i++){
        cout << "Enter name number "<< i+1 << ": ";
        for(int j = 0; j < 15 ; j++){
            cin >> string[i][j];
        }
    } */
    int grades[40];
    while (i < 40){
        int grade = (grades[i] = rand() % 100);
        i++;
    /*    if(grade >= 90){ cout << "A+" << "\t"; }
        else if( grade >= 80){ cout << " B+" << "\t"; }
        else if( grade >= 70 ) { cout << "C+" << "\t"; }
        else if( grade >= 60 ) { cout << "D+" << "\t"; }
        else{ cout << "F9‼️" << "\t"; } */
        switch (grade / 10)
        {
        case 9:
            cout << grade << " A+" << "\t";
            break;
        case 8:
            cout << grade << " B+" << "\t";
            break;
        case 7:
            cout << grade << " C+" << "\t";
            break;
        case 6:
            cout << grade << " D+" << "\t";
            break;
        default:
            cout << grade << " F9‼️" << "\t";
            break;
        }
    }
    
    
    return 0;
}
double avrage(int x, int y, int z ){
    int sum = x + y + z;
    double avr = static_cast <double>( sum )/3;
    return avr;
}