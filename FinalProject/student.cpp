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

enum status{
	Admin,
	Faculty,
	Student
};

string file_path_creation(string, string, string);

int main(int argc,char *argv[]){
	
	struct user_info current_user_info;
	current_user_info.user_name = argv[1];
	current_user_info.user_id = stoi(argv[2]);
	int subject_count = stoi(argv[3]);
	
	int read_file_marks[subject_count];

	//Opening files to store file desciptor into read_file_marks
	for(int i=0; i<subject_count; i++){
		string file_path = file_path_creation(current_user_info.user_name, to_string(i+1), "Student");
		char file_path_array[100];
		strcpy(file_path_array,file_path.c_str());
		//cout<<file_path<<endl;
		read_file_marks[i] = open(file_path_array,O_RDONLY);
	}

	//We are reading the content of the files
	char *readStream = new char[subject_count];
	for(int i =0; i<subject_count;i++){
		read(read_file_marks[i],&readStream[i],sizeof(char));
	}

	for(int i=0; i<subject_count;i++){
		close(read_file_marks[i]);
	}

	int output_file = open("./Output/output.txt",O_TRUNC | O_WRONLY);

	for(int i = 0; i<subject_count; i++){
		write(output_file,&readStream[i],sizeof(char));
		if(i<subject_count-1){
			write(output_file," ",strlen(" "));
		}
	}
	write(output_file,"\n",strlen("\n"));
	for(int i =0; i<subject_count; i++){
		write(output_file,"| ",strlen("| "));
	}
	bool Inprogram = true;
	while(Inprogram){
		cout<<"Do you want to see your marks?(Y/N)"<<endl;
		string input;
		cin>>input;
		if(input=="Y"){
			const char *command = "./editor ./Output/output.txt";
			system(command);
		}else if(input=="N"){
			cout << "Logging you out"<<endl;
			exit(0);
		}else{
				cout<<"Wrong input"<<endl;
		}
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

string file_path_creation(string name, string subject_number, string status = "Student"){
	string file_path = "./" + status + "/" + name + "/" + subject_number + ".txt";
	return file_path;
}


