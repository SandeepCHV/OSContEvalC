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
// Driver code
int main()
{
  int file_input = open("try.txt",O_WRONLY);
  string hello = "Hello";
  char array[100];
  strcpy(array,hello.c_str());
  write(file_input,array,5);
  write(file_input,array,5);
  write(file_input,array,5);
}