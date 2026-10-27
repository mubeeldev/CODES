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
        
        void setTittle(string tt){title = tt;}
        void setInstroctor(string ii){instructor = ii;}
        void setCredit(int cc) {credit = cc;}
        
        string gettitle(){return title;}
        string getInstructor(){return instructor;}
        int getCredit(){return credit;}

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
            this->c1 = c1; this->c2 = c2;
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
            if(c1.getInstructor() == name ){
                cout << c1.getInstructor() << "\n"; 
                return true;
            }else if(c2.getInstructor() == name){
                cout << c2.getInstructor() << "\n";
                return true;
            }else{
                return false;
            };
           // return (c1.getInstructor() == c2.getInstructor());
        }
};

int main(){
    Course c1("MAth","Dr.Ahmad",3);
    Course c2("Physics","Dr.Ali",4);

    Depatment dpt(c1,c2);
    dpt.hightCreditcourse().display();

    dpt.containsInstructor("Dr.Ahmad");

    return 0;
}