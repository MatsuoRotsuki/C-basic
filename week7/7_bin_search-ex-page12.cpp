#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTFOUND -1
/*
  Define an array of integers, load from 1
to 100 in order to the array.
  Read a number from the standard input,
perform the binary search for an array.
Output "Not Found" if the array does not
have it.
   When you perform the binary search,
output the array index compared to the
standard output. Also, display the number
of comparisons achieved until the target
number is found.*/
typedef int ElementType;

int recurBinsearch(ElementType a[], ElementType x, int l, int r)
{
	if (l > r) return NOTFOUND;
	int m = (l + r)/2;
	printf("m = %d\n",m);
	if (a[m] > x) return recurBinsearch(a, x, l, m-1);
	else if (a[m] < x) return recurBinsearch(a, x, m+1, r);
	else {
		printf("Found!\n");
		return m;
	}
	return NOTFOUND;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main (){
	int target, i, j;
	int list[100]={41,67,34,0,69,24,78,58,62,64,5,45,81,27,61,91,95,42,27,36,91,4,2,53,92,82,21,16,18,95,47,26,71,38,69,12,67,99,35,94,3,11,22,33,73,64,41,11,53,68,47,44,62,57,37,59,23,41,29,78,16,35,90,42,88,6,40,42,64,48,46,5,90,29,70,50,6,1,93,48,29,23,84,54,56,40,66,76,31,8,44,39,26,23,37,38,18,82,29,41};
	for (i = 0; i < 100-1; i++){
		for (j = 100-1; j > i; j--){//BUBBLE SORTING
			if (list[j] < list[j-1])
			    swap(&list[j], &list[j-1]);
		}
	}
	printf("Nhap so can tim: ");
	scanf("%d",&target);
	int f;
	if ((f = recurBinsearch(list,target,0,99)) == -1) printf("Not Found!\n");
	else printf("\nindex = %d, data = %d",f,list[f]);
	return 0;
}
