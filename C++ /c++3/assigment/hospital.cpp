#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cerr;

class Hospital {
    private:
        string name;
        int beds;
        int patients;
        public:
            Hospital& setName(string name){
                this->name = name;
                return *this;
            }
            Hospital& setBeds(int beds){
                this->beds = beds;
                return *this;
            }
            Hospital& setPatients(int patients){
                this->patients = patients;
                return *this;
            }
            string getName() const{
                return name;
            }
            int getBeds() const{
                return beds;
            }
            int getPatients() const{
                return patients;
            }
            Hospital(string name , int beds , int patients){
                this->name = setName(name).getName();
                this->beds = setBeds(beds).getBeds();
                this->patients = setPatients(patients).getPatients();   
            }
            Hospital& addPatient(){
                if(patients < beds){
                    patients++;
                } else {
                    cerr << "Error: Cannot add patient. Hospital is full." << endl;
                }
                return *this;
            }
            Hospital& removePatient(){
                if(patients > 0){
                    patients--;
                } else {
                    cerr << "Error: Cannot remove patient. No patients in the hospital." << endl;
                }
                return *this;
            }   
            Hospital& displayInfo() {
                cout << "Hospital Name: " << name << endl;
                cout << "Number of Beds: " << beds << endl;
                cout << "Number of Patients: " << patients << endl;
                cout << "available Beds: " << (beds - patients) << endl;
                cout << "-------------------------------------------------" << endl;
                return *this;
            }
};

int main() {
    Hospital hospital("General Hospital", 10, 5);
    hospital.addPatient()
            .addPatient()
            .addPatient()
            .removePatient()
            .displayInfo();

    Hospital hospital2("City Hospital", 16, 15);
    hospital2.addPatient()
            .addPatient()
            .removePatient()
            .displayInfo();
    // hospital2.displayInfo();
    return 0;
}