#include <iostream>

using namespace std;

int main() {
    int x,y;

    cout<<"\\Enter\n two\t omtergers\b: ";
    cin>> x >> y;
    
    cout<<"x++="<<x++<<endl; // print x then add 1 x=6
    cout <<"++x = "<< ++x << "\n";

    int sum = x++ +7;
    cout <<"sum = " <<sum <<endl;

    sum = ++x +7;
    cout <<"sum = " <<sum <<endl;
    

    int sub = x-- + 7;
    cout << "sub = "<<sub <<endl;

    sub = --x + 7;
    cout << "sub = "<<sub <<endl;

    cout << endl;
    cout <<"x="<<x<<" y="<<y;


    return 0;
}