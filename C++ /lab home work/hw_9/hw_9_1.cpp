#include <iostream>
#include <cmath>

using namespace std;
int main(){

    int base;
    int power;
    double result;
    cout << "===================================================" << endl;
    cout << "             WELCOME TO POWER CALCULATOR" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "       autho: Muhammed alhassan id: 471116625" << endl;
    cout << "---------------------------------------------------" << endl;


    cout << "Enter base then power : ";
    cin >> base >> power;
    result = pow(base,power);
    cout <<"result = "<<result << endl;
    return 0;
}