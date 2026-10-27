#include <iostream>
#include <string>
using std::string;

#ifndef CREATE_H
#define CREATE_H

class CreateAnDestroy{
    private:
        int objectID;
        string message;
    public:
        CreateAnDestroy(int,string);
        ~CreateAnDestroy();
};
#endif
