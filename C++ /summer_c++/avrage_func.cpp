#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int input();
void average(int,int);
void outprint(float);

int main(){
    int total = input();
    average(total,3);

    return 0;
}
int input(){
    cout << "Enter three numbers: ";
    int a,b,c;
    cin >> a >> b >> c;
    return a+b+c;
}
void average(int sum, int count){
    float avg = sum/count;
    outprint(avg);
}

void outprint(float num){
    cout << "the average of thee numbers is : "<< num << endl;
}