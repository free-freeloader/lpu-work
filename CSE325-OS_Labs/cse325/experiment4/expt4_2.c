#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
	DIR *dir;
	struct dirent* entry;
	dir = opendir(".");
	if(!dir) {
		perror("Error opening directory.\n");
		return 1;
	}

	printf("Directory entries: \n");
	while((entry = readdir(dir)) != NULL) {
		printf("%s\n", entry->d_name);
	}

	closedir(dir);
	return 0;
}
