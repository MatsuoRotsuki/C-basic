#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    NAME_LENGTH = 30,
    TEL_LENGTH = 15,
    EMAIL_LENGTH = 50,
};

typedef struct {
    char name[NAME_LENGTH];
    char tel[TEL_LENGTH];
    char email[EMAIL_LENGTH];
} Address;

typedef struct TreeNode {
    Address data;
    struct TreeNode *left;
    struct TreeNode *right;
} Tree;

void freetree(Tree *root){
    if (root == NULL) return;
    freetree(root->left);
    freetree(root->right);

    free(root);
}

void inthongtin(Address temp){
    printf("Name: %s\n",temp.name);
    printf("Tel: %s\n",temp.tel);
    printf("Email: %s\n",temp.email);
}

Tree *create (Address x){
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

Tree *treesearch(Tree *root ,char x[]){
    if (root == NULL) return NULL;
    if (strcmp(root->data.name, x)  == 0) return root;
    if (strcmp(root->data.name, x) < 0) return treesearch(root->right, x);
    else return treesearch(root->right, x);
}

Tree* treeinsert(Tree *root, Address key){ //Iterative Algorithm
    Tree* newnode = create(key);
    Tree* x = root;
    Tree* y = NULL;
    while(x != NULL){
        y = x;
        if (strcmp(key.name, x->data.name) < 0) x = x->left;
        else x = x->right;
    }
    if (y == NULL) y = newnode;
    else if (strcmp(key.name, y->data.name) < 0) y->left = newnode;
    else y->right = newnode;
    return y;
}

Tree *treeinsert2(Tree *root, Address key) { //Recursive Algorithm
    if(root == NULL){
        root = create(key);
        return root;
    }
    if(strcmp(root->data.name , key.name) < 0) {
        root->right = treeinsert2(root->right,key);
    } else {
        root->left = treeinsert2(root->left, key);
    }
    return root;
}

void inorderprint(Tree *root){
	if (root == NULL) return;
	else {
		inorderprint(root->left);
		inthongtin(root->data);
		inorderprint(root->right);
	}
}

void postorderprint(Tree *root){
	if (root == NULL) return;
	else {
		postorderprint(root->left);
		postorderprint(root->right);
		inthongtin(root->data);
	}
}

void preorderprint(Tree *root){
	if (root == NULL) return;
	else {
		inthongtin(root->data);
		preorderprint(root->left);
		preorderprint(root->right);
	}
}