#include <iostream> 
using std::cout; using std::endl;


class A{
    public:
        class B{
            private:
            int num;
        public:
            B& set_date(int n);
            int Get_date();
        };
};

A::B& A::B::set_date(int n){
    this->num = n;
    return *this;
}
int A::B::Get_date(){
    return this->num;
}

int main(){
    cout << "Nested classes in C++" << endl;
    A::B obj;
    obj.set_date(10);
    cout << obj.Get_date() << endl;

    system("pause > 0");
}