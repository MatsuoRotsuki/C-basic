#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 30
#define TEL 15
#define ADDR 50


typedef struct {
    char name[NAME];
    char tel[TEL];
    char email[ADDR];
} Address;

typedef struct _Node{
    Address data;
    struct _Node *next;
} List;

List *create(Address X){
    List *newnode = (List*)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = X;
    newnode->next = NULL;
    return newnode;
}

void inthongtin(Address temp){
    printf("\nName: %s\n",temp.name);
    printf("Telephone number: %s\n",temp.tel);
    printf("Email: %s\n",temp.email);
}

void traverse(List *head){
    List *tg = head;
    while(tg!= NULL){
        inthongtin(tg->data);
        tg = tg->next;
    }
}

void freelist(List *head){
    List *temp = head;
    while(temp!= NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
}

List *SortedMerge(List *a, List *b);
void FrontBackSplit(List *source, List** frontRef, List** backRef);
void mergeSort(List** headRef){
    List *head = *headRef;
    List *a, *b;

    /*Base case -- length 0 or 1*/
    if ((head == NULL) || (head->next == NULL)){
        return;
    }
    
    /*Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a,&b);

    /*Recursively sort the sublists*/
    mergeSort(&a);
    mergeSort(&b);

    /*if answer = merge the two sorted lists together*/
    *headRef = SortedMerge(a, b);
}

List *SortedMerge(List *a, List *b){
    List *result = NULL;

    /*Base cases*/
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    
    /*Pick either a or b, and recur*/
    if (strcmp(a->data.name, b->data.name) <= 0){
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

/*UTILITY FUNCTION*/
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(List *source, List** frontRef, List** backRef){
    List *fast, *slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while(fast != NULL){
        fast = fast->next;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void push(List **head, Address new_data){
    List *newnode = create(new_data);

    newnode->next = (*head);

    (*head) = newnode;
}