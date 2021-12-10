#include <stdio.h>
#include <string.h>
char * my_strcat (char a[], char b[])
{
	char *charptr;
	charptr = (char*)malloc((strlen(a)+strlen(b)+1) * sizeof(char));
    if (charptr == NULL)
    {
    	printf("Memory Allocation Failed!\n");
    	return NULL;
	}
	strcpy(charptr, a);
    strcpy(charptr+strlen(a), b);
    
    return charptr;
}

int main ()
{
	char s1[10]="hello_";
	char s2[10]="world";
	char *ptr = my_strcat(s1,s2);
	printf("%s", ptr);
	free(ptr);
}
