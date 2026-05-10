#include <iostream>
using namespace std;
int toSeconds(int minutes){
    return minutes * 60;
}
int main(){
    int m;
    cout << "Enter minutes: ";
    cin >> m;

    cout << "in second = "<< toSeconds(m) << endl;
    return 0;
}