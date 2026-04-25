#include <iostream>
#include <string>

using namespace std;
int main(){
    double mark;
    cout<<"Enter Your Mark: ";
    cin>>mark;
    string grade = (mark >= 90 && mark <= 100)? "A"
                :   (mark >= 80 && mark <= 90)? "B"
                :   (mark >= 70 && mark <=80)? "C"
                :   (mark >= 60 && mark <= 70)? "D"
                :   (mark < 60)? "F"
                : "invalid Entry!";
    cout<<"Your Grade is \" "<<grade<<"\""<<"\n";
    

    return 0;
}