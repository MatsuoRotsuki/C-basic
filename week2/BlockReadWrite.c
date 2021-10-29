#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80
};

int BlockWriteRead (FILE *in, FILE *out)
{
	int num;
	char buff[MAX_LEN+1];
	while (!feof(in))
	{
		num = fread(buff, sizeof(char), MAX_LEN, in);
		buff[num * sizeof(char)] = '\0';
		fwrite(buff, sizeof(char), num, out);
		puts(buff);
	}
}

int main ()
{
	FILE *fin, *fout;
	int reval = SUCCESS;
	if ((fin = fopen ("lab1.txt","r")) == NULL)
	{
		printf("Cannot open %s.\n","lab1.txt");
		reval = FAIL;
	}
	else if((fout = fopen("lab1a.txt","w")) == NULL)
	{
		printf("Cannot open %s.\n","lab1a.txt");
		reval = FAIL;
	}
	else {
		BlockWriteRead(fin,fout);
		fclose(fin);
		fclose (fout);
	}
	return reval;
}

