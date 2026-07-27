#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

void printout(const int [][4], int , int);

int main() {
    srand( time(0));
    const int row = 4;
    const int col = 4;
    int array[row][col];
    // inicializing values in array
    for(int i = 0;i < row ; i++){
        for(int j = 0; j < col; j++){
            array[i][j] = rand() % 10;
        }
    }
    printout(array, row, col);
    return 0;
}

void printout(const int arr[][4], int row, int col){
    for(int i = 0;i < row ; i++){
        cout << endl;
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
    }
}
