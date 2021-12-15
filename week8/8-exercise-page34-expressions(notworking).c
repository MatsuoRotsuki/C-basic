#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
• A binary can represent an arithmetic expression:
The leaves are operands and the other nodes are
operators.
• The left and right subtrees of an operator node
represent subexpressions that must be evaluated
before applying the operator at the root of the
subtree.
• For example
!a + (b – c)/d
• Write a program create a tree
representing this expression*/

//-----------------------------------------
typedef char ElementType;

typedef struct TreeNode{
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
} Tree;

Tree *create(ElementType x){
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void freetree(Tree *root){
    if (root == NULL) return;
    //printf("%c",root->data);
    freetree(root->left);
    freetree(root->right);
    free(root);
}
//--------------------------------------- TREE IMPLEMENTATION DONE
// IMPLEMENTATION OF EVALUATING THE EXPRESSION
// Contribution needed, for C++ file containing algorithm, please see 8-exercise-page34-evaluation-expression.cpp 

//----------------------------------------
int main (){
    Tree *root = create('+');
    root->left = create('!');
    root->left->left = create('a');
    root->right = create('/');
    root->right->left = create('-');
    root->right->right = create('d');
    root->right->left->left = create('b');
    root->right->left->right = create('c');
    
    freetree(root);
    return 0;
}
