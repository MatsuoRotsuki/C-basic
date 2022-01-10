/*
Exercise
• We assume that you make a mobile phone’s address book.
• At least, we want to write a program that can store about 
100 structure data with name and phone number and email address.
• Read about 10 data from an input file to this structure, and 
write the data that is sorted in ascending order into an 
output file.
• Use the insertion sort and selection sort
• (1) Write a program that uses array of structure 
• (2) Write a program that uses singly-linked list or doubly linked list.
• In both program, print out the number of comparisons 
made during the sorting process of each algorithm.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort-algorithm-address.h"

int countcomparison = 0;

Address data[100];
int count = 0;

void docFile(){
    FILE *fin = fopen("Telephonebook.txt","r");
    while(!feof(fin)){
        fscanf(fin,"%s\n%s\n%s\n", &data[count].name, &data[count].tel , &data[count].email);
        count++;
    }
    fclose(fin);
}

void inthongtin(int i){
    printf("Name: %s\nTelephone number: %s\nEmail: %s\n", data[i].name, data[i].tel, data[i].email);
}

int main (){
    docFile();
    insertionSort(data, count);
    int i;
    for (i = 0; i < count; i++) inthongtin(i);
    return 0;
}
//DONE
