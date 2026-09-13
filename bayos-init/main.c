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
		printf("Hello from child process!\n");
	} else {
		printf("Hello from parent process!\n");
	}

	return 0;
}
