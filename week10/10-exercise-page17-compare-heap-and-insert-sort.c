// Exercise: Comparison of 
// running time
// • Write a program to initiate an array of 500 
// integers by using random function.
// • Sort this array using insertion sort and 
// heap sort. Calculate the running time of 
// program in each case and print out the 
// results.

#include "sort-algorithm-int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    srand((int)time(0));
    int List[500];
    for (int i = 0; i < 500; i++) List[i] = rand() % 1000;
    insertionSort(List, 500);
    for (int i = 0; i < 500; i++) printf("%d ",List[i]);
}

//INSERTION SORT spends 0.0888s
//HEAP SORT spends 0.08494s
