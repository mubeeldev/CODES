#include <iostream>
#include <string>
using namespace std;
int main(){
    int age;
    cout<<"Enter your Age :";
    cin>>age;
    string message  = (age >= 18 && age <= 70)? "Eligible to drive! and income > 3000"
                        : "you cant drive im sorry! ";
    cout<< message <<endl;

    return main();
}