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
    A& Set_A_data(int r);
    int Get_A_data();
};

A& A::Set_A_data(int A_num){
    this->A_num = A_num;
    return *this;
}
A::B& A::B::Set_data(int B_date){
    this->num = B_date;
    return *this;
}
int A::Get_A_data() {
    return this ->A_num;
}
int A::B::Get_data(){
    return this ->num;
}
int main() {
    cout << "Nested classes in C++" << endl;
    A A_obj;
    A::B obj; // Create object of type A::B
    A_obj.Set_A_data(4);
    cout << "the Class A number is : "<< A_obj.Get_A_data() << endl;
    cout << "--------------------------------------------\n";

    obj.Set_data(10);
    cout  << " the Number is  "<< obj.Get_data() << endl;

    system("pause > 0");
}