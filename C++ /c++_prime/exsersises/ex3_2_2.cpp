#include <iostream>
#include <string>
using namespace std;

int main(){
    string line1 , line2;
    cout << " :> ";
    cin >> line1 >> line2;
    if(line1.size() > line2.size()){
        cout << "line one is greater than line 2!" <<  endl;
        
    } else if(line2.size() > line1.size()){
        cout << "line 2 is greater than line one " << endl;
        cout << "line one " << line1 << "," << "line2 " << line2 << endl;
    }else {
        cout << "line one and line2 are equal" <<  endl;

    }

    

    return 0;
}