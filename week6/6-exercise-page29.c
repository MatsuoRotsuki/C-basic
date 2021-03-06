#include <stdio.h>
#include <stdlib.h>
#define NOTFOUND -1
typedef int ElementType;

int RecursiveBinSearch(ElementType A[], ElementType X, int l, int r){
    if (l > r) return NOTFOUND;
    int m = (l+r)/2;
    printf("m = %d\n", m);
    if (A[m] > X) return RecursiveBinSearch(A, X,l,m-1);
    else if (A[m] < X) return RecursiveBinSearch(A,X,m+1,r);
    else return m;
    return NOTFOUND;
}

int main (){
    ElementType A[100]; //not random integers but ordered array of integers
    int i;
    for (i = 0; i < 100; i++){
        A[i] = i+1;
    }
    int target, found;
    printf("Which number do you want to search: ");
    scanf("%d",&target);
    if ((found =RecursiveBinSearch(A,target,0,100-1)) == -1) printf("NOT FOUND!\n");
    else printf("Result = %d",found);
    return 0;
}