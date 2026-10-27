#include <iostream>
using std::cout;
using std::endl;
/*
    there is one error in this code 
    in public member function change() of class Test, 
    the statement "this = t;" is invalid 
    because "this" is a pointer to the current object and cannot be assigned to another pointer. 
    The correct way to change the value of x in the current object would be to dereference 
    the pointer t and assign its value to x, like this: "x = t->x;". 

    the out put of this code will be "x = 5" because the change() 
    function does not actually change the value of x in the current object.
    but after fixing the error, the output will be "x = 10" 
    because the change() function will change the value of x in the current object to the value of x in the object pointed to by t.
*/

class Test
{
private:
    int x;

public:
    Test(int x = 0) { this->x = x; }
    void change(Test *t) { this->x = t->x; }
    void print() { cout << "x = " << x << endl; }
};
int main()
{
    Test obj(5);
    Test *ptr = new Test(10);
    obj.change(ptr);
    obj.print();
    return 0;
}