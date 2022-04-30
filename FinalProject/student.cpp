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
	//cout<<current_user_info.user_name<<endl;
	current_user_info.user_id = stoi(argv[2]);
	//cout<<current_user_info.user_id<<endl;
	int subject_count = 4;
	string student_name[4];

	fstream fin;
	fin.open("user_list.txt");
	int i =0;
	while(fin){
		string line;
		getline(fin,line);
		if(strstr(line.c_str(),"3")){
			char analyzer[100];
			strcpy(analyzer,line.c_str());
			char *token1 = strtok(analyzer," ");
			token1 = strtok(NULL," ");
			student_name[i]=token1;
			i++;
		}
	}
	/*for(int i = 0; i<4;i++){
		cout<<student_name[i]<<endl;
	}*/
	int read_file_marks[subject_count][4];
	//Opening files to store file desciptor into read_file_marks
	for(int i=0; i<subject_count; i++){
		for(int j=0;j<4;j++){
			string file_path = file_path_creation(student_name[i], to_string(j+1), "Student");
			//cout<<file_path<<endl;
			char file_path_array[100];
			strcpy(file_path_array,file_path.c_str());
			//cout<<file_path<<endl;
			read_file_marks[i][j] = open(file_path_array,O_RDONLY);
		}
	}

	//We are reading the content of the files
	char *readStream = new char[subject_count];
	char data[4][4];
	for(int i =0; i<subject_count;i++){
		for(int j=0;j<4;j++){
			read(read_file_marks[i][j],&readStream[i],sizeof(char));
			data[j][i] = readStream[i];
		}
	}

	for(int i =0; i<4;i++){
		for(int j=0;j<4;j++){
			cout<<data[j][i]<<" ";
		}
		cout<<endl;
	}

	for(int i=0; i<subject_count;i++){
		for(int j=0;j<4;j++){
			close(read_file_marks[i][j]);
		}
	}

	int output_file = open("./Output/output.txt",O_TRUNC | O_WRONLY);

	for(int i = 0; i<subject_count; i++){
		for(int j=0;j<4;j++){
			readStream[i] = data[j][i];
			//cout<<sizeof(char)<<endl;
			write(output_file,&readStream[i],sizeof(char));
			write(output_file," ",strlen(" "));
			}
		if(i<4){
			char *name_array = new char[100];
			strcpy(name_array,student_name[i].c_str());
			//cout<<name_array<<strlen(name_array)<<endl;
			write(output_file,"- ",sizeof("- "));
			write(output_file,name_array,strlen(name_array));
		}
		if(i<3)
		write(output_file,"\n",strlen("\n"));
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


