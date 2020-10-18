#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include"sorter.h"

int is_directory(const char *path){
	struct stat statbuf;
	if(stat(path,&statbuf)!=0){
		return 0;
	}
	return S_ISDIR(statbuf.st_mode);
}

char* get_extension(const char *path){
	char *dot = strrchr(path,'.');
	if(dot==NULL){
		return "plain";
	}
	else{
		return dot+1;
	}
}

int sorter(const char *path){
	DIR *base_dir = opendir(path);
	if(base_dir==NULL){
		printf("Failed to open %s\n",path);
		return 1;
	}
	
	unsigned int path_sz = strlen(path);
	struct dirent *entry;
	while((entry=readdir(base_dir))){
		char *file_name = entry->d_name;
		unsigned int file_name_sz = strlen(file_name);
		char *file_path = malloc(path_sz + file_name_sz + 2);

		strcpy(file_path,path);
		file_path[path_sz]='/';
		strcpy(file_path + path_sz + 1, file_name);

		if(!is_directory(file_path)){
			char *extension = get_extension(file_path);
			unsigned int extension_sz = strlen(extension);

			char *extension_dir = malloc(path_sz+extension_sz+2);
			strcpy(extension_dir, path);
			extension_dir[path_sz]='/';
			strcpy(extension_dir+path_sz+1,extension);
			
			if(!is_directory(extension_dir)){
				if(mkdir(extension_dir,0755)==0){
					printf("%s created successfully\n",extension_dir);
				}
				else{
					printf("%s failed to create\n",extension_dir);
				}
			}
		
			unsigned int extension_dir_sz = strlen(extension_dir);
			char *new_file_path = malloc(extension_dir_sz+file_name_sz+2);

			strcpy(new_file_path,extension_dir);
			new_file_path[extension_dir_sz]='/';
			strcpy(new_file_path+extension_dir_sz+1,file_name);

			if(rename(file_path,new_file_path)==0){
				printf("%s -> %s\n",file_path,new_file_path);
			}
			else{
				printf("%s -> %s FAILED\n",file_path,new_file_path);
			}
		}
	}
	return 0;
}
