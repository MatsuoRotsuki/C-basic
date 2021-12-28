#include <stdio.h>
#include <string.h>
#define NAME 30
#define TEL 15
#define ADDR 50


typedef struct {
    char name[NAME];
    char tel[TEL];
    char email[ADDR];
} Address;

void swap (Address *a, Address *b){
    Address temp = *a;
    *a = *b;
    *b = *a;
}

int partition(Address A[], int L, int R, int indexPivot){
    Address pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    int i;
    for (i = L; i <= R-1; i++){
        if (strcmp(A[i].name, pivot.name) < 0){
            swap( &A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(Address A[], int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if (L < index)
            quickSort(A, L, index-1);
        if (index < R)
            quickSort(A, index+1, R);
    }
}

void insertionSort(Address List[], int size){
    int i, j;
    Address next;
    for (i = 1; i < size; i++){
        next = List[i];
        for (j = i-1; j >= 0 && (strcmp (next.name, List[j].name) < 0); j--)
            List[j+1] = List[j];
        List[j+1] = next;
    }
}

void selectionSort(Address List[], int size){
    int i, j, min;
    for (i = 0; i < size-1; i++){
        min = i;
        for (j = i+1; j < size-1; j++)
            if (strcmp (List[j].name, List[min].name) < 0) min = j;
        swap(&List[i], &List[min]);
    }
}

