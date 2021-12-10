#include <stdio.h>
#include <stdlib.h>

enum{SUCCESS, FAIL, MAX_LEN = 80
};

int EFile(FILE *fin)
{
	int num;
	char buff[MAX_LEN+1];
	while (!feof(fin))
	{
		while((num = fgetc(fin))!= '\n');
		fprintf(fin,"\n");
	}
}

int main ()
{
	FILE *fptr;
	int reval = SUCCESS;
	
	if ((fptr = fopen("class1EF.txt","w")) == NULL)
	{
		printf("Cannot open %s.\n","class1EF.txt");
		reval = FAIL;
	}
	else {
		EFile(fptr);
		fclose(fptr);
	}
	return reval;
}
