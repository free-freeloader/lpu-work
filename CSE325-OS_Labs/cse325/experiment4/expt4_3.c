#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
	char d_name[256];
	printf("Entry directory name to delete: ");
	scanf("%255s", d_name);
	if(rmdir(d_name)!=0){
		perror("Erroe removing the directory\n");
		return 1;
	}

	printf("Directory %s deleted successfully\n", d_name);
	return 0;
}
