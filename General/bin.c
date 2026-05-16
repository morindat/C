# include <stdio.h>
# include <math.h>

int comparisons(int n){
	if (n == 1){
		return 1;
	}
	else{
		return 1 + comparisons (n/2);
	}
}

double iteratively(int n){
	return log2(n) + 1;
}

int main (){
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int x = 6;
	
	int number = comparisons(x);
	int result = iteratively(x);

	printf("The number of comparisons needed recursively is: %d\n", number);
	printf("The number of comparisons needed iteratively is: %d\n", result);

	int n = sizeof(list)/sizeof(list[0]);
	int start = 0;
	int end = n-1;
	int mid = (start + end)/2;
	int found = 0;

	while (start <= end){
		mid = (start + end) / 2;

		if (list[mid] == x){
			found = 1;
			printf("Found!, at position %d\n", mid);
			break;
		}
		else{
			if (x < list[mid]){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
	}
	if (!found){
		printf("Not found\n");
	}

	return 0;
}
