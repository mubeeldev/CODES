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


  for(auto usr = users.begin();usr != users.end(); ++usr){
    (*usr)[0] = toupper((*usr)[0]);
    cout << *usr << " ";
  }
    
    return 0;
}