/*
    my observatin

    i observe that the constractore of the classes are not directly initialize
    persn();
    address();
    and they used address aas object declered in the class to get acces to address class members infrmations
    Obj = Obj.addr.Set_Data(Obj);
    1. Compilation and Execution Status
Status: The program compiles and runs successfully without errors.

Concept Demonstrated: It is a classic demonstration of a nested (inner) class in C++ (Address defined inside the scope of the enclosing Person class) and out-of-line member function definitions using the scope resolution operator (::).

2. Execution Flow
Object Instantiation: In main(), a Person object named P1 is created, which automatically initializes its nested Address member object (addr).

Data Input (Set_Data_Person & Set_Data):

The program prompts the user to input personal details: Name, Age, Gender, and Job.

It then delegates to the nested class method (Obj.addr.Set_Data(Obj)) to collect address details: Unit Number, Street Name, and Country Name.

The modified object is passed back up and stored in P1.

Data Output (Display_Person & Display_Address):

The program calls P1.Display_Person(P1), which prints the personal details.

It then invokes Obj.addr.Display_Address(Obj) to print the nested address information cleanly to the console.

3. Key Technical Observations
Access Control & Encapsulation:

Member functions of Person can directly access private fields of Person (name, Age, Gender, Job).

Member functions of the nested class Address can directly access private fields of Address (Unit_No, Street_Name, country_Name) even when accessing them via an object instance (Obj.addr...).

Input Buffer Management:

Inside Set_Data(), the code uses cin.ignore() right after reading Unit_No (cin >> Obj.addr.Unit_No;). This is a crucial step to consume the trailing newline character left in the input stream, ensuring that the subsequent getline() calls for Street_Name and country_Name capture user input properly without skipping.
*/

#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::cin;
using std::endl;

class Person{
    private:
        string name;
        int Age;
        char Gender;
        string Job;

    public:
        class Address{
            private:
                string country_Name;
                string Street_Name;
                int Unit_No;

            public:
                Address();
                Person Set_Data(Person Obj);
                void Display_Address(Person Obj);
        };
        Address addr;
        // Declared addr object of type inner class address
        Person();
        Person Set_Data_Person(Person Obj);
        void Display_Person(Person Obj);
};
// Person::Address addr; // DO NOT USE THIS FARWARD DECLARATION ( HOW )
Person::Person() {}
Person::Address::Address() {}
Person Person::Address::Set_Data(Person Obj)
{
    cout << " Address Info: \n";
    cout << "Enter Unit Number : ";
    cin >> Obj.addr.Unit_No;
    cin.ignore();
    cout << "Enter Street Name : ";
    getline(cin, Obj.addr.Street_Name);
    cout << "Enter Country Name: ";
    getline(cin, Obj.addr.country_Name);
    return Obj;
}
Person Person::Set_Data_Person(Person Obj)
{
    cout << "Enter Name: ";
    getline(cin, Obj.name);
    cout << "Enter Age: ";
    cin >> Obj.Age;
    cout << "Enter Gender (M) Male Or (F) Famale: ";
    cin >> Obj.Gender;
    cout << "Enter Job: ";
    cin >> Obj.Job;
    Obj = Obj.addr.Set_Data(Obj);
    return Obj;
}
void Person::Address::Display_Address(Person obj) // Person::Address obj
{
    cout << "UNIT NUMBER: " << obj.addr.Unit_No << " - STREET NAME: " << obj.addr.Street_Name << " - COUNTRY:" << obj.addr.country_Name << endl;
}
void Person::Display_Person(Person Obj) //
{
    cout << " Name: " << Obj.name << endl;
    cout << " Age: " << Obj.Age << endl;
    cout << " Gender: " << Obj.Gender << endl;
    cout << " job: " << Obj.Job << endl;
    Obj.addr.Display_Address(Obj);
}
int main()
{
    Person P1;
    P1 = P1.Set_Data_Person(P1);
    cout << "-------------------------- Display Info----------" << endl;
    P1.Display_Person(P1);
    return 0;
}