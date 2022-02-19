#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char username[100];
    char password[100];
    double diem;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* root;

Node* makeNode(char* username,char* password,double diem)
{
    Node*p=(Node*)malloc(sizeof(Node));
    if (p!=NULL)
    {
        strcpy(p->username,username);
        strcpy(p->password,password);
        p->diem=diem;
        p->leftChild=NULL;
        p->rightChild=NULL;
    }
    return p;
}

Node *insertNode(Node* r,char* username,char* password,double diem)
{
    if (r==NULL) return makeNode(username,password,diem);
    int c=strcmp(r->username,username);
    if (c>0)
    {
        r->leftChild=insertNode(r->leftChild,username,password,diem);
        return r;
    }
    else if (c<0)
    {
        r->rightChild=insertNode(r->rightChild,username,password,diem);
        return r;
    }
    else
    {
        printf("Name %s exists\n",username);
        return r;
    }
}

void load()
{
    FILE* f=fopen("2014.txt","r");
    while(!feof(f))
    {
        char username[100];
        char password[100];
        double diem;
        fscanf(f,"%s%s%lf",username,password,&diem);
        root=insertNode(root,username,password,diem);
    }
}

void inOrder(Node* r)
{
    if (r==NULL) return;
    inOrder(r->leftChild);
    printf("%-20s %-20s %-10.1lf\n",r->username,r->password,r->diem);
    inOrder(r->rightChild);
}

Node* findNode(Node* r,char* username)
{
    if (r==NULL) return NULL;
    int c= strcmp(r->username,username);
    if (c==0)
    {
        return r;
    }
    else if (c>0) return findNode(r->leftChild,username);
    else 
    {
        return findNode(r->rightChild,username);
    }
}   

void changePassword(Node* p)
{
    char oldpass[100],newpass[100],confirmpass[100];
    int tmp=0;
    int count=0,count1=0;
    do
    {
        
        printf("Nhap mat khau cu: ");
        scanf("%s",oldpass);
        int c=strcmp(p->password,oldpass);
        if (c!=0)
        {
            printf("Mat khau sai vui long nhap lai\n");
        }
        else
        {
            tmp=1;
            break;
        }
    } while (tmp!=1);
    do
    {
        printf("Nhap mat khau moi: ");
        scanf("%s",newpass);
        printf("Xac nhan lai: ");
        scanf("%s",confirmpass);
        int c= strcmp(newpass,confirmpass);
        if (c!=0)
        {
            printf("Mat khau khong khop, nhap lai\n");
        }
        else
        {
            count=1;
            strcpy(p->password,newpass);

            break;
        }
    } while(count!=1);
    
}

void StoreFile(Node* r,FILE* f)
{
    if (r==NULL) return;
    StoreFile(r->leftChild,f);
    fprintf(f,"%-20s %-20s %-10.1lf\n",r->username,r->password,r->diem);
    StoreFile(r->rightChild,f);
}

void processStore()
{
    char filename[100];
    printf("Enter filename: ");
    scanf("%s",filename);
    FILE* f=fopen(filename,"w");
    StoreFile(root,f);
    fclose(f);
}


void menu1(Node* p)
{
    int choose;
    
    do
    {
        printf("========MENU1========\n");
        printf("1. Xem diem hoc sinh\n");
        printf("2. Doi mat khau\n");
        printf("3. Ghi vao file va thoat\n");
        printf("Ban chon chuc nang: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            printf("Diem so cua hoc sinh la: %lf\n",p->diem);
            break;
        case 2:
            changePassword(p);
            break;
        case 3:
            
            processStore();
           
            printf("Ban da thoat khoi menu1\n");
            break;
        default:
            break;
        }
    } while (choose!=3);
    
}

