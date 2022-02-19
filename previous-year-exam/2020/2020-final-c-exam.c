#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char Pos[41];
    int h;
    int min;
} ElementType;

typedef struct _Node {
    ElementType data;
    struct _Node *next;
} List;

List *create(ElementType data){
    List *newnode = (List*)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void freelist(List *head){
	if (head == NULL) return;
	else{
		freelist(head->next);
		free(head);
	}
}

List *insertToLast(List *head, ElementType X){
    List *newnode = create(X);
    List *temp;
    if (head == NULL)
        head = newnode;
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return head;
}

List *H = NULL;

void duyetds(List *head){
	List *tg = head;
    printf("%50s%10s%10s\n","Dia diem","Gio","Phut");
	while (tg!= NULL){
		printf("%50s%10d%10d\n",tg->data.Pos, tg->data.h, tg->data.min);
		tg = tg->next;
	}
}

void func1(){
    printf("\nNAP FILE LOG LICH SU DI CHUYEN\n");
    FILE *fin = fopen("log.txt","r");
    ElementType temp;
    while (!feof(fin)){
    	fscanf(fin,"%s%d%d",&temp.Pos, &temp.h, &temp.min);
    	H=insertToLast(H, temp);
	}
	//printf("\n\nDuyetds\n");
    //duyetds(H);
}

void func2()
{
    printf("\nIN RA LICH SU DI CHUYEN\n");
    duyetds(H);
}

void func3(){
    printf("\nTIM KIEM LICH SU THEO DIA DIEM\n");
    char target[41];
    printf("Nhap vao mot dia diem > "); scanf("%[^\n]%*c", &target);
    List *tg = NULL;
    int error = 1;
    printf("Ket qua thu duoc:\n");
    for (tg = H; tg != NULL; tg = tg->next){
        if (strcmp(tg->data.Pos,target) == 0){
            printf("%d:%d, ",tg->data.h, tg->data.min);
            error = 0;
        }
    }
    if (error == 1) printf("Ban chua toi dia diem do");
    printf("\n");
}

void func4(){
    printf("\nTIM KIEM LICH SU THEO THOI GIAN\n");
    int htarget, mtarget;
    do {
        printf("Nhap vao gio va phut > "); scanf("%d %d",&htarget, &mtarget);
        if (htarget < 0 || htarget >= 24 || mtarget < 0 || mtarget >= 60)
            printf("\nDu lieu nhap vao khong hop le\n");
    } while (htarget < 0 || htarget >= 24 || mtarget < 0 || mtarget >= 60);
    //printf("%d:%d\n",htarget, mtarget);
    List* tg = NULL;
    int error = 1;
    printf("Ket qua thu duoc:\n");
    for (tg = H; tg != NULL; tg = tg->next){
        if (htarget - tg->data.h <= 1 && htarget - tg->data.h > 0)
        {
            printf("%s ",tg->data.Pos);
            error = 0;
        }
    }
    if (error == 1) printf("Khong thay lich su di chuyen");
    printf("\n");
    fflush(stdin);
}

void func5(){
	int danger = 0;
    printf("\nKIEM TRA TRUY VET MOI NHAT\n");
    printf("Nhap vao dia diem, gio phut > ");
    ElementType target;
    scanf("%s %d %d", &target.Pos, &target.h, &target.min);
    List *tg = NULL;
    for (tg = H; tg!= NULL; tg= tg->next){
        if(strcmp(tg->data.Pos , target.Pos) == 0){
        	printf("%s\n",tg->data.Pos);
            if(target.h - tg->data.h <= 1 && target.h - tg->data.h > 0 && tg->data.min <= target.min)
                danger = 1;
        }
    }
    if (danger == 1)
        printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
    else 
        printf("Lich su di chuyen cua ban OK\n");
    fflush(stdin);
}

int main (){
    while(1){
        printf("\n===================\nCHUONG TRINH TRUY VET COVID19\n1. Nap file log lich su di chuyen\n2. In ra lich su di chuyen\n3. Tim kiem lich su theo dia diem\n4. Kiem tra truy vet theo thoi gian\n5. Kiem tra truy vet moi nhat\n6. Thoat\n===================\n");
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
        else if (strcmp(cmd,"5") == 0)
        	func5();
		else if(strcmp(cmd,"6") == 0){
            printf("\nChuong trinh dung lai thanh cong!");
            freelist(H);
            return 0;
        }
        else {
        	printf("Xin moi nhap lai!");
		}
    }
}
