#include<stdio.h>
#include<math.h>

int power(int a, int b)
{/* A custom function for integer exponentiation.
	Architecture: recursive computation	*/

	if (b == 0)
		return 1;
	else
	{
		return a * power(a, b - 1);
	}
}

float polynomial(int x, float coeff[], int k)
{/* A custom function for integer exponentiation.
	Architecture: iterative computation
	Note: more efficient method of polynomial evaluation are available
	Food for thought: Horner's Scheme of polynomial evaluation */

	float func = 0;
	for (int i=0; i<=k; i++)
	{
		float term = coeff[i] * power(x, i);
		func += term;
	}
	return func;
}

int main()
{
	int k;
	printf("Enter k, the degree of the input polynomial: ");
	scanf("%d", &k);

	float coeff[k+1];
	printf("Enter the coeffecients of k-degree polynomial\n");
	for (int i=0; i<=k; i++)
	{
		printf("a_%d : ", i);
		scanf("%f", &coeff[i]);
	}

	float c;

	printf("Enter the positive constant c (%0.3f < c) : ", fabs(coeff[k]) + k);
	scanf("%f", &c);

	printf("\n"); //...................................aesthetics
	printf("x\t  %10s  %10s\t %4.1f%6s\n", "|f(x)|", "|g(x)|", c, "|g(x)|"); //...ignore the alignment type-setting
	printf("---------------------------------------------------\n");

	for(int x = 0; ; x++)
	{
		double func1 = polynomial(x, coeff, k); //.....computes the value of the k-degree polynomial
		double func2 = pow(x, k); //...................computes the value of the k-degree monomial

		printf("%d\t %10.2f\t %10.2f\t %10.2f\n", x, fabs(func1), fabs(func2), c * fabs(func2));

		if( fabs(func1) < fabs(c * func2) )
		{
			printf("---------------------------------------------------\n");
			//printf("\n"); //...........................aesthetics
			printf("The required n_0 is : %d\n", x);
			break;
		}
	}
return 0;	
}