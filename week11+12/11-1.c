#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[30];
    char tel[15];
    char email[50];
} Address;

Address data[100];
int count;

void readFile (){
    FILE *fin = fopen ("input.txt","r");
    if (fin == NULL){
        printf("Cannot open read file\n");
        exit(0);
    }
    Address temp;
    int i = 0;
    while (!feof(fin)){
        fscanf(fin,"%s\n%s\n%s\n", &temp.name , &temp.tel, &temp.email );
        data[i] = temp;
        i++;
    }
    count = i;
    fclose(fin);
}

void swap (Address *a, Address *b){
    Address temp = *a;
    *a = *b;
    *b = temp;
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

void quicksort(Address A[], int L, int R){
    if (L < R){
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if (L < index)
            quicksort(A, L, index-1);
        if (index < R)
            quicksort(A, index+1, R);
    }
}


int main (){
    FILE *fout = fopen("output.txt","w");
    readFile();
    quicksort(data, 0, count-1);
    int i;
    for (i = 0; i < count; i++) fprintf(fout, "%s\n%s\n%s\n", data[i].name, data[i].tel, data[i].email);
    fclose(fout);
    return 0;
}