#include <iostream>
using namespace std;

int factorial(int number){
    int result = 1;
    for (int i = 1; i <= number; i++){
        result *= i;
    }
    return result;
}

int main() {
    int userNumber;

    cout << "Enter a Number : ";
    cin  >> userNumber;
    cout << "Factorial of: "<< userNumber << " = " << factorial(userNumber) << endl;

    return 0;
}