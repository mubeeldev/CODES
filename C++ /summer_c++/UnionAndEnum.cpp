#include <iostream>
using std::cout;
using std::endl;
using std::cin;

enum statua { 
    success = 1, 
    failure, 
    unknown 
};
union st_id {
    int id;
    char name[20];
};
struct student {
    st_id id;
    st_id name;
    unsigned int grade;
};
//outprint function prototype
void printStudentInfo(const student &s);
int main(){
    student s_list[3];
    for(int i = 0; i < 3; i++){
        cout << "Enter the student id : ";
        cin >> s_list[i].id.id;
        cout << "Enter the student name : ";
        cin >> s_list[i].name.name;
        cout << "Enter the student grade : ";
        cin >> s_list[i].grade;
    }
    printStudentInfo(s_list[0]);
    return 0;
}
void printStudentInfo(const student &s){
    cout << "Student id : " << s.id.id << endl;
    cout << "Student name : " << s.name.name << endl;
    cout << "Student grade : " << s.grade << endl;
}