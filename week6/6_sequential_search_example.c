#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char lastname[25];
	char telenum[11];
} Address;

typedef int T;

int LinearSearch (T M[], int N, T X) //N la size
{
	int k = 0;
	while (M[k] != X && k < N)
	    k++;
	if (k < N) return k;
	return -1;
}

int LinearSentinelSearch(T M[], int N, T X)
{
	int k = 0; M[N] = X;
	while (M[k] != X)
	    k++;
	return k-1;
}

int binSearch(int List[], int Target, int size)
{
	int m, l = 0, r = size -1;
	while (l <= r)
	{
		m = (l+r)/2;
		if (List[m] == Target)
		    return m;
		else if (Target < List[m])
		    r = m - 1;
		else 
		    l = m + 1;
	}
	return -1;
}

int main ()
{
	T arr[11];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int target;
	scanf("%d",&target);
	printf("\n%d",LinearSearch(arr, 10, target)+1);
}




