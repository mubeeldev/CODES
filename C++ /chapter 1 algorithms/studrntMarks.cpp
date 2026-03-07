#include <iostream>

using namespace std;


int main(){
    double test_1 = 80;
    double test_2 = 90;
    double test_3 = 90;
    double test_4 = 70;
    double test_5 = 95;

    int sum = test_1 + test_2 + test_3 + test_4 + test_5;
    double average = sum / 5;

    cout << average <<'\n';
    double persentage = average/100;

    char grade;

    if(average >= 90){
        grade = 'A';
    }else if(average >= 80){
        grade = 'B';
    }else if(average >= 70){
        grade = 'C';
    }else{
        grade = 'F';
    }
cout <<"avrage in parsentage  "<<persentage <<'\n'; 
cout << grade <<'\n'; 

    return 0;
}