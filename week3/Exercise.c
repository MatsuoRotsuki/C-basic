#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 10
//Implementation of List in C

typedef struct Student_t {
	char num[MAX_LENGTH + 1];
	struct Student_t *next;
} Student_t;

void insert(int n)
{
}
void del(int n);

int main ()
{
	Student_t *a,*b,*c,*e,*f;
	Student_t *root = a, *cur, *newnode,*prev;
	a->next = b;
	b->next = c;
	c->next = e;
	e->next = f;
	f->next = NULL;
	strcpy(a->num,"AAAAA");
	strcpy(b->num,"BBBBB");
	strcpy(c->num,"CCCCC");
	strcpy(e->num,"EEEEE");
	strcpy(f->num,"FFFFF");
	newnode = (Student_t*)malloc(sizeof(Student_t));
	//scanf("%s",newnode->num);
	strcpy(newnode->num,"NNNNN");
	cur = b;
	//newnode->next = cur->next;
	//cur->next = newnode;
	//cur = cur->next;
	for (prev = root; prev->next!= cur; prev=prev->next);
	prev->next = cur->next;
	free(cur);
	for (cur = root; cur!= NULL; cur=cur->next)
	{
		printf("%s",cur->num);
	}
	return 0;
}
