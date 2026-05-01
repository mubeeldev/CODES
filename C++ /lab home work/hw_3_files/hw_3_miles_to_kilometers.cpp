#include <iostream>
using namespace std;

int main () {
    double miles;
    //collecting males from user
    cout<<"Enter Miles :";
    cin>>miles;

    cout<<endl;
    // converting miles to kilometers
    double kilometers = 1.609344 * miles;
    // printing the result in kilometers
    cout<< miles <<" miles is "<<kilometers<<" Kilometers"<<endl;

    return 0;
}