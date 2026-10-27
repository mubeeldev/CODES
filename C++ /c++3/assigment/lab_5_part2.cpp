#include <iostream>
#include <string>
using std::string;

class GradeBok{
    private:
        string courseName;
    public:
    GradeBok& setCourseName(string courseName){
        this->courseName = courseName.substr(0, 25);
        return *this;
    }
    string getCourseName() const{
        return courseName;
    }
    GradeBok(string courseName){
        this->courseName = setCourseName(courseName).getCourseName();
    }
    GradeBok& DisplayMessage(){
        std::cout << "Welcome to the grade book for \n" << getCourseName() << "!" << std::endl;
        return *this;
    }

};

int main(){
    GradeBok gradeBook("CS182 - C++ Programming");
    gradeBook.DisplayMessage();

    return 0;
}