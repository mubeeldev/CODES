#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

void outprint(int,int);
void printarray( int[], string[] ,int );
int main(){

    // getting amount of the student from user
    cout << " Enter student amount : ";
    int students_size;
    cin >> students_size;

    // student name and grades list
    int student_grades[students_size];
    string students_name[students_size];

    // adding grade to student grades list
    for(int i = 0; i < students_size; i++){
        cout << "Enter Student Name: ";
        cin >> students_name[i];
        cout << endl << "Enter The Student Grade: ";
        cin >> student_grades[i];
    }

    int total = 0;
    // print grade and return the total students grade
    for(int i = 0; i < students_size; ++i){
        total += student_grades[i];
    }

    // find the max and min grades
    int max = student_grades[0];
    int min = student_grades[0];
    for(int i = 1; i < students_size; i++){
        if( student_grades[i] > max){
            max = student_grades[i];
        }
        else if (student_grades[i] < min){
            min = student_grades[i];
        }
    }

    //calling print array function by passing array rafrence and value of array sixe
    printarray(student_grades,students_name,students_size);
    // printout the max and min
    cout << "max: "<< max << " min : " << min << endl;
    /* calling printout funcrtion that print the avrage and sum
    by passing sum of the grade and lenght og the grades */
    outprint(total,students_size);
    return 0;
}
// outprint sum and average
void outprint(int sum, int size){
    float average =  sum/size;
    cout << "The Sum Of The Students Grade is : " << sum << endl;
    cout << "The Average Of Students Grade is : " << average << endl;

}
//out print all the numers of the student
void printarray(int grade[], string name[], int size){
    cout << "```````````````````````STUDENT GRADES```````````````````````````" << endl;
    cout << setw(5) << " Name " << setw(15)<< "Grade" << endl;
    for( int i = 0 ; i < size; i++){
            cout << setw(3) << i+1 << " " << name[i] << setw(10)<< grade[i] << endl;
    }
}