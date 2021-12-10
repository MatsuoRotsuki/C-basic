#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTFOUND -1
#define NAMELENGTH 50
#define EMAILLENGTH 50
#define TELLENGTH 50

typedef struct {
	char name[NAMELENGTH];
	char tel[EMAILLENGTH];
	char email[TELLENGTH];
} Address;

Address readFile(FILE *fin){
	Address temp;
	fscanf(fin, "%s\n%s\n%s\n", &temp.name, &temp.tel, &temp.email);

	return temp;
}

Address A[100];

void swap(Address *a, Address *b)
{
    Address temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(Address A[], int N){
    int i, j;
    for (i = 0; i < N-1; i++){
        for (j = i+1; j < N; j++){
            if (strcmp(A[i].name , A[j].name) > 0){
                swap(&A[i], &A[j]);
            }
        }
    }
}

int BinarySearch(Address A[],char target[], int l, int r){
    if (l > r) return NOTFOUND;
    int m = (l + r) /2;
    if ( strcmp(A[m].name, target ) < 0 ) return BinarySearch(A, target,m+1,r);
    else if ( strcmp(A[m].name, target ) > 0 ) return BinarySearch(A, target, l, m-1);
    else return m;
    return NOTFOUND;
}

int main (){
    FILE *fptr;
    int size;
    char filename[] = "Telephonebook.txt";
    if ((fptr = fopen(filename,"r")) == NULL){
        printf("Cannot open %s!\n",filename);
        return 0;
    } else {
        int i = 0;
        while(!feof(fptr)){
            A[i] = readFile(fptr);
            i++;
        }
        size = i++;
        Sort(A,size);

        char target[NAMELENGTH];
        printf("Which name do you want to search: ");
        scanf("%s", &target);//Specified name

        if (BinarySearch(A,target,0,size-1) == -1){
            printf("Not Found!\n");
        } else {
            printf("Result:\n");
            printf("Name: %s\n",A[BinarySearch(A,target,0,size-1)].name);
            printf("Telephone number: %s\n",A[BinarySearch(A,target,0,size-1)].tel);
            printf("Email: %s\n",A[BinarySearch(A,target,0,size-1)].email);
        }
    }
    return 0;
}

