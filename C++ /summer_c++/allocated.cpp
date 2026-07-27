#include <iostream>
#include <string>

using std::cin;
using std:: cout;
using std::string;


void createArray();
int main(){
    const char * weekdays[7] = {"Monday","Tuesday","Wedneasday","Thousday","Friday","Satday","Sunday"};
    for ( int i = 0; i < 7; i++){
        cout << weekdays[i] << "\n";
    }
    // createArray();
    return 0;
}

void createArray(){
    int* array = new int[10];
    for(int i = 0; i < 10; i++){
        cout << " Enter the value : ";
        cin >> array[i];
    }
    delete[] array;
}
