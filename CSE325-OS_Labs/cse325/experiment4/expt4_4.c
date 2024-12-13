#include <stdio.h>
#include <unistd.h>
#include <limits.h> //for PATH_MAX

int main(){
	char cwd[1024];
	if(getcwd(cwd, sizeof(cwd))){
		printf("Currnt working directory: %s\n", cwd);
	} else {
		perror("Error retrieving current working directory.\n");
		return 1;
	}
	return 0;
}
