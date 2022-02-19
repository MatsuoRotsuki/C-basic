#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    int id;
    char toy[30];
} ElementType;

typedef struct TreeNode {
    int id;
    char toy[30];
    struct TreeNode *left;
    struct TreeNode *right;
} Tree;

Tree *RA = NULL;

void freetree(Tree *root){
    if (root == NULL) return;
    freetree(root->left);
    freetree(root->right);

    free(root);
}

Tree *create (int id, char toy[]){
    Tree *newnode = (Tree*)malloc(sizeof(Tree));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }
    newnode->id = id;
    strcpy(newnode->toy,toy);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Tree *treesearch(Tree *root , int x){
    if (root == NULL|| root->id == x)
        return root; 
    if (root->id < x)
        return treesearch(root->right,x);
    else return treesearch(root->left,x);
}

Tree *treeinsert(Tree *root, int key, char toy[]) { //Recursive Algorithm
    if(root == NULL){
        root = create(key, toy);
        return root;
    }
    if(root->id < key) {
        root->right = treeinsert(root->right,key, toy);
    } else {
        root->left = treeinsert(root->left, key, toy);
    }
    return root;
}

void inorderprint(Tree *root){
	if (root == NULL) return;
	else {
		inorderprint(root->left);
		printf("%d\t%s\n",root->id, root->toy);
		inorderprint(root->right);
	}
}
////////////////////////////////////////

int checkf1 = 0;

void func1(){
    printf("\nDOC FILE A\n");
    checkf1 = 1;
    FILE *fin = fopen("A.txt","r");

    char cmd[128];
    while (!feof(fin)){
        fscanf(fin,"%[^\n]%*c",&cmd);

        //printf("\n\ncmd: %s\n",cmd);
        char strid[20] = "";
        char toy[20] = "";
        int lastid, lasttoy = strlen(cmd);
        int i;
        for (i = 0; i < strlen(cmd); i++)
        {
			if (isdigit(cmd[i])){
				//printf("i = %d\n",i);
				lastid = i;
			}
        	if ((cmd[i] > 'a' && cmd[i] <'z') || (cmd[i] > 'A' && cmd[i] < 'Z'))
        	{
        		//printf("k = %d\n",i);
        		if (lasttoy > i)
        			lasttoy = i;
			}
    	}

    	strcpy(strid, cmd);
    	strid[lastid+1] = '\0';
    	int id = atoi(strid); //Id value is correctly assigned
    	
    	strcpy(toy, &cmd[lasttoy]); //Toy value is correctly assigned
        if (strlen(toy) == 0){
            printf("Nhap them thong tin cho id %d: ",id);
            scanf("%[^\n]%*c",&toy);
        }
    	
    	RA = treeinsert(RA, id, toy);
    }
    
    printf("Danh sach cay A:\n");
    inorderprint(RA);
    printf("\nDoc file thanh cong\n");
    fclose(fin);
    fflush(stdin);
}
//////////////////////////////

int checkf2 = 0;
ElementType arr[20];
int arrsize;

void func2(){
    printf("\nDOC FILE B\n");
    checkf2 = 1;
    FILE *fin = fopen("B.txt","r");
    char cmd[128];
    int count = 0;
    while (!feof(fin)){
        fscanf(fin,"%[^\n]%*c",&cmd);

        //printf("\n\ncmd: %s\n",cmd);
        char strid[20] = "";
        char toy[20] = "";
        int lastid, lasttoy = strlen(cmd);
        int i;
        for (i = 0; i < strlen(cmd); i++)
        {
			if (isdigit(cmd[i])){
				//printf("i = %d\n",i);
				lastid = i;
			}
        	if ((cmd[i] > 'a' && cmd[i] <'z') || (cmd[i] > 'A' && cmd[i] < 'Z'))
        	{
        		//printf("k = %d\n",i);
        		if (lasttoy > i)
        			lasttoy = i;
			}
    	}

    	strcpy(strid, cmd);
    	strid[lastid+1] = '\0';
    	int id = atoi(strid); //Id value is correctly assigned
    	
    	strcpy(toy, &cmd[lasttoy]); //Toy value is correctly assigned
        if (strlen(toy) == 0){
            printf("Nhap them thong tin cho id %d: ",id);
            scanf("%[^\n]%*c",&toy);
        }
    	
    	arr[count].id = id;
        strcpy(arr[count].toy, toy);
        count++;
    }
    arrsize = count;
    int k;
    for (k = 0; k < arrsize;k++)
        printf("%d\t%s\n",arr[k].id, arr[k].toy);
    printf("\nDoc file thanh cong\n");
    fflush(stdin);
}
///////////////////////////////////////////////
//***********************
Tree *minValueNode(Tree *root){
    Tree *current = root;

    while(current && current->left != NULL)
        current = current->left;

    return current;
}

