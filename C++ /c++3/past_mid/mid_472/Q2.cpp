#include <iostream>
using std::cout;
#include <string>
using std::string;

class Course{
    private:
        string title;
        string instructor;
        int credit;
    public:
        Course(string t = "unknown ", string i = "unknnown " , int c = 0){
            this->title = t;
            this->instructor = i;
            this->credit = c;
        }
        // Course(string t, string i, int c){
        //     title = t;
        //     instructor = i;
        //     credit = c;
        // }
        ~Course(){
           // cout << title << " distroyed\n";
        }
        void setTittle(string t){this->title = t;}
        void setInstroctor(string i){this->instructor = i;}
        void setCredit(int c) {this->credit = c;}
        string gettitle(){return this->title;}
        string getInstructor(){return this->instructor;}
        int getCredit(){return this->credit;}

        void display(){
            cout << "title : " << title
                << "  instructor : " << instructor
                << "  Credit : " << credit << "\n";
        }
};
class Depatment{
    private:
        Course c1,c2;
    public:
        Depatment(Course c1, Course c2){ 
            c1 = c1; c2 = c2;
        }
        void display(){
            cout << "c1 : " ;
            c1.display();
            cout << "c2 : " ;
            c2.display();
        }
        Course hightCreditcourse(){
            if(c1.getCredit() >= c2.getCredit()){
                return c1;
            }else {
                return c2;
            }
        }
        bool containsInstructor(string name){
            return (c1.getInstructor() == name || c2.getInstructor() == name);
            return (c1.getInstructor() == c2.getInstructor());
        }
};

int main(){
    Course c1("MAth","Dr.Ahmad",3);
    Course c2("Physics","Dr.Ali",4);

    Depatment dpt(c1,c2);
    dpt.hightCreditcourse();
    cout <<  dpt.containsInstructor("dr.Ahmad");
    c1.display();
    c2.display();
    

    return 0;
}