void themsinhvien()
{
    char username[100];
    char password[100];
    double diem;
    int count;
    do
    {
        count=0;
        printf("Nhap username: ");
        fflush(stdin);
        gets(username);
        for (int i=0;i<strlen(username);i++)
        {
            if (username[i]==' ')
            {
                count++;
                break;
            }
        }
    } while (count!=0);
    printf("Nhap password: ");
    scanf("%s",password);
    do
    {
        printf("Nhap diem: ");
        scanf("%lf",&diem);
    } while (diem<0||diem>10);
    root=insertNode(root,username,password,diem);
}

void indanhsach_m2(Node* r)
{
    if (r==NULL) return;
    indanhsach_m2(r->leftChild);
    if (strcmp(r->username,root->username)!=0)
    {
        printf("%-20s%-20s%-10.1lf\n",r->username,r->password,r->diem);
    }
    indanhsach_m2(r->rightChild);
}

Node* findMin(Node* r)
{
    if (r==NULL) return NULL;
    Node* lmin=findMin(r->leftChild);
    if (lmin!=NULL) return lmin;
    return r;
}

Node* removeNode(Node* r,char* username)
{
    if (r==NULL) return NULL;
    int c=strcmp(r->username,username);
    if (c>0) r->leftChild=removeNode(r->leftChild,username);
    else if (c<0) r->rightChild=removeNode(r->rightChild,username);
    else
    {
        if (r->leftChild!=NULL&&r->rightChild!=NULL)
        {
            Node* tmp=findMin(r->rightChild);
            strcpy(r->username,tmp->username);
            strcpy(r->password,tmp->password);
            r->diem=tmp->diem;
            r->rightChild=removeNode(r->rightChild,tmp->username);
        }
        else
        {
            Node* tmp=r;
            if (r->leftChild==NULL) r=r->rightChild;
            else r=r->rightChild;
            free(tmp);
        }
    }
    return r;
}

void processRemove()
{
    char username[100];
    
    int count;
    do
    {
        printf("Nhap username ban muon xoa: ");
        scanf("%s",username);
        count =0;
        Node* tmp=findNode(root,username);
        if (tmp!=NULL)
        {
            if (strcmp(root->username,username)==0)
            {
                printf("Khong the xoa ten nay\n");
            }
            else
            {
                printf("%-20s%-20s%-10.1lf\n",tmp->username,tmp->password,tmp->diem);
                root=removeNode(root,username);
                count=1;
            }
        }
        else
        {
            printf("Sinh vien %s khong co trong danh sach\n",username);
        }
    } while (count!=1);
    
   
}

void menu2()
{
    int choose;
    do
    {
        printf("============Menu2===========\n");
        printf("1. Them sinh vien\n");
        printf("2. In sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Luu thong tin va thoat\n");
        printf("Ban chon chuc nang: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            themsinhvien();
            break;
        case 2:
            //inOrder(root);
            indanhsach_m2(root);
            break;
        case 3:
            processRemove();
            break;
        case 4:
            processStore();
            printf("Ban da thoat menu2\n");
            break;
        default:
            break;
        }
    } while (choose!=4);
    
}

void func1()
{
    char username[100];
    char password[100];
    int count=0;
    do
    {
        printf("Enter username: ");
        scanf("%s",username);
        printf("Nhap password: ");
        scanf("%s",password);
        Node* p=findNode(root,username);
        if (p!=NULL)
        {
            if (strcmp(p->password,password)==0)
            {
                if (strcmp(p->username,root->username)==0)
                {
                    printf("Thuc hien menu2\n");
                    menu2();
                    break;
                }
                else 
                {
                    printf("Thuc hien menu1\n");
                    menu1(p);
                    break;
                }
            }
            else count++; 
        }
        else count++;
    } while (count!=3);
    
}


int main()
{
    load();
    int choose;
    do
    {
        printf("==========MENU=========\n");
        printf("1. Dang nhap\n");
        printf("2. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            func1();
            //inOrder(root);
            break;
        
        default:
            break;
        }
    } while (choose!=2);
    
}