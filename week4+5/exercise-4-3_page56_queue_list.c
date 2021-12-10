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

typedef struct {
    char name[NAME_LENGTH+1];
    char tel[TEL_LENGTH+1];
    char email[EMAIL_LENGTH+1];
} ElementType;

typedef struct NodeType {
    ElementType inf;
    struct NodeType *next;
} List;

typedef struct {
    List *front, *rear;
} Queue;

List *create(){
    List *newnode = (List *)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->next = NULL;
    return newnode;
}

Queue *MakeNullQueue(){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if (Q == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    List *head = create();
    Q->front = head;
    Q->rear = head;
    return Q;
}

int isEmpty(Queue *Q){
    return (Q->front == Q->rear);
}

void push(Queue *Q, List *topush){
    Q->rear->next = create();
    Q->rear->inf = topush->inf;
    Q->rear = Q->rear->next;
}

ElementType pop(Queue *Q){
    if (!isEmpty(Q)){
        ElementType temp = Q->front->inf;
        List *T = Q->front;
        Q->front = Q->front->next;
        free(T);
        return temp;
    }
    else {
        printf("ERROR: Queue is empty!\n");
        exit(0);
    }
}

List *readFile(FILE *fin){
    List *newnode = create();
    fscanf(fin,"%s\n%s\n%s\n",newnode->inf.name , newnode->inf.tel, newnode->inf.email);
    return newnode;
}

void showQueue(Queue *Q)
{
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    } else {
        List *tg = Q->front;
        while (tg->next != NULL){
            printf("Name: %s\n", tg->inf.name);
            printf("Telephone number: %s\n",tg->inf.tel);
            printf("Email: %s\n",tg->inf.email);
            printf("---------------------------------\n");
            tg=tg->next;            
        }
    }
}

void writeFile(FILE *fout, Queue *Q){
    List *tg = Q->front;
    while (!isEmpty(Q)){
        ElementType temp = pop(Q);
        fprintf(fout,"%s\n%s\n%s\n",temp.name,temp.tel,temp.email);
    }
}

int main (){
    FILE *fptr1, *fptr2;
    Queue *newqueue = MakeNullQueue();
    char filename1[] = "Telephonebook.txt";
    char filename2[] = "Ex4-3.txt";
    if ((fptr1 = fopen(filename1,"r")) == NULL){
        printf("Cannot open %s\n",filename1);
        return 0;
    }
    else if ((fptr2 = fopen(filename2,"w")) == NULL){
        printf("Cannot open %s\n",filename2);
        return 0;
    }
    else {
        while(!feof(fptr1)){
            List *newnode = readFile(fptr1);
            push(newqueue, newnode);
        }

        printf("\n-----------Show Telephone List----------------\n");
        showQueue(newqueue);
        printf("\n-----------------$$$$$$$$$$-------------------\n");
        writeFile(fptr2, newqueue);
    }

    
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}