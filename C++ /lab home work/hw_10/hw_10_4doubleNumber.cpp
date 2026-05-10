#include <iostream>
using namespace std;

int doubleNumber(int number){
    return number * 2;
}

int main(){

    int userNumber;
    cout << "Enter a Number : ";
    cin >> userNumber;

    cout << "The double of " << userNumber << " = " << doubleNumber(userNumber) << endl;

    return 0;
}