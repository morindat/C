# include <stdio.h>

int main (){
	int a, b, A, B;

	printf("Please enter the first number: ");
	scanf("%d", &a);

	printf("Please enter the second number: ");
	scanf("%d", &b);

	A = a;
	B = b;

	if (a == 0){
		printf("The GCD of (%d, %d) is: %d\n", A, B, b);
	}
	if (b == 0){
		printf("The GCD of (%d, %d) is: %d\n", A, B, a);
	}
	else{
		while (a != b){
			if (a > b){
				a = a - b;
			}
			else{
				b = b - a;
			}
		}
	}
	printf("The GCD of (%d, %d) is: %d\n", A, B, a);

	return 0;
}
