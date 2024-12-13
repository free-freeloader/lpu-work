#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("input_for_2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	char ch;

	while(1) {
		scanf("%c", &ch);
		if(ch == '$') {
			break;
		}
		write(fd, &ch, 1);
	}

	close(fd);

	return 0;
}
