#ifndef functions_h
#define functions_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::setw; //for setw()

class ArraUtils{
    public:
    template <size_t row, size_t col>
    void storerandom2D( int (&_2darray)[row][col],int count){
        for(size_t i =0; i < row; i++){
            for(size_t j = 0; j <col; j++){
                _2darray[i][j] = 1 + rand() % count;
            }
        }
    };
    //print out the array
    template <size_t row, size_t col>
    void printout2D(const int (&_2darray)[row][col]){
        string line(col * 16 + 1, '-');
        for(size_t i = 0; i < row; i++){
            cout << line << endl;
            for(size_t j = 0; j < col; j++){
                cout<<"\t"<<setw(3)<<_2darray[i][j]<< "\t";
            }
            cout << "|" << endl;
        }
        cout << line << endl;
    };
    
};
#endif