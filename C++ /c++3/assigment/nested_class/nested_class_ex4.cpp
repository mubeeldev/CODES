#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define size 2
class Student{
    private:
        string name;
        string Courses_name[size];
        int Courses_Credit_unit[size];
        float Courses_Garde[size];
        float GPA;
        // member methods
    public:
        // constructor
        Student();
        void Set_Name();
        void Set_Course_Name();
        void Set_Course_Garde();
        void Set_Course_Unit();
        void Cal_GPA();
        void Input_Data();
        void Display();

        string getName() const { return this->name; }
        string getCoursesName(int index) const { return this->Courses_name[index]; }
        int getCoursesCreditUnit(int index) const { return this->Courses_Credit_unit[index]; }
        float getCoursesGrade(int index) const  { return this->Courses_Garde[index]; }
};
Student::Student(){}
void Student::Set_Name(){
    cout << "Enter Student Name : ";
    getline(cin,this->name);
}
void Student::Set_Course_Name(){
    for(int i = 0; i < size; i++){
        cout << "Enter Course Name [ " << i+1 <<" ] :";
        getline(cin,this->Courses_name[i]);
    }
}
void Student::Set_Course_Garde(){
    for(int i = 0; i < size; i++){
        cout << "Enter Course [ " << this->getCoursesName(i) << " ] Grade : ";
        cin >> this->Courses_Garde[i];
        cin.ignore();
    }
}
void Student::Set_Course_Unit(){
    for(int i = 0; i < size; i++){
        cout << "Enter Course [ " << this->getCoursesName(i) << " ] Credit Unit : ";
        cin >> this->Courses_Credit_unit[i];
        cin.ignore();
    }
}
void Student::Cal_GPA(){
    for(int i = 0; i < size; i++){
        if(this->Courses_Garde[i] >= 95 && this->Courses_Garde[i] <= 100){
            this->GPA = 5.0;
        }else if(this->Courses_Garde[i] >= 90 && this->Courses_Garde[i] < 95){
            this->GPA = 4.7;
        }else if(this->Courses_Garde[i] >= 85 && this->Courses_Garde[i] < 90){
            this->GPA = 4.3;
        }else if(this->Courses_Garde[i] >= 80 && this->Courses_Garde[i] < 85){
            this->GPA = 3.7;
        }else if(this->Courses_Garde[i] >= 75 && this->Courses_Garde[i] < 80){
            this->GPA = 3.3;
        }else if(this->Courses_Garde[i] >= 70 && this->Courses_Garde[i] < 75){
            this->GPA = 2.7;
        }else if(this->Courses_Garde[i] >= 65 && this->Courses_Garde[i] < 70){
            this->GPA = 2.3;
        }else if(this->Courses_Garde[i] >= 60 && this->Courses_Garde[i] < 65){
            this->GPA = 1.7;
        }else if(this->Courses_Garde[i] >=0 && this->Courses_Garde[i] <60){
            this->GPA = 0;
        }else{
            cerr <<"something is wrong "<<endl;
        }
    }
}
void Student::Input_Data(){
        this->Set_Name();
        this->Set_Course_Name();
        this->Set_Course_Unit();
        this->Set_Course_Garde(); 
}
void Student::Display(){
    cout << "---------------------------------------------\n";
    cout << "Student Name : " << this->name << endl;
    for(int i = 0; i < size; i++){
        cout <<"Courses Name: " <<  this->getCoursesName(i)
        << "\n Course Credit Unit: " << this->getCoursesCreditUnit(i)
        << "\n Course Grade: " << this->getCoursesGrade(i)
        << "\n ---------------------------------------------";
        cout << setw(5) << "\n Courses GPA: "<< this->getCoursesGrade(i) 
        << "\n-------------End of Student Info---------------"
        << "\n ---------------------------------------------"<< endl;
    }
}
int main()
{
    Student S_arr[size];
    for (int n = 0; n < size; n++)
        S_arr[n].Input_Data();

    for (int n = 0; n < size; n++)
        S_arr[n].Display();

    system("pause > 0");
}