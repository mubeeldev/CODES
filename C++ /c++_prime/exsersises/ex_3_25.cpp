#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<unsigned> score(11 ,0);
    unsigned grade;
    while(cin >> grade){
        if(grade <= 100){
            ++score[grade/10];
        }if(grade == 0){break;};
    }
    for(auto ix = score.begin(); ix != score.end(); ++ix){
        cout << *ix << " ,";
    }
    return 0;
}