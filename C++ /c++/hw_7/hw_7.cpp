#include <iostream>
using namespace std;
int main(){
    char input;
    cout<<"Enter an oparation (+,-,/,%): ";
    cin>>input;

    int a,b;
    cout<<"Enter two numbers for calculation: ";
    cin>>a>>b;

    if(input == '+'){
        cout<<"Adding = "<<(a+b)<<endl;
    }else if(input == '-'){
        cout<<"Subtracting = "<<(a-b)<<endl;
    }else{
        cout<<"the oparation is not valid"<<endl;
    }

    // switch (input)
    // {
    // case '+':
    //     /* code */
    //     cout<<"Adding = "<<(a+b)<<endl;
    //     break;
    // case '-':
    //     cout<<"Subtracting = "<<(a-b)<<endl;
    //     break;
    
    // default:
    //     cout<<"the oparation is not valid"<<endl;
    //     break;
    // }
    return 0;
}