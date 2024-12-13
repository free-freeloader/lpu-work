#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

int main(){
	//part a
	int fd = open("sample_for_4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("Part A done successfully.\n");

	//part b
	if(chmod("sample_for_4.txt", S_IRUSR | S_IWUSR) < 0) {
		printf("Error changing file permissions.\n");
		return 1;
	}
	printf("Part B done successfully. Permissions changed: Owner has read/write, others have no permissions.\n");

	//part c
	const char* new_usr = "root";
	struct passwd* pw = getpwnam(new_usr);
	chown("sample_for_4.txt", pw->pw_uid, -1);
	printf("Part C done successfully. Ownership changed to user: %s\n", new_usr);

	//part d
	link("sample_for_4.txt", "symlink_to_4.txt");
	printf("Part D done successfully. Hardlink to sample_for_4.txt created.\n");

	//part e
	symlink("sample_for_4.txt", "softlink_4.txt");
	printf("Part E done successfully. Soft link to sample_for_4.txt created.\n");

	close(fd);

	return 0;
}
