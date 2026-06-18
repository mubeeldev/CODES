#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main () {
    vector<unsigned> scores(10,0);
    unsigned grade;
    while (cin >> grade){
        if(grade < 100) {
            ++scores[grade/10];
        }
        // for(auto &score :scores){
        //     cout << score << " ";
        // }
    };
    
 
    
    return 0;
}