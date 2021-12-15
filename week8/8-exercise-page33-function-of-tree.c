#include <stdio.h>
#include <stdlib.h>
//#include "binarytree.h"
/*Develop the following helper
functions for a tree:
– return the height of a binary tree.
– return the number of leafs
– return the number of internal nodes
– count the number of right children.*/

typedef int ElementType;

typedef struct TreeNode{
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

Tree *create(ElementType data){
	Tree *newnode = (Tree *)malloc(sizeof(Tree));
	if (newnode == NULL) {
		printf("Memory Allocation Error!\n");
		exit(0);
	}
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int TreeHeight (Tree *root){
    if (root == NULL) return 0;
    else {
        int lDepth = TreeHeight(root->left);
        int rDepth = TreeHeight(root->right);
        
        if (lDepth > rDepth) return 1+lDepth;
        else return 1+rDepth;
    }
}

int treeLeaf(Tree *root){
    if (root==NULL) return 0;
    if (root->left == NULL || root->right == NULL) return 1;
    else return treeLeaf(root->left)+treeLeaf(root->right);
}

int internalNodes(Tree *root){
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1+internalNodes(root->left) + internalNodes(root->right);
}

int rightchildren(Tree *root){
	if (root == NULL) return 0;
	int selfCount = (root->right != NULL) ? 1 : 0;
	return selfCount + rightchildren(root->left) + rightchildren(root->right);
}

int main (){
	Tree *root = create(6);
	root->left = create(3);
	root->right = create(8);
	root->left->left = create(1);
	root->left->right = create(4);
	root->right->right = create(9);
	root->right->left = create(7);
    root->right->right->right = create(10);
	
	printf("Height of tree = %d\n",TreeHeight(root));
	printf("Number of leaves = %d\n",treeLeaf(root));
	printf("Number of internal leaves = %d\n",internalNodes(root));
	printf("Number of right children = %d\n",rightchildren(root));
	freetree(root); 
	return 0;
}