#include <iostream>
#include <string>
#include <vector>
using namespace std;

void AddStudent(){
        cout <<"......................................................." << endl;

    cout << "coming soon" << endl;
}
void ShowStudent(){
        cout <<"......................................................." << endl;

    cout << "coming soon" << endl;
}
void DeleteStudent(){
        cout <<"......................................................." << endl;

    cout << "coming soon" << endl;
}

int main(){
    vector<string> students = {"Rakhan Harbi","Mohammed Iswam","Ali Arini","Abdul-hakim As'ab"};
    string oprations[] = {"Exit","Add Student","Show Student","Delete Student"};
    int nomOfStudents = sizeof(students)/sizeof(students[0]);
    int nomOfOprations = sizeof(oprations)/sizeof(oprations[0]);


    string command;
    cout << "============STUDENTS MANAGEMENT SYSTEM================"<<endl;
    cout << " Sellect Opretion By number Or Type The Opration Name " << endl;
    cout << "------------------------------------------------------"<<endl;

    while (true){
        for(int i = 0; i <= nomOfOprations-1; i++){
            cout << i << " " << oprations[i]<< endl;
        }
        cout << "Opration : ";
        getline(cin, command);

        if(command == "0" || command =="Exit" || command == "exit" || command == "EXIT"){
            cout << "Good bye !!" << endl;
            break;
        }
        if(command == "1" || command =="Add Student" || command == "add student" || command == "ADD STUDENT"){
            AddStudent();
        }
        else if(command == "2" || command =="Show Student" || command == "show student" || command == "SHOW STUDENT"){
            ShowStudent();
        }
        else if(command == "3" || command =="Delete Student" || command == "delete student" || command == "DELETE STUDENT"){
            DeleteStudent();
        }
        else {
            cout << "please enter the valid input!" << endl;
        }
        
        cout <<"```````````````````````````````````````````````````````" << endl;
    }
    


    return 0;
}