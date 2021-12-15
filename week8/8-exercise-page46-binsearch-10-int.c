#include <stdio.h>
#include <stdlib.h>
#include "binarytree-int.h"
/*
Exercise 
• Create an binary search tree with 10 
nodes. Each node contains an 
random integer. 
• Ask user to input an number and 
search for it.
• Print the content of the trees.
*/
ElementType X[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int checkifexist(ElementType k){
    int i;
    for (i = 0 ; i < 10; i++){
        if (X[i] == k) return 1;
    }
    return 0;
}

int count;

Tree *treeinsert2(Tree *root, int key) {
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

int main (){
    Tree *r = NULL;
    int i,n;
    for (count = 0 ; count < 10;) {
        n = rand()%50;
        if (!checkifexist(n)){
            r = treeinsert2(r, n);
            X[count++] = n;
        }
    }
    
    printf("Enter an integer that you want to search: ");
    scanf("%d",&i);
    Tree *found = treesearch(r, i);
    if(found == NULL) printf("Not Found!\n");
    else printf("Found!\n");

    inorderprint(r);
    freetree(r);
    return 0;
}