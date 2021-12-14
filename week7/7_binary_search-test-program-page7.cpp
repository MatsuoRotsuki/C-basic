#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTFOUND -1

typedef int ElementType;

int newBinarySearch(ElementType A[], ElementType X, int N){
	int l,m,r;
	l = 0; r = N - 1;
	while (l <= r){
		m = (l+r)/2;
		if (A[m] < X)
		    l = m + 1;
		else if(A[m] > X)
		    r = m - 1;
		else return m; //Found
	}
	return NOTFOUND;
}
/* EXERCISES PAGE 8
Implement a recursive version of a
binary search function.
*/
int recursiveBinarySearch(ElementType A[],ElementType X, int l, int r){
	if (l == r) return -1;
	int m = (l+r)/2;
	if (A[m] == X) return m;
	else if (A[m] < X) return recursiveBinarySearch(A, X, m+1,r);
	else if (A[m] > X) return recursiveBinarySearch(A, X, l, m-1);
	return -1;
}

//int BinarySearch_dictorder (phoneaddress A[], char name[], int N){
//	int l, m, r;
//	l = 0; r = N - 1;
//	while (l <= r){
//		m = (l+r)/2;
//		if (strcmp(A[m].name,name) < 0) l = m + 1;
//		else if (strcmp(A[m].name,name) > 0) r = m - 1;
//		else return m;
//	}
//	return NOTFOUND;
//}

int main ()
{
	static int A[] = {1,3,5,7,9,13,15};
	int i;
	for (i = 0; i < 20; i++){
		printf("The %d to %d\n",i,recursiveBinarySearch(A,i,0,6));
	}
	return 0;
}

