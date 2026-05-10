#include <iostream>
#include <string>
using namespace std;


    void print(double);
    void printt(double y);

    double sum(int d, int e){
        return d+e;
    }
    double sum(int d, int e, int w){
        return sum(d,sum(e,w));
    }

int main() {
    double r = 8.2;
    int a = 6, b = 8, q = 80;
    print(sum(5,3,4));
    printt(r+5);
    double x = sum(a,b,q);
    cout << "x= " << x << "\n";
    double z = 5 + sum(a,b,3);
    cout << "z = " << z << "\n";
    cout << "sum fun call result = "<<sum(a,3,4) << "\n";

    void print(double y){
        cout << "hello y = "<< y << "\n";
    }
}