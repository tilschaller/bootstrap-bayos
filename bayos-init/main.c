#include <stdio.h>

int main(void) {
	printf("Hello world, from userspace!\n");

	setvbuf(stdout, NULL, _IONBF, 0);

	for (int i = 0; i < 10; i++) {
		int c = getchar();
		putchar(c);
	}
	
	return 0;
}
