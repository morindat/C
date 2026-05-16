# include <stdio.h>
# include <math.h>

int main(){
	int i, is_prime = 1;
	double num;

	printf("Please enter a nummber to check if it's prime: ");
	scanf("%lf", &num);

	if (num <= 0){
		printf("Please enter a positive number\n");
	}
	else if (num == 1){
		printf("%.0lf is not prime\n", num);
	}
	else if (num == 2){
		printf("The number %.0lf is prime\n", num);
	}
	else{
		for (i = 2; i <= sqrt(num); i ++){
			if (fmod(num, i) == 0){
				is_prime = 0;
				break;
			}
		}
		if (is_prime){
			printf("The number %.0lf is prime\n", num);
		}
		else{
			printf("The number %.0lf is not prime\n", num);
		}
	}

	int number, og_num, a, sum = 0;

	printf("Please enter a number to check if it is perfect: ");
    scanf("%d", &number);

	og_num = number;

	for (a = 1; a < number; a++){
		if (number % a == 0){
			sum += a;
		}
	}
	printf("%d\n", sum);
	if (sum == og_num){
		printf("The number %d is perfect!", og_num);
	}
	else {
		printf("The number %d is not perfect!", og_num);
	}

	return 0;
}