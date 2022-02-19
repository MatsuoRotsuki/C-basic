#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[31];
    int score;
    int win;
    int lose;
} Doibong;

typedef struct _Node {
    Doibong data;
    struct _Node *next;
} List;

List *create(Doibong X){
    List *newnode = (List*)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = X;
    newnode->data.score = 0;
    newnode->data.lose = 0;
    newnode->data.win = 0;
    newnode->next = NULL;
    return newnode;
}

void freelist(List *head){
    if (head == NULL) return;
    else {
        freelist(head->next);
        free(head);
    }
}

List *insertToHead(List *head, Doibong X){
    List *newnode = create(X);
    newnode->next = head;
    return newnode;
}

List *H = NULL;

void inds(){
    printf("%-10s%-15s%-10s%-10s%-10s\n","Id","Tendoibong","Diem","Sobanthang","Sobanthua");
    List *tg;
    for (tg = H; tg != NULL; tg = tg->next){
        printf("%-10d%-15s%-10d%-10d%-10d\n",tg->data.id,tg->data.name,tg->data.score,tg->data.win,tg->data.lose);
    }
}

void func1(){
    printf("\nIN THONG TIN CAC DOI BONG\n");
    
    FILE *fin = fopen("bongda.txt","r");
    int N;
    int i;
    fscanf(fin,"%d",&N);
    Doibong temp;
    for (i = 0; i < N; i++)
    {
        fscanf(fin,"%d %s",&temp.id, &temp.name);
        H = insertToHead(H, temp);
    }
    
    
    inds();

    fclose(fin);
    fflush(stdin);
}

void func2(){
    printf("\nIN THONG TIN LICH THI DAU\n");


    fflush(stdin);
}

void func3(){
    fflush(stdin);
}

void func4(){
    fflush(stdin);
}

int main (){
    while(1){
        printf("\n================\n");
        printf("1. In thong tin cac doi bong\n");
        printf("2. In thong tin lich thi dau\n");
        printf("3. Cap nhat ket qua thi dau\n");
        printf("4. Thong ke\n");
        printf("5. Thoat\n");
        printf("================\n");
        char cmd[128];
        printf("Chon chuc nang > "); scanf("%[^\n]%*c", &cmd);
        if (strcmp(cmd,"1") == 0)
            func1();
        else if (strcmp(cmd,"2") == 0)
            func2();
        else if (strcmp(cmd,"3") == 0)
            func3();
        else if (strcmp(cmd,"4") == 0)
            func4();
        else if (strcmp(cmd,"5") == 0){
            printf("\nChuong trinh dung lai thanh cong!\n");
            freelist(H);
            return 0;
        }
        else {
            printf("Xin moi nhap lai!\n");
        }
    }
}