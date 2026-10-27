#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

#include <algorithm>
using std::for_each;
using std::begin;
using std::end;

enum enColor {green, red, white, blue};
enum enGender { male, female};
enum enMaritalStatus { single, married };

struct stAddress {
    string streeName;
    string buildingNumber;
    string POBOX;
    string zipCode;
};
struct stContactInfo {
    string email;
    int phoneNumber;
};
struct stPerson{
    string firstName;
    string lastName;

    enGender gender;
    string dateOfBeth;
    enMaritalStatus maritalStatus;
    stAddress address;
    stContactInfo contact;
    enColor FavoretColor;

};
void regristration( stPerson users[], int size);
int main(){
    stPerson s;
    stPerson *users = new stPerson [100];
    int usersSize = sizeof(&users[0])/sizeof(&users);
    regristration( users, usersSize);
    cout << usersSize;
    s.firstName = "mohammed";
    s.lastName = "Alhassan";
    s.dateOfBeth = "1998";
    s.gender = enGender::male;
    s.maritalStatus = enMaritalStatus::single;
    s.address.buildingNumber = "43";
    s.address.POBOX = "3445";
    s.address.streeName = "unaiza";
    s.address.zipCode = "45678";

    delete[] users;
    return 0;
}
void regristration( stPerson users[], int size ){
    for( int i = 0; i < size; i++) {
        cout << "First Name: ";
        cin >> users[i].firstName;
        cout << "Last Name: ";
        cin >> users[i].lastName;
        cout << "Date Of Bath: ";
        cin >> users[i].dateOfBeth;
        cout << "Gender: male / female ";
        string gender;
        cin >> gender;
        if (gender == "male"){users[i].gender = enGender::male;}else{ users[i].gender = enGender::female;}
        cout << "marital statud: single / marred ";
        string maritalStatu;
        cin >> maritalStatu;
        if (maritalStatu == "single"){users[i].maritalStatus = enMaritalStatus::single;}else{ users[i].maritalStatus = enMaritalStatus::married;}
        cout << "enter email:";
        cin >> users[i].contact.email;
        cout << "enter Phone Number:";
        cin >> users[i].contact.phoneNumber;
        cout << "enter street name:";
        cin >> users[i].address.streeName;
        cout << "enter POBOX:";
        cin >> users[i].address.POBOX;
        cout << "enter zip code:";
        cin >> users[i].address.zipCode;
        cout << "enter building number:";
        cin >> users[i].address.buildingNumber;
    
    } 
            
            
        
    
}