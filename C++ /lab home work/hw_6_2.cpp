#include <iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter max value: ";
    cin>>num;
    for(int i = 1; i > num ; i--){
        cout<<i<<"\t";
    }

    return 0;
}