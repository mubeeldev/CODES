#include <iostream>
#include <string>
using namespace std;
int main(){
    double num;
    cout<<"Enter A Number 0-100 : ";
    cin>>num;

    string output = (num > 50 && num <= 100)? "Avrage is High"
                : (num <= 50 && num > 30)? "The Avrage is Medium"
                : (num <= 30)? "Avrage is Low!"
                : "Inverlid Entry";
    cout<<output <<'\n';
    return 0;
}