#include <stdio.h>
#include <unistd.h>

int main(){
	char* path = "/bin/ls";
	char* args[] = {"ls","-l","-a",NULL};

	printf("Before execv()\n");

	if(execv(path, args) != 0) {
		perror("execv failed");
	}

	printf("This line will not be printed unless execv fails.\n");

	return 0;
}
