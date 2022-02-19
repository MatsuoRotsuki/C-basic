#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

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

Tree *treesearch(Tree *root ,ElementType x){
    if (root == NULL|| root->data == x)
        return root; 
    if (root->data < x)
        return treesearch(root->right,x);
    else return treesearch(root->left,x);
}

Tree *treeinsert2(Tree *root, int key) { //Recursive Algorithm
    if(root == NULL){
        root = create(key);
        return root;
    }
    if(root->data < key) {
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
		printf("%4d",root->data);
		inorderprint(root->right);
	}
}

void postorderprint(Tree *root){
	if (root == NULL) return;
	else {
		postorderprint(root->left);
		postorderprint(root->right);
		printf("%4d",root->data);
	}
}

void preorderprint(Tree *root){
	if (root == NULL) return;
	else {
		printf("%4d",root->data);
		preorderprint(root->left);
		preorderprint(root->right);
	}
}

int main (){
    Tree *r = NULL;
//    r = treeinsert2(r, 8);
//    r = treeinsert2(r, 3);
//    r = treeinsert2(r,10);
//    r = treeinsert2(r, 1);
//    r = treeinsert2(r, 6);
//    r = treeinsert2(r, 4);
//    r = treeinsert2(r, 7);
//    r = treeinsert2(r,14);
//    r = treeinsert2(r,13);
	int i;
	for (i = 0; i < 17; i++){
		Tree *f = treesearch(r, i);
    	if (f == NULL) printf("\n%d NOT FOUND\n",i);
    	else printf("\n%d FOUND\n",i);
	}
    inorderprint(r);
    printf("\n");
    preorderprint(r);
    freetree(r);
}
