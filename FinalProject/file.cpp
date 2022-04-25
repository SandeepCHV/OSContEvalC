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
struct user_info{
	int user_id;
	string user_name;
	int user_status;
};

void fill_user_data(struct user_info *,char *);
string command_creation(string,string,string,string);


int count_sub_size();
enum status{
	Admin = 1,
	Faculty = 2,
	Student = 3
};


int main(){
	//int current_userid = getuid();		//Getting the value of the current user
	int current_userid = 1000;
	string user_id = to_string(current_userid);
	struct user_info current_user_info;
	int subject_count = count_sub_size();
	fstream current_fio;
	current_fio.open("user_list.txt",ios::in);
	
	while(current_fio){
		string current_buffer;
		
		getline(current_fio,current_buffer);
		if(strstr(current_buffer.c_str(),user_id.c_str())){
			char buffer_array[100];
			strcpy(buffer_array,current_buffer.c_str());
			fill_user_data(&current_user_info, buffer_array);
		}
		
	}

	current_fio.close();
	string command_line;
	const char *command;
	switch(current_user_info.user_status){
		case Admin		: 	cout<<"Hello, you are admin";
							break;
		case Faculty	: 	cout<<"Hello, you are faculty";
							break;
		case Student	: 	
							command_line = command_creation("student",current_user_info.user_name,to_string(current_user_info.user_id),to_string(subject_count));
							command = command_line.c_str();
							system(command);
							break;
		default			: 	cout<<"Your are not a part of the system";
							break;
	}
}	

void fill_user_data(struct user_info *user_data, char line_buffer[]){
	char* token = strtok(line_buffer, " ");
	user_data->user_id = stoi(token);
	token = strtok(NULL," ");
	user_data->user_name = token;
	token = strtok(NULL," ");
	user_data->user_status = stoi(token);
}

string command_creation(string execname, string name, string uid, string subject_number){
	string file_path = "./" + execname + " " + name + " " + uid + " " + subject_number;
	return file_path;
}

int count_sub_size(){
	fstream fio;
	int count = 0;
	fio.open("user_list.txt",ios::in);
	string buffer;
	
	while(fio){
		getline(fio,buffer);
		if(strstr(buffer.c_str(),"2")){
			count++;
		}
	}

	fio.close();
	return count;
}
	
	
