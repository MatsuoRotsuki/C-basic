#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[11];
    int score;
} Doibong;

typedef struct _Tree{
    Doibong data;
    struct _Tree *left;
    struct _Tree *right;
} Tree;

void freetree(Tree *root){
    if (root == NULL) return;
    freetree(root->left);
    freetree(root->right);

    free(root);
}

Tree *create (char x[]){
    Tree *newnode = (Tree*)malloc(sizeof(Tree));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }
    strcpy(newnode->data.name, x);
    newnode->data.score = 0;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


void inorderprint(Tree *root){
	if (root == NULL) return;
	else {
		inorderprint(root->left);
		printf("%s:%d, ",root->data.name, root->data.score);
		inorderprint(root->right);
	}
}

Tree *treeinsert(Tree *root, char X[], int scoreupdate) {
    if(root == NULL){
        root = create(X);
        root->data.score = scoreupdate;
        return root;
    }
    if(strcmp(root->data.name, X) < 0) {
        root->right = treeinsert(root->right,X,scoreupdate);
    } 
    else if (strcmp(root->data.name, X) > 0){
        root->left = treeinsert(root->left, X,scoreupdate);
    }
    else if (strcmp(root->data.name, X) == 0)
        root->data.score += scoreupdate;
    return root;
}

Tree *treesearch(Tree *root ,char X[]){
    if (root == NULL|| strcmp(root->data.name, X) == 0)
        return root; 
    if (strcmp(root->data.name, X) < 0)
        return treesearch(root->right,X);
    else return treesearch(root->left,X);
}

Tree *minValueNode(Tree *root){
    Tree *current = root;

    while(current && current->left != NULL)
        current = current->left;

    return current;
}

Tree *deleteNode(Tree *root, char key[]){
    if (root == NULL)
        return root;

    if (strcmp(key, root->data.name) < 0)
        root->left = deleteNode(root->left, key);
    
    else if (strcmp(key, root->data.name) > 0)
        root->right = deleteNode(root->right, key);
    
    else {
        if (root->left == NULL){
            Tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Tree *temp = root->left;
            free(root);
            return temp;
        }
        Tree *temp = minValueNode(root->right);
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.name);
    }
    return root;
}

Tree *R = NULL;

void func1(){
    printf("\nTAO CAY\n");
    FILE *fin = fopen("BongDa.txt","r");
    char db1[11];
    char db2[11];
    int temp1, temp2;
    int scoredecise;
    while (!feof(fin)){
        fscanf(fin, "%s %s %d %d",&db1,&db2,&temp1,&temp2);
        
        //printf("DB1:%s DB2:%s temp1:%d temp2:%d\n",db1,db2,temp1,temp2);

        if (temp1 > temp2) scoredecise = 1;
        else if (temp1 < temp2) scoredecise = 2;
        else if (temp1 == temp2) scoredecise = 0;
        
        //printf("\nSCORE = %d",scoredecise);

        if (scoredecise == 0){
            R = treeinsert(R,db1,1);
            R = treeinsert(R,db2,1);
        }
        else if (scoredecise == 1){
            R = treeinsert(R,db1,3);
            R = treeinsert(R,db2,0);
        }
        else if (scoredecise == 2){
            R = treeinsert(R,db2,3);
            R = treeinsert(R,db1,0);
        }
    
    }
    //inorderprint(R);
    fclose(fin);
    fflush(stdin);
}

void func2(){
    printf("\nKET QUA\n");
    inorderprint(R);
    fflush(stdin);
}

void func3(){
    printf("\nTIM KIEM\n");
    char nametarget[11];
    printf("Nhap vao doi muon tim kiem: ");scanf("%[^\n]%*c",&nametarget);
    Tree *f = treesearch(R,nametarget);
    printf("Diem cua doi %s la %d diem.\n",f->data.name, f->data.score);
    fflush(stdin);
}

Tree* findMin(Tree* r)
{
    if (r==NULL) return NULL;
    Tree* lmin=findMin(r->left);
    if (lmin!=NULL) return lmin;
    return r;
}

Tree *removeNode(Tree *r, char *name){
    if (r == NULL) return NULL;
    int c = strcmp(r->data.name, name);
    if (c > 0) r->left=removeNode(r->left,name);
    else if (c < 0) r->right = removeNode(r->right,name);
    else {
        if (r->right!=NULL && r->left!=NULL)
        {
            Tree *tmp = findMin(r->left);
            strcpy(r->data.name, tmp->data.name);
            r->data.score = tmp->data.score;
            r->right=removeNode(r->right, tmp->data.name);
        } else {
            Tree *tmp = r;
            if (r->left == NULL) r = r->right;
            else r = r->left;
            free(tmp);
        }
    }
    return r;
}

void child_Func4(int x, Tree *node){
    if (node == NULL) return;
    child_Func4(x,node->left);
    if (node->data.score < x)
    {
        printf("%-20s%-10d\n",node->data.name, node->data.score);
        removeNode(R,node->data.name);
    }
    child_Func4(x,node->right);
}

void func4(){
    printf("\nXUONG HANG\n");
    int X;
    printf("Nhap vao mot so nguyen: ");
    scanf("%d",&X);
    printf("Doi bong bi xuong hanh la:\n");
    child_Func4(X, R);
    
    printf("Cay moi la:\n");
    inorderprint(R);
    fflush(stdin);
}

void inorderfileout(Tree *root, FILE *fout){
	if (root == NULL) return;
	else {
		inorderfileout(root->left, fout);
		fprintf(fout,"%s\t%d\n",root->data.name, root->data.score);
		inorderfileout(root->right, fout);
	}
}

void func5(){
    printf("\nXUAT FILE\n");
    FILE *fout = fopen("Ketqua.txt","w");
    inorderfileout(R,fout);
    fclose(fout);
    fflush(stdin);
}

int main (){
    while(1){
        printf("\n==================\n");
        printf("1. Tao cay\n");
        printf("2. Ket qua\n");
        printf("3. Tim kiem\n");
        printf("4. Xuong hang\n");
        printf("5. Xuat file\n");
        printf("==================\n");
        char cmd[128];
        printf("Chon chuc nang > "); scanf("%[^\n]%*c",&cmd);
        if (strcmp(cmd, "1") == 0)
            func1();
        else if (strcmp(cmd, "2") == 0)
            func2();
        else if (strcmp(cmd, "3") == 0)
            func3();
        else if (strcmp(cmd, "4") == 0)
            func4(); //CHUA XONG
        else if (strcmp(cmd, "5") == 0){
            func5();
            printf("\nChuong trinh dung lai thanh cong!\n");
            freetree(R);
            return 0;
        }
        else {
            printf("\nMoi nhap lai!\n");
        }
    }
}
