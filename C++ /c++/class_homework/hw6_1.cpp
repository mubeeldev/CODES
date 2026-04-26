#include <iostream>
using namespace std;
int main(){
    int x;
    cout <<"Enter a mark: ";
    cin>>x;
    switch (x)
    {
    case 90:
        cout<<"A"<<endl;
        break;
    case 82:
    case 81:
    case 80:
        cout<<"B";
    
    default:
        cout<<"invalid number"<<endl;
        break;
    }

    return 0;
}