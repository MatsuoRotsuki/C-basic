#include <stdio.h>
#include <stdlib.h>
#include "binarytree-int.h"

Tree *search(Tree *root, ElementType x){
    if (root == NULL|| root->data == x){
        if (root == NULL) printf("NOT FOUND!\n");
        else printf("FOUND!\n");
        return root;
    }
    if (root->data < x) return treesearch(root->right, x);
    else return treesearch(root->right, x);
}

int main (){
    Tree *r = NULL;
    r = treeinsert2(r, 5);
    r = treeinsert2(r, 6);
    Tree *f = search(r, 6);
    freetree(r);
}