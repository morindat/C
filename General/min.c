# include <stdio.h>

int main(){
	int myarr[5], temp;
	int n = 5, max, min, i, j;

	printf("Please enter numbers separated by space: ");
	for (i = 0; i < n; i++){
		scanf("%d", & myarr[i]);
	}
	// Bubble sort
	for (i = 0; i < n; i++){
		for (j = 0; j < n-i-1; j++){
			if (myarr[j] > myarr[j + 1]){
				temp = myarr[j];
				myarr[j] = myarr[j + 1];
				myarr[j + 1] = temp;
			}
		}
	}
	printf("My array: ");
	for (i = 0; i < n; i++){
		printf("%d ", myarr[i]);
	}
	printf("\n");

	printf("Reversed array: ");
	for (i = 4; i >= 0; i --){
		printf("%d ", myarr[i]);
	}
	printf("\n");

	max = myarr[0];
	min = myarr[0];

	for (i = 1; i < n; i++){
		if (myarr[i] > max) max = myarr[i];
		if (myarr[i] < min) min = myarr[i];
	}
	printf("Max: %d\n", max);
	printf("Min: %d\n", min);


	return 0;
}
