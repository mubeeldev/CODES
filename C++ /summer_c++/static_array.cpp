#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

int gradeNum = 0;

void storeGrade(int );
int bonus(int , int bonus = 1);
//main function
int main(){

    srand(time(0));
    for(int i = 0; i < 6; i++){
        int randomNumber = rand()% 100;
        storeGrade(randomNumber);
    }
    return 0;
}

void storeGrade(int grade){
    static int sum = 0;
    gradeNum ++;
    sum += grade;
    static int Array[5];
    Array[(gradeNum -1) % 5] = grade;
    grade = bonus(grade);
    cout << grade << "\t";

}
/*if you set the defoult value ones in the function prototype 
you no need to set it again */
int bonus(int g, int bonus){
    g+=bonus;
    return g;
}