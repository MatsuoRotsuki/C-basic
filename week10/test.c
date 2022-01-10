#include <stdio.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20
};

typedef struct {
	char name[20];
	char tel[11];
	char email[25];
} phoneaddress;

int main (){
	FILE *fp;
	phoneaddress phonearr[MAX_ELEMENT];
	int i,n,irc;
	int reval = SUCCESS;
	printf("How many contacts do you want to enter(<20)?");
	scanf("%d",&n);
	for (i = 0; i < n; i++){
		printf("Name: "); scanf("%s",phonearr[i].name);
		printf("Tel: "); scanf("%s",phonearr[i].tel);
		printf("Email: "); scanf("%s",phonearr[i].email);
	}
	if ((fp = fopen("phonebook.dat","w+b")) == NULL){
		printf("Cannot open %s,\n", "phonebook.dat");
		reval = FAIL;
	}
	irc = fwrite(phonearr, sizeof(phoneaddress), n, fp);
	printf(" fwrite return code = %d\n",irc);
	fclose(fp);
	
	if ((fp = fopen("phonebook.dat", "rb")) == NULL){
		printf("Cannot open %s,\n", "phonebook.dat");
		reval = FAIL;		
	}
	
	irc = fread(phonearr, sizeof(phoneaddress), n, fp);
	printf(" fread return code = %d\n", irc);
	for (i = 0; i < n; i++){
		printf("%s-",phonearr[i].name);
		printf("%s-",phonearr[i].tel);
		printf("%s\n",phonearr[i].email);
	}
	fclose(fp);
	return reval;
}
