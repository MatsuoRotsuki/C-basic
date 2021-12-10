#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 10

typedef int ElementType;

typedef struct {
    ElementType Elements[MAXLENGTH];
    int rear, front;
} Queue;

void MakeNullQueue(Queue *Q){
    Q->front = Q->rear = -1;
}

int isEmpty(Queue Q){
    return (Q.front == -1);
}

int isFull(Queue Q){
    return ((Q.rear-Q.front+1) == MAXLENGTH);
}

void push(Queue *Q, ElementType X){
    if (!isFull(*Q)){
        if(isEmpty(*Q)) Q->front = 0;
        Q->rear++;
        Q->Elements[Q->rear] = X;
    }
    else printf("Queue is full!\n");
}

void pop (Queue *Q){
    if (!isEmpty(*Q)){

    } else {
        printf("Queue is empty!\n");
    }
}

int main ()
{
    
    
}
