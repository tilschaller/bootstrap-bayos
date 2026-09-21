#include <stdio.h>
#include <unistd.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Hello world, from userspace!\n");

	for (int i = 0; i < 10; i++) {
		int c = getchar();
		putchar(c);
	}
	putchar('\n');

	pid_t p = fork();
	if (p == 0) {
		printf("Child process is calculating pi:\n");
		execve("/usr/bin/pi", NULL, NULL);
	} else {
		printf("This is the parent process!\n");
	}

	return 0;
}
