#include <iostream>
using std::cout;

class Date{
private:
    int day , month,year;
public:
    Date(int d = 1, int m = 1, int y = 2000){
        day = d;
        month = m;
        year = y;
    }
    ~Date(){}
    void setday(int d){
        day = d;
    }
    void setmonth(int m){
        day = m;
    }
    void setyear(int y){
        day = y;
    }
    int getday(){
        return day;
    }
    int getmonth(){
        return month;
    }
    int getyear(){
        return year;
    }
    bool compeare(Date another){
        if (year < another.year){
            return true;
        }
        else if (year == another.year && month < another.month){
            return true;
        }
        else if (year == another.year && month == another.month && day < another.day){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        cout << day << "/" << month << "/" << year;
    }
};
class student{
private:
    std::string name;
    int id ;  
    Date birthdate;
public:
    student(std::string n = "unknown", int i = 0, Date b = Date()){
        name = n;
        id = i;
        birthdate = b;
    }
    ~student(){}
    void setname(std::string n){
        name = n;
    }
    void setid(int i){
        id = i;
    }
    void setbirthdate(Date b){
        birthdate = b;
    }
    std::string getname(){
        return name;
    }
    int getid(){
        return id;
    }
    Date getbirthdate(){
        return birthdate;
    }
    void print(){
        cout << "Name: " << name << "\nID: " << id << "\nBirthdate: ";
        birthdate.print();
    }
};  



int main(){
    student s1("Alice", 12345, Date(15, 6, 2000));
    s1.print(); 
    student s2("Bob", 67890, Date(20, 12, 1999));
    cout << "\n\n";
    s2.print();
    cout << "\n\n";
    if (s1.getbirthdate().compeare(s2.getbirthdate())){
        cout << s1.getname() << " is younger than " << s2.getname() << "\n";
    }
    else{
        cout << s1.getname() << " is older than " << s2.getname() << "\n";
    }

    return 0;
}