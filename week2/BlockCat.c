#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80
};

void BlockCat(FILE *fin)
{
    int num ;
    char buff[MAX_LEN+1];
    while (!feof(fin))
    {
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        printf("%s",buff);
    }
}

int main (int argc, char *argv[])
{
    FILE *fptr;
    int reval = SUCCESS;
    if(argc != 2)
    {
        printf("Not enough argument!\n");
        printf("Correct syntax: ./BlockCat filename\n");
        reval = FAIL;
    }
    if ((fptr = fopen(argv[1],"r")) == NULL)
    {
        printf("Cannot open %s.\n",argv[1]);
        reval = FAIL;
    }
    else {
        BlockCat(fptr);
        fclose (fptr);
    }
    return reval;
}
