#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct NodeType{
	ElementType data;
	struct NodeType *next;
} List;

//Ham Push
List *push (List *p, ElementType x)
{
	List *temp = (List *)malloc(sizeof(List));
	if (temp == NULL)
	{
		printf("Memory Allocation Error\n");
		exit(0);
	}
	temp->data = x;
	temp->next = p;
	p = temp;
	return p;
}

//Ham POP
List *pop (List *p, ElementType *value)
{
	List *temp;
	if (p == NULL)
	{
		printf("Empty stack cannot pop!\n");
		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->next;
	free(temp);
	return p;
}

void freelist(List *head)
{
	List *tg = head;
	List *temp = NULL;
	while(tg!=NULL)
	{
		temp = tg->next;
		free(tg);
		tg=temp;
	}
}

void duyetds(List *head)
{
	List *tg = head;
	while (tg!=NULL)
	{
		printf("%c",tg->data);
		tg=tg->next;
    }
}

int main ()
{
	List *danhsach;
	char string[]="ailacondicuaanhnao";
	for (int i = 0; i < strlen(string); i++)
	    danhsach = push(danhsach, string[i]);
	duyetds(danhsach);
	freelist(danhsach);
	return 0;
}
