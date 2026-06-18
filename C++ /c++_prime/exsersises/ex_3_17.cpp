#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
int main(){
    vector<string> users;
    string user;
    while (cin >>user){
        if(user == "quit"){ break;}
        users.push_back(user);
    }
    for(auto use : users){
        for(auto &ch: use){
            ch = toupper(ch);
        }
        cout << use << " ";
    }
    
    return 0;
}