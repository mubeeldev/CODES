#include <iostream>
using namespace std;
int main() {
    int x = 10;

    if (x > 5) {
        cout<<"x is greater than 5 "<<endl;
    }
    if (x % 2 == 0) {
        cout<<"x is even"<<endl;
    }
    if (x % 2 == 1) {
        cout<<"x is odd"<<endl;
    }
    if (x < 0) {
        cout<<"x is negetive"<<endl;
    }
    if (x *x >= x-x) {
        cout<<"(x * x) grater than or equal (x + x)"<<endl;
    }

    return 0;
}