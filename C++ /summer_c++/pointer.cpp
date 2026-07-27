#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void setgrades( int * ,int ); //function prototype
void toread(int *, int ); // function prototype

int main(){ 
    int size = 10; //size of the array
    int grades[size]; // array of 10 integers
    setgrades(grades,size); // calling setrade function
    toread(grades,size);
    return 0;
}
//set functions with one pointer parameter allow user to input the values of the grades array
void setgrades( int * pointer , int size){
    int i = 0; // index for the array
    int input = 0; // raading the value from user
    while (*pointer != -1){
        cout << "Enter grade : ";
        cin >> input; //  assigning the value to the input variable
        if(input == -1) break; //checking if the input is -1 then break the loop
        if(i >= size){ // checking if the index is greater than the size of the array
            cout << "Array is full" << endl; // if the array is full then print the message
            break; // break the loop
        }   
        *(pointer+i) = input; // adding value to the pointer
        i ++; // incrementing the index
    }
    
}
//reading function
void toread(int * const grade , int size){
    for(int i = 0; i < size ; i++){
        cout << grade[i] << "\t";
    }
}