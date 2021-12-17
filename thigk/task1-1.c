#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTFOUND -1

typedef struct _Address {
	char name[20], tel[12], email[50];
} Address;

Address list[20];

void inthongtin(int i){
	printf("Name: %s\n", list[i].name);
	printf("Telephone number: %s\n", list[i].tel);
	printf("Email: %s\n", list[i].email);
}

void swap(Address *a, Address *b){
	Address temp = *a;
	*a = *b;
	*b = temp;
}

void Sort(Address A[], int N){
	int i, j;
	for (i = 0; i < N-1; i++){
		for(j = i+1; j < N; j++){
			if (strcmp(A[i].name , A[j].name) > 0){
				swap(&A[i], &A[j]);
			}
		}
	}
}

void docFile (){
	FILE *f = fopen("input.txt", "r");
	if (f == NULL){
		printf("Cannot open read file.\n");
		exit(0);
	}
	int i = 0;
	while (!feof(f)){
		fscanf(f,"%s\n%s\n%s\n",&list[i].name, &list[i].tel, &list[i].email);
		i++;
	}
	Sort(list, 10);
	fclose(f);
}

int BinarySearch(Address A[], char target[], int l, int r){
	if (l > r) return NOTFOUND;
	int m = (l + r) / 2;
	if (strcmp(A[m].name , target) < 0) return (A, target, m+1, r);
	else if (strcmp(A[m].name, target) > 0) return BinarySearch(A, target, l, m-1);
	else return m;
	return NOTFOUND;
}

void outfile(int i){
	FILE *f = fopen("Result 1-1.txt","w");
	fprintf(f,"Name: %s\n", list[i].name);
	fprintf(f,"Telephone number: %s\n", list[i].tel);
	fprintf(f,"Email: %s\n", list[i].email);
	fclose(f);
}

int main (){
	docFile();
	int i;
	char tar[20];
	printf("Which name do you want to search: ");
	scanf("%s", &tar);
	int f;
	if ((f = BinarySearch(list, tar, 0, 9)) == -1){
		printf("Not Found!\n");
	} else {
		printf("Result: \n");
		inthongtin(f);
		outfile(f);
	}
	return 0;
}

