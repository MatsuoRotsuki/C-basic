#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int L, int R, int indexPivot){
    int pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    int i;
    for (i = L; i <= R-1; i++){
        if (A[i] < pivot){
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(int A[], int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if (L < index)
            quickSort(A, L, index-1);
        if (index < R)
            quickSort(A, index+1, R);
    }
}

void insertion_sort(int A[], int n){
    int i, j;
    int next;
    for (i = 1; i < n; i++){
        next = A[i];
        for (j = i-1; j >= 0 && next < A[j]; j--)
            A[j+1] = A[j];
        A[j+1] = next;
    }
}

void indanhsach(int List[], int n){
    int i;
    for (i = 0; i < n; i++) 
        printf("%d ",List[i]);
}

int main (){
    int n,i;
    printf("Nhap n: "); scanf("%d",&n);
    int List[100];
    for (i = 0; i < n; i++)
        List[i] = rand()%100;
    // for (i = 0; i < n; i++){
    //     printf("n[%d] = ",i+1);
    //     scanf("%d", &List[i]);
    // }
    //insertion_sort(List, n);
    quickSort(List, 0, n-1);
    indanhsach(List, n);
    return 0;
}

// Insertion sort: mất 1.433 giây n = 10
// Quick sort: 0.6417 giây với n =10

// Insertion sort: mất 1.265 giây n = 100
// Quick sort: 0.9825 giây với n = 100
