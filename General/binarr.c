# include <stdio.h>

int main()
{
	int bin[5];
	int flag = 0;

	printf("Enter the Binary String bit-wise: ");
	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &bin[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		if (bin[i] != bin[4 - i])
		{
			flag++;
			break;
		}	
	}

	printf("The Binary String given is : ");
        for(int i = 0; i < 5; i++)
        {
                printf("%d ", bin[i]);
        }
	
	printf("\n");	

	if (!flag)
		printf("The entered Binary string is a Palindrome.\n");
	else
		printf("The entered Binary string is not a Palindrome.\n");

return 0;
}