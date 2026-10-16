#include <iostream>
#include <string>
using std::string;
using std::cout;

class Animals{
    private:
        string type;
        int age;
    public:
        Animals(string t, int a){
            type = t;
            age = a;
            cout << "Animal " << type << " aged " << age << " is born\n";
        }
        ~Animals(){
            cout << "Animal " << type << " aged " << age << " is gone\n";
        }

};
void zoo_area(){
    Animals a1("Tiger", 5);
    Animals a2("Elephant ", 10);
    static Animals a33("phanda",7);
}
Animals global("lion", 3);
int main(){
    zoo_area();
    Animals a4("zebra" , 2);
    return 0;
}

