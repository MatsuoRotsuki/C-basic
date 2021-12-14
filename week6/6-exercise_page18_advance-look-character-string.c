#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
#define MAX_ELEMENT 1000000

typedef struct {
    char word[MAX_LENGTH];
} wordType;

wordType data[MAX_ELEMENT];
int count = 0;

void input(FILE *fin){
    while (!feof(fin)){
        fscanf(fin, "%s", &data[count++].word);
    }
    printf("\nNumber of words input: %d\n",count);
}

int main (){
    FILE *fptr;
    char filename[] = "words.txt";
    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n",filename);
        return 0;
    }
    else {
        input(fptr);
        // char target[20] = "computer";
        char target[20];
        printf("Look for all the words that begin with: ");
        scanf("%s",&target);
        int i, j,n = strlen(target);
        char *ptr;
        for (i = 0; i < count; i++){
            for (j = 0; j < n; j++){
                if (data[i].word[j] != target[j]) break;
            }
            if (j == n) printf("\n%s",data[i].word);
        }
    }
}