# include <stdio.h>
# include <string.h>

void BIT_AND(char* str1, char* str2, char*result){
	int len = strlen(str1);
	for (int i = 0; i < len; i++){
		result[i] = (str1[i] == '1' && str2[i] == '1') ? '1' : '0';
	}

	result[len] = '\0';
}

void BIT_OR(char* str1, char* str2, char* result){
	int len = strlen(str1);
	for (int i = 0; i < len; i++){
		result[i] = (str1[i] == '1' || str2[i] == '1') ? '1': '0';
	}
	result[len] = '\0';
}

void BIT_NAND(char* str1, char* str2, char* result){
	int len = strlen(str1);
	for (int i = 0; i < len; i++){
		result[i] = (str1[i] == '1' && str2[i] == '1') ? '0' : '1';
	}
	result[len] = '\0';
}

void BIT_XOR(char* str1, char* str2, char* result){
	int len = strlen(str1);
	for (int i = 0; i < len; i++){
		result[i] = (str1[i] != str2[i]) ? '1' : '0';
	}
	result[len] = '\0';
}

int main(){
	char str1[100], str2[100];
	char Or[100], And[100], XoR[100];

	printf("Please enter the first binary string: ");
	scanf("%s", str1);
	printf("Please enter the second binary string: ");
	scanf("%s", str2);

	int len = strlen(str1);

	if (strlen(str1) != strlen(str2)){
		printf("Error 404: String 1 and 2 must be of equal length");
		return 1;
	}

	for (int i = 0; i < len; i++) {
        if ((str1[i] != '0' && str1[i] != '1') || 
            (str2[i] != '0' && str2[i] != '1')) {
            printf("Error: Strings must contain only 0s and 1s\n");
            return 1;
        }
    }

	BIT_AND(str1, str2, And);
	BIT_OR(str1, str2, Or);
	BIT_XOR(str1, str2, XoR);

	printf("BITWISE AND: %s\n", And);
	printf("BITWISE OR: %s\n", Or);
	printf("BITWISE XOR: %s\n", XoR);

	return 0;
}