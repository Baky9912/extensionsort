#include"sorter.h"

int main(int argc, char **argv){
	const char *usage = "Usage: ./extensionsorter <directory>\n";

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
			printf("%s",usage);
			return 1;
		}
	}
	else{
		printf("%s",usage);
		return 1;
	}

	sorter(dir_path);
}
