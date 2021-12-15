#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct NodeType{
    ElementType data;
    struct NodeType *l;
    struct NodeType *r;
} Tree;

int isEmpty(Tree *root){
    int i;
}

int TreeHeight(Tree *root){
    if(root == NULL) return -1;
    else {
        int lDepth=TreeHeight(root->l);
        int rDepth=TreeHeight(root->r);
        if (lDepth > rDepth)
            return lDepth + 1;
        else return rDepth + 1;
    }    
}

int treeLeaf(Tree *root){
    if (root == NULL) return 0;
    if (root->l == NULL && root->r == NULL) return 1;
    else return treeLeaf(root->l) + treeLeaf(root->r);
}

Tree *create(ElementType data){
	Tree *newnode = (Tree *)malloc(sizeof(Tree));
	if (newnode == NULL) {
		printf("Memory Allocation Error!\n");
		exit(0);
	}
	newnode->data = data;
	newnode->l = NULL;
	newnode->r = NULL;
	return newnode;
}

int internalNodes(Tree *root){
	if (root == NULL || (root->l == NULL && root->r == NULL))
		return 0;
	return 1+internalNodes(root->l)+internalNodes(root->r);
}

int rightchildren(Tree *root){
	if (root == NULL) return 0;
	int selfCount = (root->r != NULL) ? 1 : 0;
	return selfCount + rightchildren(root->l) + rightchildren(root->r);
}

void freetree(Tree *root){
	if (root==NULL) return;
	freetree(root->l);
	freetree(root->r);
	
	free(root);
}

Tree *Search(ElementType X, Tree *root){
	if (root == NULL || root->data == X) return root;
	if (root->data < X)
	    return Search(X, root->r);
	else {
		return Search(X,root->l);
	}
}

void InsertNode(ElementType X, Tree *root){
	if (root == NULL){
		root = create(X);
		root->l = NULL;
		root->r = NULL;
	}
	else if (X < root->data) InsertNode(X, root->l);
	else if (X > root->data) InsertNode(X, root->r);
}

ElementType DeleteMin(Tree *root){
	ElementType k;
	if (root->l == NULL){
		k = root->data;
		root=root->r;
		return k;
	}
	else return DeleteMin(root->r);
}

int main (){
	Tree *root = create(6);
	root->l = create(3);
	root->r = create(8);
	root->l->l = create(1);
	root->l->r = create(4);
	root->r->r = create(9);
	root->r->l = create(7);
	
	printf("%d",TreeHeight(root));
	//Tree *node = Search(4, root);
	//printf("%d",node->data);
	freetree(root); 
	return 0;
}
