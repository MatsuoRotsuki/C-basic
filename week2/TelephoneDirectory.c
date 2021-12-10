#include <stdio.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

typedef struct {
	char name[25];
	char tel[12];
	char email[25];
} phoneadd;



int main ()
{
	FILE *fptr;
	phoneadd *ptr;
	phoneadd phonearr[MAX_ELEMENT];
	int i, n, irc;//return code
	int reval = SUCCESS;
	printf("How many contacts do you want to enter (<20)?");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		printf("name:"); scanf("%s",&phonearr[i].name);
		printf("tel:"); scanf("%s",&phonearr[i].tel);
		printf("email:"); scanf("%s",&phonearr[i].email);
	}
	if ((fptr = fopen("Telephone Directory Book.txt","w"))== NULL)
	{
		printf("Cannot open %s.\n", "Telephone Directory Book.txt");
		reval = FAIL;
	}
	
	irc = fwrite(phonearr, sizeof(phoneadd), n, fptr);
	printf(" fwrite return code = %d\n",irc);
	fclose(fptr);
	//read from this file to array again
	if ((fptr = fopen("phonebook.dat","rb")) == NULL)
	{
		printf("Cannot open %s.\n","phonebook.dat");
		reval = FAIL;
	}
	irc = fread(phonearr, sizeof (phoneadd), n, fptr);
	printf(" fread return code = %d\n", irc);
	for ( i = 0; i< n; i++)
	{
		printf("%s-",phonearr[i].name);
		printf("%s-",phonearr[i].tel);
		printf("%s\n",phonearr[i].email);
	}
	fclose(fptr);
	return reval;
}