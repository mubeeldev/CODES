#include <iostream>
using namespace std;
int main() {
    double score;

    cout<<"Enter your score:";
    cin>>score;

    if(score >= 60){
        cout<<"Pass";
    }else{
        cout<<"fail"<<endl;
    }
    return 0;
}