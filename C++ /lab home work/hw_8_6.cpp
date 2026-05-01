#include <iostream>
using namespace std;
int main(){
    int accountNumber;
    double openingBlance, balance, amount;
    char code;

    int numDeposits = 0,numWithrawals = 0;
    double totalDeposits = 0, totalWithrawals = 0, interesPaid = 0;
    double serviceCharge = 0;
    bool chargedFee = false;

    cout<<"Enter Account Number Follow By space then Balance: ";
    cin>> accountNumber >> balance;
    openingBlance = balance;
    // cout<<"Enter W to withrawals \n D to deposite \n I intrest \n E end transactio : ";
    while (cout << "Enter W to withrawals \n D to deposite \n I intrest \n E end transactio : ",cin>> code && (code != 'E' && code != 'e'))
    {
        cout<<"Enter Amount :";
        cin>> amount;
        if(code == 'W' || code == 'w'){
            balance -= amount;
            totalWithrawals += amount;
            numWithrawals++;
        }else if(code == 'D' || code == 'd'){
            balance += amount;
            totalDeposits += amount;
            numDeposits++;
        }else if(code == 'I' || code == 'i'){
            balance += amount;
            interesPaid += amount;
        }
        if(balance < 1000.00 && !chargedFee){
            serviceCharge = 25.00;
            balance -= serviceCharge;
            chargedFee = true;
        }
    }
    cout << "\n==================================================" << endl;
    cout << "              ACCOUNT SUMMARY REPORT" << endl;
    cout << "\n==================================================" << endl;
    cout << "Account Number          : " << accountNumber << endl;
    cout << "Opening Balance         : $" << openingBlance << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Number of Deposits      : " << numDeposits << endl;
    cout << "Total Deposites         : $" << totalDeposits << endl;
    cout << "Number of Withdrawals   : " << numWithrawals << endl;
    cout << "Total Withdrawals       : $" << totalWithrawals << endl;
    cout << "Interest Paid           : $" << interesPaid << endl;
    
    if(chargedFee){
        cout << "Service Charge      : $" << serviceCharge << endl;
    }else {
        cout << "service Charge      : None " << endl;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Closing blance          : $" << balance << endl;
    cout << "\n==================================================" << endl;




    return 0;
}