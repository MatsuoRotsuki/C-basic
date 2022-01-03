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

Tree *treesearch(Tree *root ,ElementType x){
    if (root == NULL|| root->data == x) return root;
    if (root->data < x) return treesearch(root->right, x);
    else return treesearch(root->right, x);
}

Tree* treeinsert(Tree *root, ElementType key){ //Iterative Algorithm
    Tree* newnode = create(key);
    Tree* x = root;
    Tree* y = NULL;
    while(x != NULL){
        y = x;
        if (key < x->data) x = x->left;
        else x = x->right;
    }
    if (y == NULL) y = newnode;
    else if (key < y->data) y->left = newnode;
    else y->right = newnode;
    return y;
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
    printf("%d ",root->data);
    prettyprint(root->left);
    prettyprint(root->right);
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