#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
	int choice, fd;
	fd = open("first.txt", O_RDONLY | O_CREAT, 0644);

	int file_size = lseek(fd, 0, SEEK_END);
	int half_size = file_size/2;

	printf("Enter choice(1/2): ");
	scanf("%d", &choice);

	if(choice==1) { //first half of file
		char buffer[half_size];
		lseek(fd, 0, SEEK_SET);
		read(fd, buffer, half_size);

		int fd2 = open("firstOP.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		write(fd2, buffer, half_size);
		close(fd2);
	} else { //second half of file
		char buffer[file_size - half_size];
		lseek(fd, half_size, SEEK_SET);
		read(fd, buffer, file_size - half_size);

		int fd3 = open("firstOP.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		write(fd3, buffer, file_size - half_size);
		close(fd3);
	}
	close(fd);

	return 0;
}
