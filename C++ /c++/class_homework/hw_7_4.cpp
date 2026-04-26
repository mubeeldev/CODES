#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;
int main(){
    cout<<static_cast<char>(toupper('a'));
    cout<<static_cast<char>(toupper('s'));
    char c = static_cast<char>(toupper('m'));
    cout<<c;
    double x = 3.0;
    double y = 4.5;
    cout<<endl<<pow(x,y);
    double z = pow(x,y);
    double v=z+pow(x,y);
    cout<<endl<<z;
    cout<<endl<<v;
    return 0;
}