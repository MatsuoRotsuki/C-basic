#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTFOUND -1

typedef struct _Address {
	char name[20], tel[12], email[50];
} Address;

typedef struct Node {
    Address data;
    struct Node *next;
} List;

void inthongtin(Address data){
	printf("Name: %s\n", data.name);
	printf("Telephone number: %s\n", data.tel);
	printf("Email: %s\n", data.email);
}

List *create(Address temp){
    List *newnode = (List *)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }
    
    newnode->data = temp;
    newnode->next = NULL;
    return newnode;
}

List *Insert_ToLast(List *head, Address X)
{
    List *newnode,*temp;
    newnode=create(X);
    
    if(head==NULL) {
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
    return head;
}

List *h = NULL;

void docFile(){
	FILE *f = fopen("input.txt", "r");
	if (f == NULL){
		printf("Cannot open read file.\n");
		exit(0);
	}
	int i = 0;
	while (!feof(f)){
        Address temp;
		fscanf(f,"%s\n%s\n%s\n", &temp.name, &temp.tel, &temp.email);
        h = Insert_ToLast(h, temp);
	}
    fclose(f);
}

void duyetds(List *head){
    List *tg=head;
    printf("\n");
    while(tg!=NULL){
        inthongtin(tg->data);
        tg=tg->next;
    }    
}

void freelist(List *head){
    List *tg=head,*temp;
    while(tg!=NULL){
        temp=tg->next;
        free(tg);
        tg=temp;
    }    
}


void Search (List *head, char target[]){
    List *tg = head;
    FILE *fout = fopen("Result 1-2.txt", "w");
    while (tg!=NULL){
        if ( strcmp (tg->next->data.name, target) == 0) break;
        tg=tg->next;
    }
    if (tg == NULL){
        printf("NOT FOUND!\n");
        return;
        fprintf(fout, "NOT FOUND!\n");
    }
    else {
        List *r = tg->next;
        tg->next = tg->next->next;
        r->next = head;
        head = r;
        printf("FOUND!\n");
        inthongtin(head->data);
        fprintf(fout,"Name: %s\n", head->data.name);
	    fprintf(fout,"Telephone number: %s\n", head->data.tel);
	    fprintf(fout,"Email: %s\n", head->data.email);
    }
    fclose(fout);
}

int main (){
    docFile();
    char f[30];
    printf("Which name do you want to search: ");
    scanf("%s",&f);
    Search(h, f);
    freelist(h);
    return 0;
}