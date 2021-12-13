#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _QueueNode {
    ElementType data;
    struct _QueueNode *next;
} QueueNode;

typedef struct _Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

QueueNode *createQueueNode(ElementType X){
    QueueNode *newnode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = X;
    newnode->next = NULL;
    return newnode;
}

Queue *createQueue(){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if (Q == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

int isEmtpy(Queue *Q){
    if (Q == NULL) return 1;
    return (Q->front == Q->rear);
}

void push(Queue *Q, ElementType X){}

ElementType pop(Queue *Q){

}

void QueueDestroy(Queue *Q){
    while(!isEmtpy(Q)) pop(Q);
    free(Q);
}