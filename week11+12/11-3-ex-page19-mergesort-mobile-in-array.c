#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    NAME_LENGTH = 30,
    TEL_LENGTH = 15,
    EMAIL_LENGTH = 50,
};

typedef struct {
    char name[NAME_LENGTH];
    char tel[TEL_LENGTH];
    char email[EMAIL_LENGTH];
} Address;

Address Data[11];
int n;

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
    printf("Name: %s\n",temp.name);
    printf("Telephone number: %s\n",temp.tel);
    printf("Email: %s\n",temp.email);
}
void printArray(Address List[], int size){
    int i;
    for (i = 0; i < size; i++){
        inthongtin(List[i]);
    }
    printf("\n");
}

void docfile(){
    FILE *fin = fopen("input.dat","rb");
    if (fin == NULL){
        printf("Cannot open input file!\n");
        exit(0);
    }
    int irc = fread(Data, sizeof(Address), 10, fin);
    n = irc;
    //printf("%d\n",irc);
    // for (int i = 1; i <= irc; i++){
    //     inthongtin(Data[i]);
    // }
    fclose(fin);
}

int main (){
    docfile();
    mergeSort(Data, 0,n-1);
    printArray(Data, n);
}