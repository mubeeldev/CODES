#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> num{1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < num.size()-1; ++i){
        cout << num[i] + num[i+1] << " ";
    }
    return 0 ;
}
