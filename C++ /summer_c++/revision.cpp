#include <iostream>
using std::cin;
using std::cout;


enum sts {
    pass,
    fail,
    incomplet
};
union studentId {
    int id;
    char userName[10];
};
struct st_info {
    studentId id;
    bool typeId;
    char name[10];
    float gradde;
    sts status;
};
// st_info s1;

void outprint(st_info *ptr);
int main(){

    st_info *st_list = new st_info[3];

    /*
    cout << "To use id type (1) or (0) for username : ";
    cin >> s1.typeId;

    if(!s1.typeId){
        cout << "Enter Student User Name : ";
        cin >> s1.id.userName;
    } else{
        cout << "Enter Student id : ";
        cin >> s1.id.id;
    }
    cout << "\n Enter Student Name: ";
    cin >> s1.name;
    cout << "\n Enter Grade of Student: ";
    cin >> s1.gradde; */
    //--------------------------------------------------------------
    cout << "to use id type (1) or (0) for username : ";
    bool cId;
    cin >> cId;

    if(cId){
        for(int i = 0; i < 3; i++){

            cout << "Enter student Id : ";
            cin >> st_list[i].id.id;
            cout << " Enter Student name : ";
            cin >> (st_list+i)-> name;
            cout << " Enter Student Grade : ";
            cin >> (st_list+i)-> gradde;
        }
    }
    for(int i = 0; i < 3; i++){

            cout << "Enter student User Name : ";
            cin >> st_list[i].id.userName;
            cout << " Enter Student name : ";
            cin >> (st_list+i)-> name;
            cout << " Enter Student Grade : ";
            cin >> (st_list+i)-> gradde;
    }
    for( int i = 0; i < 3; i++){
        if(st_list[i].gradde > 60){st_list[i].status;}
        else if(st_list[i].gradde == 0 ){st_list->status ;}
        else st_list->status;
    }

    outprint(st_list);
    delete[] st_list;
    return 0;
}

void outprint(st_info *ptr){
    for (int i = 0; i < 3; i++){

        if((ptr + i) -> typeId){cout << "id: "<< ( ptr+i )->id.id << "\n";}
        else { cout << "User Name is : " << ( ptr+i )->id.userName<< "\n";}
        cout << "Name : " << ( ptr + i)->name << "\n Grade" << ptr->gradde << "\n";
        switch (( ptr + i )->status)
        {
        case 1: cout << "status : pass" ; break;
        case 2: cout << "status : fail" ; break;
        case 3: cout << "status : incomplet" ; break;
        }
    }
}