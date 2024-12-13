#include <stdio.h>
#include <pthread.h>
#include <string.h>
void* msg(void* arg) {
	char** arr = (char**)arg;	
	for(int i=0; i<5; i++) {
		printf("%s ",arr[i]);
	}

}

int main(){
	char* strings[5] = {"My", "name", "is", "Pankaj", "Bashera"};
	pthread_t thread;
	pthread_create(&thread, NULL, msg, (void*)strings);
	pthread_join(thread, NULL);
	return 0;
}
