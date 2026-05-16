#include <stdio.h>

int main()
{

	int A[3][3], B[3][3];
	int C[3][3];

	printf("Enter integer elements of the first matrix:\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	printf("Enter integer elements of the second matrix:\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	printf("\n");
	printf("The first matrix is :\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n"); //..................this printf is circumstantially strategic!
	}

	printf("\n");
	printf("The second matrix is :\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n"); //..................this printf is circumstantially strategic!
	}

	//.....Element-wise Addition of two matrices.....
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	printf("\n");
	printf("The resultant matrix is :\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n"); //..................this printf is circumstantially strategic!
	}

return 0;
}

/* Practice Problems :

1. Write a program to compute the Trace of a square matrix
2. Write a program to compute the the Transpose of a given matrix
3. Write a program to check whether the Graph G has any loops or not, when its Adjacency Matrix given. */