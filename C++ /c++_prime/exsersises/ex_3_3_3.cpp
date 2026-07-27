#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> score{1,2,3,4,5,6,7,8,9};
    for(auto i = score.cbegin(); i != score.cend(); ++i){
        cout << *i << ", ";
    } 

    cout << endl << score.size();

    return 0;
}