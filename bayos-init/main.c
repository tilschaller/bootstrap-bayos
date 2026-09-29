#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Hello world, from userspace!\n");

	for (int i = 0; i < 10; i++) {
		int c = getchar();
		putchar(c);
	}
	putchar('\n');

	pid_t pid = fork();
	if (pid == 0) {
		printf("Child process is calculating pi:\n");
		execve("/usr/bin/pi", NULL, NULL);
	}

	int res;
	pid = waitpid(pid, &res, 0);
	printf("This is the parent process! Child terminated!\n");

	return 0;
}
