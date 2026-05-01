#include <iostream>
using namespace std;

int main() {
    int num, smallest, largest;
    bool first = true;

    cout << "Enter integers (-1 to stop):" << endl;

    while (true) {
        cout << "Enter number: ";
        cin >> num;

        if (num == -1) break;

        if (first) {
            smallest = largest = num;
            first = false;
        } else {
            if (num < smallest) smallest = num;
            if (num > largest)  largest  = num;
        }
    }

    if (first) {
        cout << "No numbers were entered." << endl;
    } else {
        cout << "Smallest: " << smallest << endl;
        cout << "Largest:  " << largest  << endl;
    }

    return 0;
}