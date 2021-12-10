#include <stdio.h>
#include <stdlib.h>

// typedef struct {
//     char name[25];
//     char tel[12];
//     char email[30];
// } ElementType;

typedef int ElementType;

typedef struct NodeType {
    ElementType inf;
    struct NodeType *next;
} List;

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

void freelist(List *head){
    List *temp = head;
    while (temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
}

List *insert(List *head, ElementType x,int index){
    List *temp = create(x);
    if (index == 0){
        temp->next = head;
        return temp;
    }
    int count = 0;
    List *tg;
    for (tg = head; tg->next != NULL; tg=tg->next){
        count++;
    }
    if(index == count + 1){
        for (tg = head; tg->next!=NULL; tg=tg->next);
        tg->next = temp;
        return head;
    }
    else if(index > count+1){
        printf("Currently there are %d elements in list!\n", count+1);
        return head;
    }
    else {
        tg = head;
        int i;
        for (i = 0; i != index-1; i++){
            tg = tg->next;
        }
        temp->next = tg->next;
        tg->next = temp;
        return head;
    }
}

List *del(List *head, int index)
{
    List *tg;
    int count = 0;
    for (tg = head; tg != NULL; tg=tg->next) count++;
    if ((index > count-1) || (index < 0)){
        printf("Invalid index!\n");
        return head;
    }
    if (index == 0){
        tg = head;
        head = tg->next;
        free (tg);
        return head;
    }
    else {
        tg = head;
        int i;
        for (i = 0; i != index-1; i++){
            tg = tg->next;
        }
        List *del = tg->next;
        tg->next = del->next;
        free(del);
        return head;
    }
}

int main (){
    List *newlist = NULL;
    int i;

    for (i = 0; i<=50; i++){
        newlist = insert(newlist, i ,i);
    }
    newlist = del(newlist, 51);

    traverse(newlist);
    freelist(newlist);
    return 0;
}