#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly-linked-list-sort-algorithm-address.h"

List *head = NULL;
int sizeoflist = 0;

void docfile(){
    FILE *fin = fopen("input.dat","rb");
    Address temp;
    int irc;
    
    while(!feof(fin)){
       irc = fread(&temp, sizeof(Address), 1, fin);
       push(&head, temp);
       sizeoflist += irc;
    }

    fclose(fin);
}

int main (){
    docfile();
    printf("Size = %d\n",sizeoflist);
    printf("Unsorted List: \n\n");
    traverse(head);
    printf("\nSorted List: \n\n");
    mergeSort(&head);
    traverse(head);
    freelist(head);
}
