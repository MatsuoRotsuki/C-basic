/*We assume that you make a mobile phone’s address book.
• Declare a structure which can store at least "name", "telephone
number", "e-mail address.”.
• Declare a structure for a binary tree which can stores the
structure of an address book inside. Read data of about 10 from
an input file to this binary tree as the following rules.
– An address data which is smaller in the dictionary order for the e-mail
address is stored to the left side of a node.
– An address data which is larger in the dictionary order for the e-mail
address is stored to the right side of a node.
• (1) Confirm the address data is organized in the binary tree
structure with some methods (printing, debugger, etc).
• (2) Find a specified e-mail address in the binary tree and output it
to a file if found.
• (3) Output all the data stored in the binary tree in ascending
order for the e-mail address. (Reserve it for the next week)*/


/*SOLUTION from slide page 49 to 53

SEARCH FUNCTION
TreeType Search(char* email,TreeType Root){
if (Root == NULL) return NULL; // not found
else if (strcmp((Root->Key).email, email) == 0)
return Root;
else if (strcmp((Root->Key).email, email) < 0)
//continue searching in the right sub tree
return Search(email,Root->right);
else {
// continue searching in the left sub tree
return Search(email,Root->left);
}
}

INSERT A NODE
void InsertNode(phoneaddress x,TreeType *Root ){
if (*Root == NULL){
*Root=(NodeType*)malloc(sizeof(NodeType));
(*Root)->Key = x;
(*Root)->left = NULL;
(*Root)->right = NULL;
}
else if (strcmp(((*Root)->Key).email, x.email) > 0)
InsertNode(x, (*Root)->left);
else if (strcmp(((*Root)->Key).email, x.email) > 0)
InsertNode(x,(*Root)->right); 

int main(void)
{
FILE *fp;
phoneaddress phonearr[MAX];
treetype root;
int i,n, irc; // return code
int reval = SUCCESS;
int n=10;
//read from this file to array again
if ((fp = fopen("phonebook.dat","rb")) == NULL){
printf("Can not open %s.\n", "phonebook.dat");
reval = FAIL;
}
irc = fread(phonearr, sizeof(phoneaddress), n,
fp);
fclose(fp);
....;
for (i=0; i<n; i++)
root = InsertNode(phonearr[i],root);
pretty_print(root,0);
// Search for an email
// Do it by your self
. . .
}
*/


#include <stdio.h>