#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int somay = 0;

typedef struct _Node {
    char name[5];
    int capacity;
    struct _Node *next;
} List;

List *H = NULL;

List *create(cpu X){
    List *newnode = (List*)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = X;
    newnode->next = NULL;
    
    return newnode;
}

List *insertToHead(List *head, cpu X){
    List *newnode = create(X);
    newnode->next = head;
    return newnode;
}

void func1(){
    char filename[128];
    printf("\nLOAD DATA FILES\n");
    printf("Enter filename > "); scanf("%[^\n]%*c",&filename);
    FILE *fin = fopen(filename,"r");
    if (fin == NULL){
        printf("File khong ton tai\n");
        return;
    }
    
    int n, i;
    cpu temp;
    fscanf(fin,"%d",&n);
    for (i = 0; i < n; i++){
        if (somay <= 20){
            fscanf(fin,"%s%d",&temp.name, &temp.capacity);
            H = insertToHead(H, temp);
            somay++;
        } else {
            printf("Danh sach da day, khong them duoc!\n");
            break;
        }
    }

    printf("So may vua them moi: %d",n);

    fclose(fin);
    fflush(stdin);
}

void func2(){
    printf("\nUPDATE CPU INFO\n");
    char idtarget[5];
    while (1){

    }
    fflush(stdin);
}

void func3(){
    fflush(stdin);
}

void func4(){
    fflush(stdin);
}

int main (){
    while (1){
        printf("\n====Program for management computers===\n");
        printf("1) Load Data Files\n");
        printf("2) Update CPU info\n");
        printf("3) Update Ram info\n");
        printf("4) Search\n");
        printf("5) Quit\n");
        char cmd[128];
        printf("Choose function > "); scanf("%[^\n]%*c",&cmd);
        if (strcmp(cmd, "1") == 0){
            func1();
        }
        else if (strcmp(cmd, "2") == 0){
            func2();
        }
        else if (strcmp(cmd, "3") == 0){
            func3();
        }
        else if (strcmp(cmd, "4") == 0){
            func4();
        }
        else if (strcmp(cmd, "5") == 0){
            printf("Chuong trinh dung lai thanh cong!\n");
            
            return 0;
        }
        else {
            printf("Moi nhap lai!\n");
        }
    }
}