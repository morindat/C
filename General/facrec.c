#include <stdio.h>

int recursiveFactorial(int a)
{
	/* Function to recursively compute factorial. */

	if (!a) //...............NOTE : (!a) and (a == 0) are logically equivalent here
		return 1; //.........basically 0! = 1
	else
		return a * recursiveFactorial(a - 1); //......basically n! = n * (n - 1)!
}

int iterativeFactorial(int a)
{
	int facto = 1;

	if (!a)
		return 1;
	else
	{
		for(int i = 1; i <= a; i++)
		{
			facto *= i; //...........iteratively multiplies all integers from 1 to a
		}
	}
	return facto;
	
}
char George(int a)
{
	if (!a)
		return 'N';
	else
		return 'Y';
}

void tableFactorial()
{
	printf("i | recursive factorial\t | iterative factorial\t | Similarity [Y/N] \n");
	printf("-------------------------------------------------------------------\n");
	for (int i = 1; i < 7; i++)
	{
		/* Observe we call a custom function from another custom function*/
		/* FOOD FOR THOUGHT :
			1. Can we always do that?
				Does the order in which custom functions
				are defined matter in a C program? 
			2. What happens when define the return data type of a
				custom function to be int but the actual value getting returned
				from the function is of float or char data type?*/

		printf("%d | %d\t\t\t | %d\t\t\t | %c \n", i, recursiveFactorial(i), iterativeFactorial(i), George((recursiveFactorial(i) == iterativeFactorial(i))));
	}
	printf("\n");
}

int main()
{
	int n = 6; //.....................scope for experimentation
	int rec_facto, iter_facto;

	printf("\n");
	// printf("Enter the natural number for factorial: ");
	// scanf("%d", &n);

	rec_facto = recursiveFactorial(n);
	iter_facto = iterativeFactorial(n);

	printf("\n");
	printf("Factorial(%d) computed recursively : %d\n", n, rec_facto);
	printf("Factorial(%d) computed iteratively : %d\n", n, iter_facto);
	printf("\n");

	tableFactorial(); //....example of a function whih takes no input and returns no output
	return 0;
}

/* FOOD FOR THOUGHT :
	3. So we have seen that every function returns a value unless
		its defined with 'void ...'. 'printf()' and 'scanf()' are also functions
		with arguments, what values do they return? What is the data type
		of the return values of these in-built functions?

	HINT : printf("The return value of printf = %d\n", printf("[test] "));*/