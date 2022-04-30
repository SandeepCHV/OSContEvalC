#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<unistd.h>
using namespace std;

int main(int argc,char *argv[]){
    cout<<"Hello, welcome Administrator"<<endl;
    bool admin_login = true;

    while(admin_login){
        int console_input;

        cout<<"Choose the following options"<<endl;
        cout<<"1. Create New Student User"<<endl;
        cout<<"5. Logout"<<endl;
        cin>>console_input;

        string username;
        string password;
        switch(console_input){
            case 1  :   system("sudo adduser");
                        break;

            default :   cout<<"Invalid output"<<endl;
        }
    }
}