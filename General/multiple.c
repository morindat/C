# include <stdio.h>

int main(){
	int num, multiple, og_num, i= 0;

	printf("Please enter a number: ");
	scanf("%d", &num);
	
	og_num = num;
	multiple = num;

	printf("The multiples of %d are: [", og_num);
	
	while(multiple <= 200){
		printf("%d", multiple);
		multiple += og_num;;
		if(multiple <= 200){
			printf(", ");
		}
	} 
	printf(", ...]");

	return 0;
}
