#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

int main(){
    srand(time(0)); //seed the random number generator
    ArraUtils f; //create an object of the class ArraUtils
    static int numbers[10][5]; //static array to store the random numbers

    f.storerandom2D(numbers, 100); //call the storerandom function to store the random numbers into the array
    f.printout2D( numbers); //call the printout function to print out the array
    return 0;
}
