#include <iostream>
#include <string>
using namespace std;
int main(){
    int x =10;
    string result = x >= 0 ? "true" : "false";
    cout << "result = "  << result<<endl;

    string resultx = x >= 0 ?  x == 10?
        "x  equal to 10" : "x not equal to 10"
        : "false";

    cout<< "result" << resultx<<endl;

    return 0;
}