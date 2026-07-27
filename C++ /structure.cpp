#include <iostream>
using std::cin;
using std::cout;
struct fullname{
    char f_name[15];
    char l_name[15];
};
struct  Student{
    int id;
    fullname s_name;
    float GPA;
};
void printout( Student st_list[], int size);

int main(){
    int size;
    cout << "Enter amount of the dtudent : ";
    cin >> size;

    Student *st_list = new Student[size];
    for( int i = 0; i < size; i ++){
        cout << "Enter Student id : ";
        cin >> st_list[i].id;
        cout << "Enter Student first name : ";
        cin >> st_list[i].s_name.f_name;
        cout << "Enter Student last name : ";
        cin >> st_list[i].s_name.l_name;
        cout << "Enter Student GPA : ";
        cin >> st_list[i].GPA;
    }

    printout(st_list,size);
    delete[] st_list;
    return 0;
}
void printout( Student array[], int size){
    for( int i = 0; i < size; i ++){
        cout << "Student id : "<< array[i].id << "\t";
        cout << "Student first name : " << array[i].s_name.f_name << "\t";
        cout << "Student last name : "<< array[i].s_name.l_name << "\t";
        cout << "Student GPA : "<< array[i].GPA << "\t";
    }
}