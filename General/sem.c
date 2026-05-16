#include<stdio.h>

int main()
{
	int flag = 0, shut = 0;

	printf("p\t q\t r\t (r \u2192 (\u00AC p \u2228 q))     (p \u2227 \u00AC r)\t  \u00AC(\u00AC r \u2228 q)\n"); //...........usage of ASCII and Unicode values to insert relevant symbols; makes the output aesthetic
	printf("-----------------------------------------------------------------------\n");

	for(int p = 0; p < 2 && !shut; p++) //........notice the condition in this for loop
	{
		for(int q = 0; q < 2 && !shut; q++)
		{
			for(int r = 0; r < 2; r++)
			{  /*all the premises and conclusion of the argument*/
				int premise_01 = (!r || (!p || r));
				int premise_02 = (p && !r);
				int conclusion = !(!r || q);
				
				printf("%d\t %d\t %d\t \t%d\t \t%d\t \t%d\t \n", p, q, r, premise_01, premise_02, conclusion);
				if (premise_01 && premise_02)
				{
					if (!conclusion)
					{
						shut++; //.....................master-switch to break all the for loops
						flag++;	//.....................indicator to tell if the status of truth table
						break;
					}
				}
			}
		}
	}
	printf("\n"); //........makes the output aesthetic

	if (flag)
	{
		printf("Last row in the Truth Table above, indicates that the logical argument is invalid.\n");
		printf("All the premises are True and simultaneously the conclusion is False.\n");
	}
	else
		printf("Here is the complete Truth Table for the given logical argument, which is valid.\n");

	printf("\n"); //........makes the output aesthetic

	return 0;
}
