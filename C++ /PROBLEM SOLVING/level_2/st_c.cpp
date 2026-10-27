#include<iostream>
#include <string>
using namespace std;
#define ARRAY_SIZE 3 //Array size is defined as global variable


class employee {
    private:
        int empID;
        string name;
        float salary; // data members
        char department[50];
        float part_Time;
        float Total_Income;
    public:
        employee(int id, string n, float sl,const char dpt[]){
            empID = id;
            name = n;
            salary = sl;
            for(int i = 0; i < 50; i ++){department[i] = dpt[i];}
    
        }
        void Calcu_part_Time(float hours){
             part_Time = hours * 100; 
            }

        void Calcu_Income(){
            Total_Income = salary + part_Time;
        }
        void Display(){
        cout << "The employee information is given as follows:" << endl;
        cout << endl;

        cout << "Employee ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary:$ " << salary << endl;
        cout << "Department: " << department << endl;
        cout << "Part Time:$ " << part_Time << endl;
        cout << "Total Income:$ " << Total_Income << endl;
        cout << endl;

        }
    }; // end struct definition

    int main(){
        employee e1(1234,"Idris",50000.50, "CS");
        e1.Calcu_Income();
        e1.Calcu_part_Time(5);
        e1.Display();
        

        // cout << "Please enter The employee information:" << endl;
        // cout << endl;
        // for (int i = 0; i < ARRAY_SIZE; i++) {
        // cout << "Enter Employee ID: ";
        // cin >> emp[i].empID;
        // cout << "Name: ";
        // cin >> emp[i].name;
        // cout << "Salary: ";
        // cin >> emp[i].salary;
        // cout << "Department: ";
        // cin >> emp[i].department;
        // cout << "Part Time working hours: ";
        // cin >> H;
        // emp[i].Calcu_part_Time(emp, i, H);
        // emp[i].Calcu_Income(emp, i);
        // cout << endl;
        //}
        // for (int i = 0; i < ARRAY_SIZE; i++)
        // {
        // emp[i].Display(emp , i);
        // }
        return 0;
} // end main