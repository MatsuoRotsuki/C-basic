#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80
};

void BlockReadWrite(FILE *fin, FILE *fout)
{
	int num;
	char buff[MAX_LEN+1];
	while (!feof(fin))
	{
		num = fread(buff, sizeof(char), MAX_LEN, fin);
		buff[num * sizeof(char)] = '\0';
		puts(buff);
		fwrite(buff, sizeof(char), num, fout);
	}
}

int main (int argc, char* argv[])
{
	FILE *fptr1, *fptr2;
	int reval = SUCCESS;
	if (argc != 3)
	{
		printf("Not enough argument!\n");
		printf("The correct syntax should be: ./filecpy filename1 filename2\n");
		reval = FAIL;		
	}
	if ((fptr1 = fopen(argv[1],"r")) == NULL)
	{
		printf("Cannot open %s.\n",argv[1]);
		reval = FAIL;
	}
	else if ((fptr2 = fopen (argv[2],"w")) == NULL)
	{
		printf("Cannot open %s.\n", argv[2]);
		reval = FAIL;
	}
	else {
		BlockReadWrite(fptr1, fptr2);
		fclose (fptr1);
		fclose(fptr2);
	}
	return reval;
}

