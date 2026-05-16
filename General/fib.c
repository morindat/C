# include <stdio.h>

int main(){
	int a = 0, b = 1, c, i;
	
	int num; 

	printf("Please enter the number of terms: ");
	scanf("%d", &num);

	if (num == 0){
		printf("The 0th fibonacci series is: %d\n", num);
	}
	if (num == 1){
		printf("The fibonacci of 1 is: %d\n", num);
	}
	else{
		printf("The fibonacci series: [0, 1, ");
		for (i = 2; i <= num; i ++ ){
			c = a + b;
			a = b;
			b = c;
			printf("%d, ", c);
		}
	}
	printf("...]");
	return 0;
}
