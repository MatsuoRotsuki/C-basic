#include <stdio.h>
#include <stdlib.h>

enum{SUCCESS, FAIL};

int main ()
{
    FILE *fptr;
    int reval = SUCCESS;
    if ((fptr = fopen("out.txt","w")) == NULL)
    {
        printf("Cannot open %s.\n","out.txt");
        reval = FAIL;
    }
    char fname[] = "out.txt";
    int *p;
    int i, n, value, sum;

    printf("Enter a list of numbers with the first is the size of list: \n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    i = 0; sum = 0;
    while (i < n)
    {
        scanf("%d", &value);
        p[i++] = value;
        sum+=value;
    }
    for (i = n -1; i >=0; i--)
    {
        fprintf(fptr,"%d ",p[i]);
    }
    fprintf(fptr,"%d ",sum);
    fclose(fptr);
    free(p);
    return reval;
}