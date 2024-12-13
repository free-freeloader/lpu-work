#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	char* old_filename = argv[1];
	char* new_filename = argv[2];

	if(strlen(old_filename)==0 || strlen(new_filename)==0) {
		printf("Please enter bth names");
		exit(EXIT_FAILURE);
	}

	if(rename(old_filename, new_filename)!=0) {
		printf("Error in renaming file");
		exit(EXIT_FAILURE);
	}

	printf("File %s renamed to %s successfully", argv[1], argv[2]);

	return 0;
}
