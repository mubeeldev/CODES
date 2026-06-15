#include <iostream>
#include <string>
#include "salse_item.h"
using namespace std;



    

int main() {
    double price = 0;
    salse_item data1, data2;
    cout << "name,salse,price: ";
    ::cin >> data1.bookNo >> data1.units_sold >> data1.price;
    data1.revenue = data1.units_sold * data1.price;
    cout << "name,salse,price: ";
    :: cin >> data2.bookNo >> data2.units_sold >> data2.price;
    data2.revenue = data2.units_sold * data2.price;

    if(data1.bookNo == data2.bookNo){
        unsigned totalcnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalcnt << " " << totalRevenue << " ";

        if(totalcnt != 0 ) {cout << totalRevenue/totalcnt << endl;}else cout << " ( no sales ) " << endl;
        return 0 ;
    } else {cerr << "data must refer to the same ISBN " << endl;}

    return -1;
}