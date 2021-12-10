#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOUND 1
#define NOTFOUND -1
#define NAMELENGTH 30
#define EMAILLENGTH 50
#define TELLENGTH 12

typedef struct {
	char name[NAMELENGTH];
	char tel[EMAILLENGTH];
	char email[TELLENGTH];
} Address;

typedef struct NodeType{
	Address addr;
	struct NodeType *next;
} List;


List *create()
{
	List *newnode = (List *)malloc(sizeof(List));
	if (newnode == NULL){
		printf("Memory Allocation Error!\n");
		exit(0);
	}
	
	newnode->next = NULL;
	return newnode;
}

void Displaynode(List *p)
{
	if (p == NULL) 
	{
		printf("NULL!\n");
		return;
	}
	printf("Name: %s\n", p->addr.name);
	printf("Tel: %s\n", p->addr.tel);
	printf("Email: %s\n", p->addr.email);
	return;
}

void TraverseList(List *head)
{
	List *p = head;
	while (p != NULL){
		Displaynode(p);
		p = p->next;
	}
	printf("\n");
}

void freelist(List *head){
	List *tg;
	while (head != NULL){
		tg = head->next;
		free(head);
		head = tg;
	}
	printf("Free list successfully!\n");
}

List *Insert_ToLast(List* head, Address x)
{
	List *newnode, *temp;
	newnode = create();
	newnode->addr = x;
	if (head == NULL)
	{
		head = newnode;
	}
	else {
		temp = head;
		while (temp->next != NULL)
		    temp = temp->next;
		temp->next = newnode;
	}
	return head;
}

Address readFile(FILE *fin){
	Address temp;
	fscanf(fin, "%s\n%s\n%s\n", &temp.name, &temp.tel, &temp.email);

	return temp;
}

void writeFile(FILE *fout, List *found){
	if (found == NULL) return;
	fprintf(fout, "%s\n%s\n%s\n", found->addr.name, found->addr.tel, found->addr.email);
}

List *SearchLinear(List *head,char target[]){
    List *tg = head;	
	while (tg !=NULL){
		if (strcmp(tg->addr.name, target) == 0) return tg;
		tg = tg->next;
	}
	return NULL;
}

int main ()
{
	FILE *fptr1, *fptr2;
	List *head = NULL;
	char filename1[] = "Telephonebook.txt";
	char filename2[] = "Copyoftelephonebook.txt";
	if ((fptr1 = fopen(filename1, "r")) == NULL){
		printf("Cannot open %s\n",filename1);
		return 0;
	}
	else if ((fptr2 = fopen(filename2, "w")) == NULL){
		printf("Cannot open %s\n",filename2);
		return 0;
	}
	else {
		while (!feof(fptr1)){
			Address temp = readFile(fptr1);
			head = Insert_ToLast(head, temp);
		}
		printf("\n");
		//TraverseList(head);
		char temp[NAMELENGTH];
		printf("Please enter a name: "); scanf("%s",&temp);
		printf("\nResult:\n");
		List *found = SearchLinear(head, temp);
		if(found == NULL) printf("Cannot find the name in telephone book!\n");
		else Displaynode(found);
		printf("\n---------------------\n");
		writeFile(fptr2, found);
	}
	
	fclose(fptr1);
	fclose(fptr2);
	freelist(head);
	return 0;
}
