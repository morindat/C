# include <stdio.h>

int countDigits(int num){
	if (num < 10) return 1;
	else{
		return 1 + countDigits(num / 10);
	}
}

int getfirst(int num, int digits){
	while (num >= 10){
		num /= 10;
	}
	return num;
}

int power(int a, int b){
	if (b == 0) return 1;
	else{
		return a * power(a, b - 1);
	}
}

int isPalindromeHelper(int num, int digits){
	if (num < 10){
		return 1;
	}

	int firstdig = getfirst(num, digits);
	int last = num % 10;

	if (firstdig != last){
		return 0;
	}

	int remaining = (num / 10) % (int)(power(10, digits - 2));

	return isPalindromeHelper(remaining, digits - 2);

}

int isPalindrome(int num){
	int digits = countDigits(num);
	return isPalindromeHelper(num, digits);
}

int main(){
	int num;
	printf("Please enter a number to check if it is a palindrome: ");
	scanf("%d", &num);

	if (isPalindrome(num)){
		printf("The number is a palindrome!\n");
	}
	else{
		printf("The number is not a palindrome!\n");
	}

	return 0;
}
