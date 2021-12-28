#include <stdio.h>

typedef int ElementType;

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = *a;
}

int partition(ElementType A[], int L, int R, int indexPivot){
    ElementType pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    for (int i = L; i <= R-1; i++){
        if (A[i] < pivot){
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(ElementType A[], int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if (L < index)
            quickSort(A, L, index-1);
        if (index < R)
            quickSort(A, index+1, R);
    }
}

void insertionSort(ElementType List[], int size){
    int i, j;
    ElementType next;
    for (i = 1; i < size; i++){
        next = List[i];
        for (j = i-1; j >= 0 && next < List[j]; j--)
            List[j+1] = List[j];
        List[j+1] = next;
    }
}

void selectionSort(ElementType List[], int size){
    int i, j, min;
    for (i = 0; i < size-1; i++){
        min = i;
        for (j = i+1; j < size-1; j++)
            if (List[j] < List[min]) min = j;
        swap(&List[i], &List[min]);
    }
}
