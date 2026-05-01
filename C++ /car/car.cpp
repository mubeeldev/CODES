#include <iostream>
#include <string>
using namespace std;

int main(){
    bool start = false;
    bool drive = false;
    bool ready = true;
    string command;

    while (ready){
        cout<<"Enter start to start the car:🖲️ ";
        cin>>command;

        if (command == "start" || command == "START"){
            if(start == true){
                cout<<"Car is Already Started"<<endl;
            }else{
                cout<<"car STARTED"<<endl;
                start = true;
            }
        }

        else if(command == "drive"||command == "DRIVE"){
            if(start == false){
                cout<<"Start the car first 🖲️"<<endl;
            }else if(drive == true){
                cout<<"you are already driving the car"<<endl;
            }else{
                cout<<"you are drivng the car"<<endl;
                drive = true;
            }
        }

        else if(command == "stop" || command == "STOP"){
            if(drive == false && start == false){
                cout<<"start the car firs 🖲️"<<endl;
            }else if(drive == false){
                cout<<"the is already Stoppef"<<endl;
            }else{
                cout<<"Car STOPPED"<<endl;
                drive = false;
            }
        }

        else if(command == "exit"||command == "EXIT"){
            if(drive == true){
                cout<<"you can't shootsdown the enghine whale driving! \n stop the car first \n Enter STOP to stop the car :"<<endl;
            }
            cout<<"einghine shootdown!!"<<endl;
            start = false;
        }
        
        else{
            cout<<"please Enter a valid entry!!"<<endl;
        }
    }
    
    
    return 0;
}