#include <iostream>

using namespace std;
int main(){
    for(int i= 1;;i++)
    {
        if(i > 6)
            break;
        if(i%2==0)
            continue;
        cout<<i<<endl;
    }
    return 0;
}