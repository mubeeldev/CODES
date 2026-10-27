//creating and manipulating an account object
#include <iostream>
#include <string>
#include "account.h"

int main(){
    Account MyAccount; // create an Account object named MyAccount
    // show the initial value of name for MyAccount (which is empty)
    std::cout << "Initial name is: " << MyAccount.getName();
    // prompt for and read name
    std::cout << "\nPlease enter the name: ";
    std::string theName; // create a string variable to hold the name
    getline(std::cin, theName); // read a line of text into theName

    // display the name entered by the user
    std::cout << "You entered: " << theName << std::endl;
    // set the name for MyAccount
    MyAccount.setName(theName);

    // show the updated value of name for MyAccount
    std::cout << "Updated name is: " << MyAccount.getName() << std::endl;

    return 0;
}