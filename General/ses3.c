# include <stdio.h>
# include <math.h>

int main(){
	int num, og_num, rev_num = 0;

	printf("Please enter a number to check if it is a palindrome: ");
	scanf("%d", &num);

	og_num = num;

	if (num < 10){
		printf("The number must have more than one digit\n");
	}
	else{
		while (num != 0){
			rev_num = (rev_num * 10) + (num % 10);
			num = num / 10;
		}
	}
	if (rev_num == og_num){
		printf("The number %d is a palindrome!\n", og_num);
	}
	else{
		printf("The number %d is not a palindrome!\n", og_num);
	}


	double number, i;
	int is_prime = 1;

	printf("Please enter a number: ");
	scanf("%lf", &number);

	if (number <= 1){
		printf("Please enter a number greater than 1\n");
		return 0;
	}
	else{
		for (i = 1; i <= sqrt(num); i ++){
			if (fmod(num, i ) == 0){
				is_prime = 0;
			}
		}
	}
	if (is_prime){
		printf("The number %.0lf is prime!\n", number);
	}
	else{
		printf("The number %.0lf is not prime!\n", number);
	}

	int fib, x, a = 0, b = 1, c;

	printf("Please enter ther number of terms you need up to for the fib series: ");
	scanf("%d", &fib);

	if (fib == 0){
		printf("[0]");
	}
	else if (fib == 1){
		printf("[0, 1]");
	}
	else{
		printf("The fibonacci series is: \n");
		printf("[0, 1");
		for (x = 2; x <= fib; x ++){
			c = a + b;
			printf(", %d", c);
			a = b;
			b = c;
		}
		printf("]\n");
	}

	int A, B, C, D;
	printf("A|B|C|D\n");
	for (A = 0; A <=1; A++){
		for (B = 0; B <= 1; B++){
			for (C = 0; C <= 1; C++){
				for (D = 0; D <= 1; D++){
					printf("%d %d %d %d\n", A, B, C, D);
				}
			}
		}
	}


	return 0;
}
