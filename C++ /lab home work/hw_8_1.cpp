#include <iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter max value: ";
    cin>>num;
    for(int i = num; i > 0 ; i--){
        cout<<i<<"\t";
    }

    return 0;
}