#include <stdio.h>
#include <stdlib.h>
enum{SUCCESS, FAIL
};



int main ()
{
	char filename[] = "out.txt";
	FILE *fptr;
	int n, i;
	int sum = 0;
	int *p;
	int reval = SUCCESS;
	if ((fptr = fopen(filename,"w")) == NULL)
	{
		printf("Cannot open %s.\n",filename);
		reval = FAIL;
	}
	else {
		scanf("%d",&n);
		p = (int *)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
		{
			scanf("%d",p+i);
			sum += *(p+i);
		}
		for (i = n-1; i >= 0; i--)
		{
			fprintf(fptr,"%d ",*(p+i));
		}
		fprintf(fptr,"%d ",sum);
		fclose(fptr);
		free(p);
	}
	return reval; 
}
