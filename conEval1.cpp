#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h> 

using namespace std;

int main(int argc,char *argv[]){
    char *readStream = new char[1];
    int bytes_read=0;
    

    int readFD[3];

    readFD[0] =  open("./X.txt",O_RDONLY);
    readFD[1] =  open("./Y.txt",O_RDONLY);
    readFD[2] =  open("./Z.txt",O_RDONLY);

    if(readFD[0]>-1){
        bytes_read = read(readFD[0],readStream,sizeof(char));
        if(bytes_read){
            cout<<readStream<< " ";
        }
    }
    else{
        cout<<"_ ";
    }

    if(readFD[1]>-1){
        bytes_read = read(readFD[1],readStream,sizeof(char));
        if(bytes_read){
            cout<<readStream<< " ";
        }
    }
    else{
        cout<<"_ ";
    }
    
    if(readFD[2]>-1){
        bytes_read = read(readFD[2],readStream,sizeof(char));
        if(bytes_read){
            cout<<readStream<< " ";
        }
    }
    else{
        cout<<"_ ";
    }
    
    cout << endl << "-----------------------------------------------"<<endl;

    close(readFD[0]);
    close(readFD[1]);
    close(readFD[2]);


    int writeFD[3];
    char *writeStream=new char[1];


    writeFD[0] =  open("./X.txt",O_WRONLY);
    writeFD[1] =  open("./Y.txt",O_WRONLY);
    writeFD[2] =  open("./Z.txt",O_WRONLY);

    bool access= (writeFD[0]>-1 || writeFD[1]>-1 || writeFD[2]>-1);
        
    bool inProgram = true;
    while(inProgram && access){

        if(writeFD[0]>-1){
            cout<< "Enter 1 to Change Value of file 1"<<endl;
        }
        if(writeFD[1]>-1){
            cout<< "Enter 2 to Change Value of file 2"<<endl;        
        }
        if(writeFD[2]>-1){
            cout<< "Enter 3 to Change Value of file 3"<<endl;        
        }
        cout<<"Enter 4 to Exit The Program"<<endl;

        cout << endl;
    
        int option;
        
        cin>> option; 
        cin.ignore();  
        if(option!=4){
            cout<<"Enter Value To Replace in the file: ";
        }          
        switch(option){
            case 1: 
                cin>>writeStream;  
                cout<<writeStream<<endl;
                lseek(writeFD[0],0,SEEK_SET);
                write(writeFD[0],writeStream,sizeof(char));
                break;
            case 2:
                cin>>writeStream;  
                cout<<writeStream<<endl;
                lseek(writeFD[1],0,SEEK_SET);
                write(writeFD[1],writeStream,sizeof(char));
                break;
            case 3:
                cin>>writeStream;  
                cout<<writeStream<<endl;
                lseek(writeFD[2],0,SEEK_SET);
                write(writeFD[2],writeStream,sizeof(char));
                break;
            case 4:
                inProgram = false;
                break;
            default:
                cout<<"Please Enter A Valid Option"<<endl;
        }    
        cout<<endl;
    }
    
    close(writeFD[0]);
    close(writeFD[1]);
    close(writeFD[2]);

}
