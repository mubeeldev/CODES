#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

int readPositiveNumber(string message);
bool isPerfectNumber( int Number);
void printResult(int Number);

int main(){
    printResult(readPositiveNumber("Please Enter a Positive Number?"));
    return 0;
}
int readPositiveNumber(string message){
    int Number = 0;
    do{
        cout << message << "\n";
        cin >> Number;
    }while (Number <= 0);
    return Number;
    
}
bool isPerfectNumber( int Number){
    int sum = 0;
    for ( int i = 1; i < Number; i++){
        if(Number % i == 0){ sum += i;}
    }
    return Number == sum;
}
void printResult(int Number){
    if( isPerfectNumber(Number)){
        cout << Number << " Is Perfect Number. \n";
    }else{
        cout << Number << " Is NOT Perfect Number. \n";
    }
}
