#include <stdio.h>
#define MAX_CHAR 26
int main ()
{
	int count [26] = {0};
	char f;
	while ((f = getchar()) != '\n')
	{
		if (f <= 'z' && f >= 'a')
		{
			++count[f-'a'];
		}
		if (f <= 'Z' && f >= 'A')
		{
			++count[f - 'A'];
		}
	}
	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (count[i] > 0)
		    printf("The letter '%c' appears %d time(s).\n",'a'+i,count[i]);    
	}
}
