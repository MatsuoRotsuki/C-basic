#include <stdio.h>
#include "bstfunc-char.h"

int main (){
	Tree *root = create('J');
	root->left = create('E');
	root->left->left = create('A');
	root->left->right = create('H');
	root->right = create('T');
	root->right->left = create('M');
	root->right->right = create('Y');
	preorderprint(root);
	//printf("\nHeight of tree = %d",treeheight(root));
	freetree(root);
}
