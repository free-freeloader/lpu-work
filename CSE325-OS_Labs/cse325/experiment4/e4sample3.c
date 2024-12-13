#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	const char *dirname = "newDirectory";
	mkdir(dirname, 0777);
	
	return 0;
}
