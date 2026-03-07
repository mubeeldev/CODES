#include <iostream>
using namespace std;

int main() {
    double baseSalary = 600;
    int noOfserviceYears = 10;

    int bonus;
    double totalSele = 10000;
    int additionalBonus;

    if(noOfserviceYears <= 5){
        bonus = 10*noOfserviceYears;
    }else{
        bonus = 20*noOfserviceYears;
    }

    //additional bonus
    if(totalSele < 5000){
        additionalBonus = 0;
    }
    else if(totalSele >= 5000 && totalSele <= 10000){
        additionalBonus = totalSele * 0.3;
    }
    else{
        additionalBonus = totalSele * 0.6;
    }

    //payment chaking

    int payCheck = baseSalary + bonus + additionalBonus;
    cout <<"****************************************************************" <<'\n';
    cout <<"Total Seles: "<<totalSele <<'\n';
    cout <<"Bonus: "<<bonus <<'\n';
    cout <<"Additional Bonus: "<<additionalBonus <<'\n';
    cout <<"Pay Check:  "<< payCheck <<'\n' ;
    cout <<"****************************************************************" <<'\n';

    return 0;
}