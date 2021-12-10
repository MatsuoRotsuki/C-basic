#include <stdio.h>
#define NOTFOUND -1

typedef int ElementType;

int BinarySearch (ElementType A[], ElementType X, int N){
    int l,m,r;
    l = 0; r = N -1;
    while (l <= r){
        m = (l + r)/2;
        if (A[m] < X)
            l = m + 1;
        else if (A[m] > X)
            r = m - 1;
        else 
            return m;
    }
    return NOTFOUND;
}

int main (){
    ElementType A[] = {1,3,5,7,9,13,15};
    int SizeofA = sizeof(A) / sizeof(A[0]);
    int i;
    for (i = 0; i < 20; i++){
        printf("Binary Search of %d returns %d\n",i,BinarySearch(A,i,SizeofA));
    }
    return 0;
}