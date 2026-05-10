#include <iostream>
#include <string>
using namespace std;

int r = 10;

int main(){
    int r = 5;
    {
        int r = 5;
            cout << "r " << r << "\n";
            cout << "r " << ::r << "\n";
    }
    cout << "r "<< r <<"\n";

    return 0;
}