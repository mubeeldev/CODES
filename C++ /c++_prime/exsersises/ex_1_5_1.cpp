#include <iostream>
#include "salse_item.h"
using namespace std;

int main() {
    salse_item item1, item2;
    :: cin >> item1.bookNo >> item1.units_sold >> item1.price;
    item1.revenue = item1.units_sold * item1.price;
    :: cin >> item2.bookNo >> item2.units_sold >> item2.price;
    item2.revenue = item2.units_sold * item2.price;

    if (item1.bookNo == item2.bookNo) {
        unsigned totalCount = item1.units_sold + item2.units_sold;
        unsigned totalRevenue = item1.revenue + item2.revenue;
        cout << item1.bookNo << "\t" << totalCount << "\t" << totalRevenue << "\t";
        if(totalRevenue != 0){cout << totalRevenue/totalCount << endl;}
        
    } else {
        cerr << "Data must refer to the same ISBN" << endl ;
        return -1 ;
    }
    
    
    return 0;
}