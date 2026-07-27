#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
   vector<string> items;
   string input;
   while (cin >> input){
        if(input == "quit"){break;}
        items.push_back(input);
   }
   
   for(auto &item :items){
    cout << item << " ";
   }
    

    
    return 0;
}