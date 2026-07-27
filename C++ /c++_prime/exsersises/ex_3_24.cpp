#include <iostream>
#include <vector>
using namespace std;

int main() {
//    vector<string> text{"sugger","salt","union","uganda","unated","watch","welcome","zebra","zabadi","zaitune"};
    vector<int> text{};
    int item;
    while (cin >> item) {
        if(item == -1){break;};
            text.push_back(item);
    }
    auto beg = text.begin(), end = text.end();
    auto mid = beg + (end - beg)/2;
    cout << " adjustment sum : ";
    for(auto it = text.begin(); it != text.end(); ++it){
        cout << *it + (*it + 1) << " ";
        }
        auto left = beg , right = end-1;
        cout << "another innder summ : ";
        while (left <= right){
            cout << *left + *right << " ";
            left ++;
            right --;
            cout  << endl << "left : " << *left << "right : " << *right << endl;
            

        }

    


    
        return 0;
    }