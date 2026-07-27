#include <iostream>
using std::cout;
using std::cin;


int main() {
    int array[3];
    for(int i = 0; i < 3; i++){
        cout << " Enter the student grade : ";
        cin >> array[i] ;
    }
    for(int i = 0 ; i < 3 ; ++i){
        cout << array[i] << " ";
    }

    return 0;
}
