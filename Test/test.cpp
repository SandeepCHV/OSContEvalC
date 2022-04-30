#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> 
#include <iostream>
using namespace std;
// Driver code
int main()
{
  pid_t pid;
  int status = 0;

  pid = fork();
  
  if(pid == -1){
    cout<<"I have failed to created a child process"<<endl;
    exit(1);
  }else if(pid>0){
    for(int i =0; i<10; i++)
      cout<<"Child Process"<<i<<endl;
      exit(0);
  }else{
    cout<<"Hello"<<endl;
    while(wait(&status));
      for(int i =0; i<10;i++)
        cout<<"Parent Process"<<i<<endl;
  }

  cout<<"END PROGRAM"<<endl;
}