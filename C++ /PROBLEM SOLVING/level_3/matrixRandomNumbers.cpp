//  3X3 RANDOM NUMBERS


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;


int randomNUmbers(int from, int to){
    int ranNum = rand() % (to - from + 1 ) + from;
    return ranNum;
}
void fillRandomNUmber(int arr[3][3], int rows, int cols){
    for( short i = 0; i < rows; i++){
        for( short j = 0; j < cols; j++){
            arr[i][j] = randomNUmbers(1,100);
        }
    }
}
void display(int arr[3][3],int rows,int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
                cout << setw(5) << arr[i][j] << "    ";

        }
        cout << endl;
    }
}
int main(){
    srand((unsigned int)time(0));
    int arr[3][3];

    fillRandomNUmber(arr, 3,3);
    display(arr,3,3);

    system("pause > 0");
}