#include <iostream>
using namespace std;

class vehicle{
    protected:
    string brand;
    int year;
    public:
        vehicle(string brand, int year) : brand(brand), year(year) {}
        void Display(){
            cout << "Brand : " << brand << "\nYear : " << year << endl;
        }

};
class Car : public vehicle{
    private:
        string model;
        public:
            Car(string brand, int year ,string model) : vehicle(brand, year), model(model){}
            void Display(){
                vehicle::Display();
                cout << "model : " << model << endl;
            }
};

int main(){
    Car c("TOYOTA", 2027, "Camery");
        c.Display();

    system("pause > 0");
}