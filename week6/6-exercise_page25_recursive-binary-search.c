#include<stdio.h>
#include<stdlib.h>
#define NOTFOUND -1
typedef int ElementType;

int RecursiveBinarySearch(ElementType A[], ElementType X, int l, int r){
    if (l > r) return NOTFOUND; 
    int m = (l + r)/2;
    if (A[m] > X) return RecursiveBinarySearch(A, X, l, m-1);
    else if (A[m] < X) return RecursiveBinarySearch(A, X, m+1, r);
    else return m; //FOUND
    return NOTFOUND;
}

int main (){
    static ElementType A[] = {1,3,5,7,9,11,13,15};
    int size = sizeof(A) / sizeof(A[0]);
    int i;
    for (i = 0; i < 20; i++){
        printf("Recursive Binary Search of %d returns %d\n",i,RecursiveBinarySearch(A,i,0,size-1));
    } 
}