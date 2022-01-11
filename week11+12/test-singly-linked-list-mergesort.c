#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list-sort-algorithm-int.h"
#include <time.h>
int main (){
    /*Start with the empty list */
    List *res = NULL;
    List *a = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 4);
    // int i;
    // srand((unsigned)time(0));
    // for (i = 0; i < 50; i++) push(&a, rand()%1000);

	printf("Unsorted Linked List: ");
	traverse(a);
	mergeSort(&a);
    printf("\nSorted Linked List is: \n");
    traverse(a);
    freelist(a);
    return 0;
}
