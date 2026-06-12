#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(){
    Sales_item currentItem, item;
    if (cin >> currentItem){
        int count = 1;
        while (cin >> item) {
            if (currentItem.isbn() == item.isbn()) {
                count++;
        } else {
            cout << currentItem << " occures " << count << " times" << endl;
            currentItem = item;
            count = 1;}
        }
        cout << currentItem << " occures " << count << " times" << endl;
    }

    return 0;
}