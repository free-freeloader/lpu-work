#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char buffer[1024];
	size_t bytes_read, bytes_write;

	int fd1 = open("reading.txt", O_RDONLY | O_CREAT);
	int fd2 = open("writeinto.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	while((bytes_read = read(fd1, buffer, 1024)) > 0) {
		write(fd2, buffer, bytes_read);
	}
	close(fd1);
	close(fd2);

	return 0;
}
