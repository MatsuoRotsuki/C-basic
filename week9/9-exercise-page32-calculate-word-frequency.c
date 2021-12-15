// Exercise: Calculate word frequencies
// • Write to a program WordCount which reads a text file, then 
// analyzes the word frequencies. The result is stored in a file. 
// When user provide a word, program should return the 
// number of occurrences of this word in the file. 
// • For example, suppose the input files has the following 
// contents: A black black cat saw a very small mouse and a very 
// scared mouse.
// • The word frequencies in this file are as follows:
// AND 1
// CAT 1
// SAW 1
// SCARED 1
// SMALL 1
// BLACK 2
// MOUSE 2
// VERY 2
// A 3

// Hint
// • Use a binary search tree (it's even better with 
// AVL) to store data.
// • A node in this tree should contain at least two 
// fields:
// – word: string
// – count: int
// • Words are stored in nodes in the dictionary order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[10][50];

void input (FILE *fin){
    
}

int main (){
    FILE *fin, *fout;
    if ((fin = fopen("words.txt","r")) == NULL){
        printf("Cannot open read file\n");
        return 0;
    }
    else if ((fin = fopen("result.txt", "r")) == NULL){
        printf("Cannot open write file\n");
        return 0;
    }

    return 0;
}
