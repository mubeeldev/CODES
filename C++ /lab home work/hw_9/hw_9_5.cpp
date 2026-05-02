#include <iostream>
#include <cmath>
using namespace std;

int main(){ 
    float a,b,c;
    float aPow, bPow;
    cout << "Enter a and b bslues: \n";
    cin >> a >> b;
    aPow = pow(a,a);
    bPow = pow(b,b);
    c = sqrt(aPow + bPow);
    cout << "Result = " << c << "\n";
    return 0;
}