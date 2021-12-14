#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

typedef struct {
    int key;
    /*other fields*/
} ElementType;

ElementType list[MAXSIZE];

int binsearch(ElementType a[], int X, int l ,int r){
    if (l > r) return -1;
    int m = (l+r)/2;
    if (a[m].key > X) return binsearch(a,X,l,m-1);
    else if (a[m].key < X) return binsearch(a,X,m+1,r);
    else return m;
    return -1;
}

void verify1(ElementType list1[], ElementType list2[], int n, int m)
//compare two unordered lists
{
    int i, j;
    int marked[MAXSIZE];

    for (i = 0; i < n; i++)
        if((j = binsearch(list2, list1[i].key, 0,m-1)) < 0)
            printf("%d is not in list 2\n",list1[i].key);
        else;
}