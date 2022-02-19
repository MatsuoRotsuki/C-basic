#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char name[10];
    int score;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* root;

Node* makeNode(char name[10],int score)
{
    Node* p=(Node*)malloc(sizeof(Node));
    if (p!=NULL)
    {
        strcpy(p->name,name);
        p->score=score;
        p->leftChild=NULL;
        p->rightChild=NULL;
    }
    return p;
}

Node* insertNode(Node* r,char name[10],int score)
{
    if (r==NULL) return makeNode(name,score);
    int c=strcmp(r->name,name);
    if (c==0)
    {
        printf("Ten %s da ton tai\n",name);
        return r;
    }
    else if (c>0)
    {
        r->leftChild=insertNode(r->leftChild,name,score);
        return r;
    }
    else
    {
        r->rightChild=insertNode(r->rightChild,name,score);
        return r;
    }
}

Node* findNode(Node* r,char* name)
{
    if (r==NULL) return NULL;
    int c=strcmp(r->name,name);
    if (c==0) return r;
    if (c<0) return findNode(r->rightChild,name);
    else return findNode(r->leftChild,name);
}

Node* findMin(Node* r)
{
    if (r==NULL) return NULL;
    Node* lmin=findMin(r->leftChild);
    if (lmin!=NULL) return lmin;
    return r;
}

Node* removeNode(Node* r,char* name)
{
    if (r==NULL) return NULL;
    int c=strcmp(r->name,name);
    if (c>0) r->leftChild=removeNode(r->leftChild,name);
    else if (c<0) r->rightChild=removeNode(r->rightChild,name);
    else
    {
        if (r->rightChild!=NULL&&r->leftChild!=NULL)
        {
            Node* tmp=findMin(r->leftChild);
            strcpy(r->name,tmp->name);
            r->score=tmp->score;
            r->rightChild=removeNode(r->rightChild,tmp->name);
        }
        else
        {
            Node* tmp=r;
            if (r->leftChild==NULL) r=r->rightChild;
            else r=r->leftChild;
            free(tmp);
        }
    }
    return r;
}



void Func1()
{
    FILE* f=fopen("BongDa.txt","r");
    if (f==NULL)
    {
        printf("Khong tim thay file\n");
        return;
    }
    Node* f1=NULL,*f2=NULL;
    char name1[10],name2[10];
    int score1,score2;
    int i=0;
    while (fscanf(f,"%s%s%d%d",name1,name2,&score1,&score2)!=EOF)
    {
        f1=findNode(root,name1);
        f2=findNode(root,name2);
        if (f1==NULL)
        {
            int diem1=0;
            root=insertNode(root,name1,diem1);
            f1=findNode(root,name1);
            i++;
            printf("Node moi thu %d - ma %s - dia chi %p\n",i,name1,&f1);
        }
        if (f2==NULL)
        {
            int diem2=0;
            root=insertNode(root,name2,diem2);
            f2=findNode(root,name2);
            i++;
            printf("Node moi thu %d - ma %s - dia chi %p\n",i,name2,&f2);
        }
        if (score1>score2)
        {
            f1->score+=3;
        }
        else if (score1<score2)
        {
            f2->score+=3;
        }
        else
        {
            f1->score++;
            f2->score++;
        }
    }
    printf("Doc file thanh cong!\n");
    fclose(f);

}

void printTree(Node* r)
{   
    if (r==NULL) return;
    printTree(r->leftChild);
    printf("%-20s%-10d\n",r->name,r->score);
    printTree(r->rightChild);
}

void Func3()
{
     char name[10];
     printf("Nhap ma doi bong: ");
     scanf("%s",name);
     Node* p=findNode(root,name);
     if (p!=NULL)
     {
         printf("Diem cua doi %s la %d diem\n",p->name,p->score);
     }
     else
     {
         printf("Khong co doi bong nay\n");
     }
}

void child_Func4(int x,Node* r)
{
    if (r==NULL) return ;
    child_Func4(x,r->leftChild);
    if (r->score<x)
    {
        printf("%-20s%-10d\n",r->name,r->score);
        removeNode(root,r->name);
    }
    child_Func4(x,r->rightChild);
}

void Func4()
{
    int x;
    printf("Nhap X: ");
    scanf("%d",&x);
    printf("Doi bong bi xuong hang la:\n");
    child_Func4(x,root);
    printf("Cay moi la:\n");
    printTree(root);
}

void storeFile(Node* r,FILE* f)
{
    if (r==NULL) return;
    storeFile(r->leftChild,f);
    fprintf(f,"%-20s%-10d\n",r->name,r->score);
    storeFile(r->rightChild,f);
}

void Func5()
{
    char filename[100];
    printf("Nhap ten file muon luu tru: ");
    scanf("%s",filename);
    FILE* f=fopen(filename,"w");
    storeFile(root,f);
    fclose(f);
}

int main()
{
    int choose;
    do
    {
        printf("=============MENU==============\n");
        printf("1. Tao cay\n");
        printf("2. Ket qua\n");
        printf("3. Tim kiem\n");
        printf("4. Xuong hang\n");
        printf("5. Xuat file\n");
        printf("6. Thoat\n");
        printf("Ban chon chuc nang: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            Func1();
            break;
        case 2:
            printTree(root);
            break;
        case 3:
            Func3();
            break;
        case 4:
            Func4();
            break;
        case 5:
            Func5();
            break;
        case 6:
            printf("============THANKS==============\n");
            break;
        default:
            printf("!Vui long chon 1 trong cac chuc nang!\n");
            break;
        }
    } while (choose!=6);
    
}