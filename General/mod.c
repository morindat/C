# include <stdio.h>

int main(){
	int a, b, A, B, r;

	printf("Please enter a number: ");
	scanf("%d", &a);

	printf("Please enter another number: ");
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
		while( b != 0){
			r = a%b;
			a = b;
			b = r;
		}
	}
	printf("The GCD of (%d, %d) is: %d\n", A, B, a);

		

	return 0;
}
