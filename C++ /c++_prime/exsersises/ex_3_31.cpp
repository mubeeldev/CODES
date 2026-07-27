#include <iostream>
#include <vector>

using namespace std;

int main(){
    int array[10] = { };
    vector<int> varray = {};
    
    for(auto i : array){
        array[i] = 5;
        varray.push_back(array[i]);
        cout << array[i] << " ";
    }
    cout << endl;
    for(auto i :varray){
        cout << i << " ";
    }

    return 0;
}