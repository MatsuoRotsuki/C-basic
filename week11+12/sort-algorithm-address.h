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

void heapify(Address List[], int size, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && strcmp(List[l].name, List[largest].name) > 0)
        largest = l;

    if (r < size && strcmp(List[r].name, List[largest].name) > 0)
        largest = r;
    
    if (largest != i) {
        swap (&List[i], &List[largest]);
        heapify(List, size, largest);
    }
}

void heapSort(Address List[], int size){
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(List, size, i);
    
    for (int i = size - 1; i > 0; i --){
        swap(&List[0], &List[i]);

        heapify(List, i, 0);
    }
}

//mergeSort
void merge(Address List[], int L, int M, int R){
    int i, j, k;
    int n1 = M - L + 1;
    int n2 = R - M;

    /*create temp arrays*/
    Address Left[n1], Right[n2];
    
    /*Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        Left[i] = List[L+i];
    for (j = 0; j < n2; j++)
        Right[j] = List[M + 1 + j];
    
    /*Merge the temp arrays back into arr[1...r]*/
    i = 0; j = 0; k = L;
    while(i < n1 && j < n2){
        if (strcmp(Left[i].name, Right[j].name) <= 0){
            List[k] = Left[i];
            i++;
        }
        else {
            List[k] = Right[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there are any */
    while(i < n1){
        List[k] = Left[i];
        i++;
        k++;
    }

    while(j < n2){
        List[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(Address List[], int L, int R){
    if (L < R){
        int M = L + (R - L) / 2;
        mergeSort(List, L, M);
        mergeSort(List,M+1,R);
        merge(List,L,M,R);
    }
}

void inthongtin(Address temp){
    printf("\nName: %s\n",temp.name);
    printf("Telephone number: %s\n",temp.tel);
    printf("Email: %s\n",temp.email);
}