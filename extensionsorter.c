#include"sorter.h"

int main(int argc, char **argv){
	const char *usage = "Usage: ./extensionsorter <directory>";

	char *dir_path;
	if(argc==1){
		dir_path = malloc(2);
		dir_path[0]='.';
		dir_path[1]='\0';
	}
	else if(argc==2){
		dir_path = argv[1];
		int j = strlen(dir_path);
		while(--j >= 0 && dir_path[j]=='/'){
			dir_path[j]='\0';
		}
		if(j<0){
			printf("%s\n",usage);
			return 1;
		}
	}
	else{
		printf("%s",usage);
		return 1;
	}

	DIR *base_dir = opendir(dir_path);
	if(base_dir==NULL){
		printf("Failed to open %s\n",dir_path);
		printf("%s\n",usage);
		return 1;
	}
	closedir(base_dir);

	if((sorter(dir_path)==0) && delete_empty(dir_path)==0){
		printf("Finished successfully\n");
	}
	return 0;
}
