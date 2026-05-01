#include <iostream>
using namespace std;

int main(){
    double num;
    cout<<"*************************************"<<endl;
    cout<<"**********NUMBER DETACTORE***********"<<endl;
    cout<<"*************************************"<<endl;
    cout<<endl;
    cout<<"Enter Any Number : ";
    cin>>num;

    if(num > 0){
        cout<<"---------------------------------"<<endl;
        cout<<"      The number is positive"<<endl;
        cout<<"---------------------------------"<<endl;
    }else{
        cout<<"---------------------------------"<<endl;
        cout<<"      The Number is Negetive" << endl;
        cout<<"---------------------------------"<<endl;
    }

    return 0;
}