#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { SUCCESS, FAIL
};

typedef struct {
	char name[30];
	char tel[12];
	char email[30];
} Address;

typedef struct list_el{
	Address addr;
	struct list_el *next;
} List;

List *head = NULL,*cur = NULL,*prev = NULL;

List *create(Address addr)
{
	List *newnode = (List *)malloc(sizeof(List));
	if (newnode == NULL)
	{
		printf("Memory Allocation Eror!\n");
		exit(0);
	}
	newnode->addr = addr;
	newnode->next = NULL;
	return newnode;
}

void insert_toHead(Address addr)
{
	List *newnode = create(addr);
	if (head == NULL){
		head == newnode;
		cur = head;
	}
	newnode->next = head;
	head = newnode;
	cur = head;
}

void insertACurrent(Address addr)
{
	List *newnode = create(addr);
	if (head == NULL && cur == NULL)
	    return;
	if (head == NULL){
		head = newnode;
		cur = head;
	} else {
		newnode->next = cur->next;
		cur->next=newnode;
		cur = cur->next;
	}
	return;
}

void insertBCurrent(Address addr)
{
	List *newnode = create(addr);
	if (head == NULL){
		head = newnode;
		cur = head;
		prev = NULL;
	} else {
		newnode->next = cur;
		if (cur == head){
			head = newnode;
		}
		else prev->next = newnode;
		cur = newnode;
	}
}

List *DeleteFirst(List *head)
{
	List *del;
	del = head;
	head=head->next;
	free(del);
	return head;
}

void *Delete_Middle(List *head)
{
	List *del = head;
	if (cur == NULL) return;
	if (cur == head) {
	    DeleteFirst(head);
	    return;
	}
	else {
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	return;
}

List *Reverse(List *head)
{
	
}




int main ()
{
	
}
