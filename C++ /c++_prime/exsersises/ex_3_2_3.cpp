#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){


    string line = "salaghabi!!xeeamdeey";
    string result = "";

    for(char &li : line){
        if(!ispunct(li)){
            result += li;
        }
        // li = 'x';
    }
    cout << result << endl;
    
    
    return 0;
}