#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {
    SUCCESS, FAIL,
    NAME_LENGTH = 30,
    EMAIL_LENGTH = 50,
    TEL_LENGTH = 12,
    MAX = 50
};

typedef struct NodeType {
    char name[NAME_LENGTH+1];
    char tel[TEL_LENGTH+1];
    char email[EMAIL_LENGTH+1];
    struct NodeType *next;
} List;

int isEmpty(List *head){
    return (head == NULL);
}

int isFull(List *head){
    int count = 0;
    List *cur = head;
    while (cur != NULL){
        count++;
        cur=cur->next;
    }
    return (count == MAX);
}

List *declare(){
    List *newnode = (List *)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
    }

    newnode->next = NULL;
    return newnode;
}

List *create(){
    List *newnode = declare();
    printf("Enter name: "); gets(newnode->name);
    fflush(stdin);
    printf("Enter email: "); gets(newnode->email);
    fflush(stdin);
    printf("Enter telephone number: "); gets(newnode->tel);
    fflush(stdin);
    return newnode;
}

List *push(List *head, List *newnode)
{
    if (isFull(head)){
        printf("Failing to push! Stack overflow\n");
        return head;
    }
    if (isEmpty(head)){
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    printf("Push successfully!\n");
    return head;
}

List *pop(List *head){
    if (isEmpty(head)){
        printf("Failing to pop! Stack underflow\n");
        return head;
    } else {
        List *topop = head;
        head = head->next;
        free(topop);
        printf("Pop successfully!\n");
        return head;
    }
}

List *readFile(FILE *fin){
    List *newnode = declare();
    fscanf(fin,"%s\n%s\n%s\n", newnode->name, newnode->tel, newnode->email);
    return newnode;
}

void showList(List *head){
    if (isEmpty(head)){
        printf("List is empty!\n");
        return;
    } else {
        List *tg = head;
        while (tg != NULL){
            printf("Name: %s\n", tg->name);
            printf("Telephone number: %s\n",tg->tel);
            printf("Email: %s\n",tg->email);
            printf("---------------------------------\n");
            tg = tg->next;
        }
    }
}

List *writeFile(FILE *fout, List *head){
    while (head != NULL){
        fprintf(fout,"%s\n%s\n%s\n",head->name,head->tel,head->email);
        head = pop(head);
    }
    return head;
}

int main ()
{
    FILE *fptr1, *fptr2;
    List *newlist = NULL;
    char filename1[] = "Telephonebook.txt";
    char filename2[] = "Copy_of_telephonebook.txt";
    if ((fptr1 = fopen(filename1,"r")) == NULL){
        printf("Cannot open %s\n",filename1);
        return 0;
    }
    else if ((fptr2 = fopen(filename2,"w")) == NULL){
        printf("Cannot open %s\n", filename2);
        return 0;
    } else {
        while (!feof(fptr1)){
            List *newnode = readFile(fptr1);
            newlist = push(newlist, newnode);
        }

        printf("\n-----------Show Telephone List----------------\n");
        showList(newlist);
        printf("\n-----------------$$$$$$$$$$-------------------\n");
        newlist = writeFile(fptr2, newlist);
        if (newlist == NULL){
            printf("COPY SUCCESS\n");
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}