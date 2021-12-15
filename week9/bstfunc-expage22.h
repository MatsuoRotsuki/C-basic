#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char tel[15];
    char email[50];
} ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
} Tree;

void freetree(Tree *root){
    if (root == NULL) return;
    freetree(root->left);
    freetree(root->right);

    free(root);
}

Tree *create (ElementType x){
    Tree *newnode = (Tree*)malloc(sizeof(Tree));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int treeheight(Tree *root){
    if (root == NULL) return 0;
    else {
        int lDepth = treeheight(root->left);
        int rDepth = treeheight(root->right);
        if (lDepth > rDepth) return 1+lDepth;
        else return 1+rDepth;
    }
}

int treeleaf(Tree *root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    else return treeleaf(root->left)+treeleaf(root->right);
}

int treeinternalnode(Tree *root){
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1+treeinternalnode(root->left)+treeinternalnode(root->right);
}

int treerightchildcount(Tree *root){
    if (root == NULL) return 0;
    int selfCount = (root->right != NULL) ? 1 : 0;
    return selfCount + treerightchildcount(root->right)+ treerightchildcount(root->left);
}

int treeleftchildcount(Tree *root){
    if (root == NULL) return 0;
    int selfCount = (root->left != NULL) ? 1 : 0;
    return selfCount + treeleftchildcount(root->left) + treeleftchildcount(root->right);
}

Tree *treeinsert(Tree *root ,ElementType key){
    if(root == NULL){
        root = create(key);
        return root;
    }
    if(root->data < key) {
        root->right = treeinsert(root->right,key);
    } else {
        root->left = treeinsert(root->left, key);
    }
    return root;
}

// ElementType DeleteMin(Tree *root){
//     ElementType k;
//     if (root->left == NULL){
//         k = root->data;
//         root=root->right;
//         return k;
//     }
//     else return DeleteMin(root->left);
// }

void prettyprint(Tree *root){
    if (root == NULL) return;
    printf("%c ",root->data);
    prettyprint(root->left);
    prettyprint(root->right);
}

void inorderprint(Tree *root){
	if (root == NULL) return;
	else {
		inorderprint(root->left);
		printf("%4c",root->data);
		inorderprint(root->right);
	}
}

void postorderprint(Tree *root){
	if (root == NULL) return;
	else {
		postorderprint(root->left);
		postorderprint(root->right);
		printf("%4c",root->data);
	}
}

void preorderprint(Tree *root){
	if (root == NULL) return;
	else {
		printf("%4c",root->data);
		preorderprint(root->left);
		preorderprint(root->right);
	}
}


