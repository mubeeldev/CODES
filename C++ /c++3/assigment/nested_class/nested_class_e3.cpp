#include <iostream>
using std::cout; using std::endl;

class A {
    private:
        int A_num;
    public:
        class B {
            private:
                int num;
            public:
                B& Set_data(int n);
                int Get_data();
        };
    B Obj; //object (Obj) has been created(Declared ) as data member of class A
    A& Set_A_data(int r , int n);
    int Get_A_data();
};
A::B& A::B::Set_data(int n){
    this->num = n;
    return *this;
}
A& A::Set_A_data(int r , int n){
    this->A_num = r;
    A::Obj.Set_data(n);
    return *this;
}
int A::B::Get_data(){
    return this ->num;
}
int A::Get_A_data(){
    return this->A_num;
}

int main() {
    cout << "Nested classes in C++" << endl;
    A A_obj;
    A_obj.Set_A_data(4 ,10);
    cout << "--------------------------------------------\n";
    cout << "The Class A number is " <<A_obj.Get_A_data() << endl;
    cout << "The Class B number is " << A_obj.Obj.Get_data();
    cout << "--------------------------------------------\n";



    system("pause > 0");
}