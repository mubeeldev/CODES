#include <iostream>
using namespace std;
#include <cmath>

int absoluteValue(double value){
    return abs(value);
}

int main(){
    int num;
    cout << "Enter num: " << "\n";
    cin >> num;
    cout << endl;
    cout << "abs of " << num << " is " << absoluteValue(num) << "\n";
    return 0;
}