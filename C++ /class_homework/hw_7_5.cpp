#include <iostream>
using namespace std;

int abs(int number){
    if(number <0){
        number = number;
    }
        return number;
    
}

int main(){
    cout<<abs(-5)<<endl;
    int f = abs(-8) + 6;
    cout<<f;
    return 0;
}