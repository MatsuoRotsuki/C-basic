#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[25];
    char tel[12];
    char email[30];
} ElementType;

typedef struct NodeType {
    ElementType inf;
    struct NodeType *next;
} List;

List *cur = NULL, *head = NULL;

List *create(ElementType X){
    List *newnode = (List *)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->inf = X;
    newnode->next = NULL;
    return newnode;
}

void traverse(List *head){
    List *tg = head;
    printf("---------------Traversing--------\n");
    while(tg != NULL){
        printf("%d ",tg->inf);
        tg = tg->next;
    }
}

List *remove(List *head, List *del)
{
    if (head == del){
        head = del->next;
        free(del);
        return head;
    }
    List *prev;
    for (prev = head; prev->next != del; prev=prev->next)
    prev->next = del->next;
    free(del);
    return head;
}

List *insert_toHead(List *head, ElementType x){
    if (head == NULL){
        head = create(x);
        return head;
    }
    else {
        List *newnode = create(x);
        newnode->next = head;
        return newnode;
    }
}

List *insert_toLast(List *head, ElementType x){
    List *newnode, *temp;
    newnode = create(x);

    if (head == NULL){
        head = newnode;
    }
    else {
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

void insert_toMiddle(List *prev, ElementType x){
    if (prev == NULL) return;
    List *newnode = create(x);
    newnode->next = prev->next;
    prev->next = newnode;
}

int main (){
    
}