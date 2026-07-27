#include <iostream>
using std::cout;

int countCall();
int main(){
    for(int i = 0; i < 3; i++){
        countCall();
        
    }

    return 0;
}
int countCall(){
    static int callCount[1] = {0};
    callCount[0] ++;
    cout << callCount[0];
    return callCount[0];
}