# include <stdio.h>
# include <math.h>

double factorial(int n){
	double fact = 1.0;
	for (int i = 1; i <= n; i++){
		fact *= i;
	}
	return fact;
}

int main (){
	int n = 6;
	printf("%lf\n", factorial(n));



	return 0;
}
