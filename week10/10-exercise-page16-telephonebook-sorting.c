// Exercise
// • We assume that you make a mobile 
// phone’s address book.
// • At least, we want to write a program that 
// can store the declared about 100 structure 
// data with name and phone number and email address.
// • Read the about 10 data from an input file 
// to this structure, and write the data that is 
// sorted in ascending order into an output 
// file.
// • Use the heap sort. Print out the number of 
// comparisons.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort-algorithm-address.h"

enum{
    NAME_LENGTH = 30,
    TEL_LENGTH = 15,
    EMAIL_LENGTH = 50,
};

// typedef struct {
//     char name[NAME_LENGTH];
//     char tel[TEL_LENGTH];
//     char email[EMAIL_LENGTH];
// } Address;

Address Data[11];
int n;

void docfile(){
    FILE *fin = fopen("input.dat","rb");
    int irc = fread(Data, sizeof(Address), 10, fin);
    n = irc;
    //printf("%d\n",irc);
    // for (int i = 1; i <= irc; i++){
    //     inthongtin(Data[i]);
    // }
    fclose(fin);
}

int main (){
    docfile();
    heapSort(Data, n);
    printf("\n-----------------------------\n");
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
        inthongtin(Data[i]);
}