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

void inthongtin(ElementType data){
	printf("Name: %s\n", data.name);
	printf("Telephone number: %s\n", data.tel);
	printf("Email: %s\n", data.email);
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

List *docFile(FILE *fin){
    List *newnode = create();
    fscanf(fin,"%s\n%s\n%s\n",newnode->inf.name ,newnode->inf.tel, newnode->inf.email);
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

void Search (Queue *Q, char target[]){
    List *tg = Q->front;
    FILE *fout = fopen("Result 1-3.txt", "w");
    while (tg!=NULL){
        if ( strcmp (tg->next->inf.name, target) == 0) break;
        tg=tg->next;
    }
    if (tg == NULL){
        printf("NOT FOUND!\n");
        return;
        fprintf(fout, "NOT FOUND!\n");
    } else {
        List *r = tg->next;
        inthongtin(r->inf);
        fprintf(fout,"Name: %s\n", r->inf.name);
	    fprintf(fout,"Telephone number: %s\n", r->inf.tel);
	    fprintf(fout,"Email: %s\n", r->inf.email);        
    }
}

int main (){
    FILE *fptr1, *fptr2;
    Queue *newqueue = MakeNullQueue();
    char filename1[] = "input.txt";
    if ((fptr1 = fopen(filename1,"r")) == NULL){
        printf("Cannot open %s\n",filename1);
        return 0;
    }
    else {
        while(!feof(fptr1)){
            List *newnode = docFile(fptr1);
            push(newqueue, newnode);
        }
        char f[30];
        printf("Which name do you want to search: ");
        scanf("%s",&f);
        Search(newqueue, f);
    }
    fclose(fptr1);
    return 0;
}