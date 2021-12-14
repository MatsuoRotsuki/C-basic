#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTFOUND -1
#define MAX_ELEMENT 100
/*
• We assume that you make a mobile
phone’s address book.
• Declare the structure which can store at
least "name", "telephone number", "e-mail
address.". And declare an array of the
structure that can handle about 100
address data.
• Read this array data of about 10 from an
input file, and write a name which is equal
to a specified name and whose array index
is the smallest to an output file. Use the
binary search for this exercise
*/
typedef struct {
    char name[30];
    char tel[20];
    char email[100];
} List;

List data[MAX_ELEMENT];
int count = 0;

void input (FILE *fin){
    List temp;
    while (!feof(fin)){
        fscanf(fin,"%s\n%s\n%s\n",&temp.name,&temp.tel,&temp.email);
        data[count] = temp;
        count++;
    }
}

void inthongtin(int k){
    printf("\nName: %s\n", data[k].name);
    printf("Telephone number: %s\n", data[k].tel);
    printf("Email: %s\n\n", data[k].email);
}

int RecurBinSearch(List data[], char x[], int l, int r){
    if (l > r) return NOTFOUND;
    int m = (l+r)/2;
    // printf("m = %d\n",m);
    if ( strcmp(data[m].name, x) < 0) return RecurBinSearch(data, x, m+1, r);
    else if ( strcmp(data[m].name, x) > 0) return RecurBinSearch(data, x, l, m-1);
    else if (strcmp(data[m].name, x) == 0){
        // printf("Found!\n");
        return m;
    }
    return NOTFOUND;
}

void swap(List *a, List *b){
    List temp = *a;
    *a = *b;
    *b = temp;
}

void sort(){
    int i,j;
    for (i = 0; i < count; i++)
        for (j = count; j > i; j--)
            if( strcmp(data[j].name , data[j-1].name) < 0)
                swap(&data[j], &data[j-1]);
}

int main (){
	FILE *fptr;
    if ((fptr = fopen("Telephonebook.txt", "r")) == NULL) {
        printf("Cannot open file!\n");
        return 0;
    }
    input(fptr);
    sort();

    char target[30];
    printf("Nhap ten can tim: ");
    scanf("%s",&target);
    // char target[30] = "pham_tien_loc";

    int f;
    if ((f=RecurBinSearch(data, target, 1, count-1)) == NOTFOUND)
        printf("Not Found!\n");
    else inthongtin(f);
    return 0;

    // printf("%d", strcmp(data[2].name, target));
}
