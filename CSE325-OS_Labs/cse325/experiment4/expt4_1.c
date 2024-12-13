#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(){
	char name[256];
	printf("Enter the name of directory: ");
	scanf("%255s", name);

	if(mkdir(name, 0755) == -1) {
		perror("Error creating directory.\n");
		return 1;
	}
	printf("Directory created successfully.\n");
	return 0;
}
