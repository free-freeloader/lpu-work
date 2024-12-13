#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main() {
	char cwd[PATH_MAX];
	const char* req_dir = "lab2";
	

	getcwd(cwd, sizeof(cwd));

	if(strstr(cwd, req_dir)==NULL || strcmp(strrchr(cwd, '/')+1, req_dir)!=0) {
		printf("Not inside Lab2 directory.");
		exit(EXIT_FAILURE);
	}

	printf("Directory opened successfully.");

	DIR* dir = opendir(".");

	struct dirent* entry;
	while((entry = readdir(dir))!=NULL){
		printf("%s\n", entry->d_name);
	}

	closedir(dir);
	printf("Lab2 closed successfully.");

	return 0;
}
