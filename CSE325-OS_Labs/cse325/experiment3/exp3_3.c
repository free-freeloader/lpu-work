#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd1 = open("input_for_3.txt", O_CREAT | O_RDONLY);
	int fd2 = open("encrypted_output_for_3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	char ch;
	while(read(fd1, &ch, 1) == 1){
		if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
			ch = ch+3;
		}
		write(fd2, &ch, 1);
	}
	close(fd1);close(fd2);
	return 0;
}
