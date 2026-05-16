# include <stdio.h>

int main(){

	// Code for factorial in C
	int num, i;
	unsigned long long ans = 1;

	printf("Please enter a number: ");
	scanf("%d", &num);

	if (num < 0){
		printf("Please enter a positive number\n");
	}
	else if (num == 0){
		printf("The factorial of 0 is 1\n");
	}
	else{
		for (i = 1; i <= num; i++){
			ans *= i;
		}
		printf("The factorial of %d is: %llu\n", num, ans);
	}
	return 0;
}
