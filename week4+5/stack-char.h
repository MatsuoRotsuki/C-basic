#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY -1

typedef char ElementType;

typedef struct _StackNode {
    ElementType data;
    struct _StackNode *next;
} StackNode;

typedef struct _Stack {
    StackNode *top;
} Stack;

int isEmpty(Stack *s){
    if (s == NULL) return 1;
    if (s->top == NULL) return 1;
    else return 0;
}

StackNode *createNode (ElementType X){
    StackNode *newnode = (StackNode *)malloc(sizeof(StackNode));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = X;
    newnode->next = NULL;
    return newnode;
}

Stack *createStack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    s->top = NULL;
    return s;
}

void push (Stack *s, ElementType X){
    if (s == NULL) return;
    StackNode *newnode = createNode(X);
    newnode->next = s->top;
    s->top = newnode;
}

ElementType pop (Stack *s){
    if (s == NULL) return INFINITY;
    if (s->top == NULL) return INFINITY;

    ElementType X = s->top->data;
    StackNode *tg = s->top;
    s->top = s->top->next;
    free(tg);
    return X;
}

void StackDestroy(Stack *s){
    while(!isEmpty(s)) pop(s);
    free(s);
}

