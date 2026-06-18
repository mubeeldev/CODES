#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
   vector<string> items;
   string input;
   while (cin >> input){
    items.push_back(input);

    for(auto item:items){
     cout << item << endl;
     
    }
   }
   
    

    
    return 0;
}