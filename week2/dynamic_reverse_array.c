#include <stdio.h>

int main ()
{
	printf("How many numbers do you want to enter?\n");
	scanf("%d", &n);
	
	P = (int *)malloc(n * sizeof(int));
	if (p == NULL)
	{
		printf("Memory Allocation Failed!\n");
		return 1;
	}
	//Get the numbers from user
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&p[i]);
	}
	printf("The numbers in reverse order are - \n");
	for (int i = 0; i < n; i++)
	     printf("%d ",p[i]);
	printf("\n");
	free(p);
}
