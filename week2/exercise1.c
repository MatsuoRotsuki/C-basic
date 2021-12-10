#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void * my_strcat (char s1[], char s2[])
{
	char *p;
	p = (char *)malloc((strlen(s1)+strlen(s2)) * sizeof(char));
	strcpy(p, s1);
	strcpy(p + strlen(s1),s2);
	return p;
}

int main ()
{
	char a1[10] ="hello_";
	char a2[10] ="world";
	//printf("s1 s2 = ");
	//scanf("%s", &a1);
	//scanf("%s", &a2);
	char * ptr = my_strcat(a1,a2);
	printf("%s", ptr);
	free(ptr);
}
