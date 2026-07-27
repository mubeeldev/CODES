#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main () {
    unsigned scores[11] = {};
    unsigned grade;
    while(cin >> grade){
        if(grade <= 100){
            ++scores[grade/2];
        }
    }
    for(auto i :scores){cout << i << " ";} cout << endl;

    return 0;
}