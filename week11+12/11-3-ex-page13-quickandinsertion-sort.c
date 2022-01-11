/*
When a program sorts a little number of the data,
a program using insertion sort is faster than a
program using quick sort and so on. So, a
program sorts efficiently, if a program changes
sorting algorithms by the number of data.
• You write a function that selects sorting
algorithms – If number of the data is more than x
numbers, the function selects quick sort. If not
so, it selects insertion sort.
• Note: get the number “x” as the program
argument.
• Read the text file that has more than 100
characters, sort the first 100 characters, and
show the result by standard output. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort-algorithm-int.h"
#define MAX_LENGTH 10000

typedef char ElementType;

char List[MAX_LENGTH];
int size;

void choose(int n, int x){
    if (n > x) quickSort(List, 0 ,size-1);
    else insertionSort(List, size);
}

void docfile(){
    FILE *fin = fopen("page13.txt","r");
    int i = 0;
    while(!feof(fin)){
        fscanf(fin,"c",&List[i]);
        i++;
    }
    size = i;
    fclose(fin);
}

int main (int argc, char *argv[]){
    int x = atoi(argv[1]);
    choose(size, x);
    return 0;
}