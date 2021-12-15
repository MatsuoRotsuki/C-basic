#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include <time.h>
#define MAX 20
/*Create an binary search tree with 10
nodes. Each node contains an
random integer.
• Ask user to input an number and
search for it.
• Print the content of the trees. */

/*SOLUTION in slide page 47
#include <stdio.h>
#include <stdlib.h>
#include <bsttree.h> // create by your self
#include <time.h>
int main(){
TreeType p, tree = NULL;
int i, n = 0;
srand(time(NULL));
for ( i = 0; i < 10; i++ )
insert (rand() % 100, tree );
printf("pretty print:\n");
strcpy(prefix," ");
prettyprint(tree,prefix);
printf("\n");
do {
printf("Enter key to search (-1 to quit):");
scanf("%d", &n);
p= Search(n, tree);
if (p!=NULL) printf("Key %d found on the tree",n);
else insert(n, tree);
while (n!=-1);
return 0;
}*/

int main (){
    Tree *root = NULL;
    int i,n = 0;
    root = create(4);
    printf("%d",treeheight(root));
    freetree(root);
    return 0;
}
