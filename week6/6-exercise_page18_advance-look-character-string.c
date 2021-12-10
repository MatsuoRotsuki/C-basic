#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE *fptr;
    char filename[] = "words.txt";
    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n",filename);
        return 0;
    }
    else {
        
    }
}