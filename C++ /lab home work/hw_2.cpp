    /*
        name : mohammed alhassan
        id : 47116625
        collage : computer collage
        varsion : 0.2
        date : 10/2/2026
    */

#include <iostream>
using namespace std;
string first_name , last_name;
int date_of_bath;

int main() {
    // this is age calculator app
    cout << "Enter first Name and last name :  " ;
    cin >> first_name >> last_name;
    cout <<endl;
    cout <<"Enter Date Of Bath : " ;
    cin >> date_of_bath;
    cout << endl;

    int age = 2026-date_of_bath;


    cout<<"Hi "<< first_name << " " <<last_name <<" you are  "<< age <<" years old"<<endl;

    return 0;
}