# include <stdio.h>

int main() {
	int i = 3;
	printf("Address of i = %p\n", (void*)&i);
	printf("The value of i = %d\n", i);

	return 0;
}
