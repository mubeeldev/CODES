#include <iostream>
using std::cout;
#include <iostream>
using std::string;

void headerline();
string columline(int);
void printTable();

int main(){
    headerline();
    printTable();
    return 0;
}

void headerline(){
    cout << "\t \t \t MULTIFICATION TABLE \n \n \t" ;
    for( int i = 1; i <= 10; i++){
        cout  << i << "\t";
    }
    cout << "\n------------------------------------------------------------------------------------\n";
}
string columline(int i){
            if(i < 10){
                return  "    |";
            }else{
                return "   |";
            }

}
void printTable(){
    for( int i = 1; i <= 10 ; i++){
        cout << "\n"<< i << columline(i) << "\t";
        for ( int j = 1; j <= 10 ; j++){
            cout << i * j << "\t";
        }
    }
}