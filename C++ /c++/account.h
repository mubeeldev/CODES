#include <iostream>

class Account{
    public:
        // menber function that sets the account name in the object
        void setName(std::string accountName){
            name = accountName; // store the account name in the object
        }
        // menmber function that retrieves the account name from the object
        std::string getName() const{
            return name; // return the account name
        }
    private:
        std::string name; // account name
};