Tree *deleteNode(Tree *root, int key){
    if (root == NULL)
        return root;

    if (key < root->id)
        root->left = deleteNode(root->left, key);
    
    else if (key > root->id)
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
        
        root->id = temp->id;
        strcpy(root->toy,temp->toy);
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}
//**********************

int checkf3 = 0;

void func3(){
    if (checkf1 == 0 || checkf2 == 0){
        printf("Chua chay ca 2 chuong trinh 1 va 2!\n");
        return;
    }
    printf("\nTIM KIEM\n");
    checkf3 = 1;
    int i;
    for (i = 0; i < arrsize; i++){
        Tree *f = treesearch(RA, arr[i].id);
        if (f != NULL){
            printf("Thong tin bi trung:\n");
            printf("%d\t%s\n",f->id, f->toy);
            RA = deleteNode(RA, f->id);
        }
    }
    system("cls");
    printf("Danh sach cay A:\n");
    inorderprint(RA);
    fflush(stdin);
}

////////////////////
void printf4(Tree *root){
	if (root == NULL) return;
	else {
		printf4(root->right);
		printf("%d\t%s\n",root->id, root->toy);
		printf4(root->left);
	}
}

int checkf4 = 0;

void func4(){
    if (checkf3 == 0) {
        printf("Chua chay chuc nang 3!\n");
        return;
    }
    printf("\nTONG HOP\n");
    checkf4 = 1;
    int i;
    for (i = 0; i < arrsize; i++){
        RA = treeinsert(RA, arr[i].id, arr[i].toy);
    }
    printf4(RA);
    //printf("\n");
    //inorderprint(RA);
    printf("Tong hop thanh cong\n");
    fflush(stdin);
}

///////////////////////////////////////
int statistic(Tree *root, char toytarget[]){
    if (root == NULL) return 0;
    if (strstr(root->toy, toytarget) != NULL) return 1;
    return statistic(root->left, toytarget)+statistic(root->right, toytarget);
}

void func5(){
    if (!checkf4){
        printf("Chua chay chuc nang 4!\n");
        return;
    }
    printf("\nTHONG KE\n");
    int i;
    printf("%s\t%d\n","maybay",statistic(RA,"mayba"));
    printf("%s\t%d\n","dientu",statistic(RA,"dient"));
    printf("%s\t%d\n","oto",statistic(RA,"ot"));
    printf("%s\t%d\n","gaubong",statistic(RA,"gaubon"));
    printf("Thong ke thanh cong!\n");
    fflush(stdin);
}

int main (){
    while (1){
        printf("\n==================\n");
        printf("1. Doc file A\n");
        printf("2. Doc file B\n");
        printf("3. Tim kiem\n");
        printf("4. Tong hop\n");
        printf("5. Thong ke\n");
        printf("6. Thoat\n");
        printf("==================\n");
        char cmd[128];
        printf("Chon chuc nang > "); scanf("%[^\n]%*c",&cmd);
        if (strcmp(cmd, "1") == 0)
            func1();
        else if (strcmp(cmd,"2") == 0)
            func2();
        else if (strcmp(cmd,"3") == 0)
            func3();
        else if (strcmp(cmd,"4") == 0)
            func4();
        else if (strcmp(cmd,"5") == 0)
            func5();
        else if (strcmp(cmd,"6") == 0){
            printf("\nChuong trinh dung lai thanh cong!\n");
            freetree(RA);
            return 0;
        }
        else {
            printf("\nMoi nhap lai!\n");
        }
    }
}
