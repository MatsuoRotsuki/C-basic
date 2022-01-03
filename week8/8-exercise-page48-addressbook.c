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



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree-telephonebook.h"
// enum{
//     NAME_LENGTH = 30,
//     TEL_LENGTH = 15,
//     EMAIL_LENGTH = 50,
// };

// typedef struct {
//     char name[NAME_LENGTH];
//     char tel[TEL_LENGTH];
//     char email[EMAIL_LENGTH];
// } Address;

Address Data[10];


// void input(){
//     for (int i = 0; i < 10; i++){
//         printf("NAME: ");scanf("%s", Data[i].name);
//         printf("TEL: ");scanf("%s", Data[i].tel);
//         printf("EMAIL: "); scanf("%s", Data[i].email);
//     }
// }

// void taofile(){
//     FILE *fin = fopen("input.dat","wb");
//     int irc = fwrite(Data, sizeof(Address), 10, fin);
//     fclose(fin);
// }
int n;

void docfile(){
    FILE *fin = fopen("input.dat","rb");
    int irc = fread(Data, sizeof(Address), 10, fin);
    n = irc;
    printf("%d\n",irc);
    for (int i = 0; i < irc; i++){
        printf("Name: %s\n",Data[i].name);
        printf("Tel: %s\n",Data[i].tel);
        printf("Email: %s\n",Data[i].email);
    }
    fclose(fin);
}

int main (){
    docfile();
    printf("\n------------------------------\n");
    Tree *root = NULL;
    for (int i = 0; i < n; i++) root = treeinsert2(root, Data[i]);
    inorderprint(root);
    printf("\n------------------------------\n");
    printf("Search for: ");
    char target[NAME_LENGTH];
    scanf("%s", &target);
    Tree *found = treesearch(root, target);
    printf("\nResult:\n");
    if (found != NULL) inthongtin(found->data);
    else printf("NOT FOUND!\n");
    freetree(root);
    return 0;
}

// Điểm thiếu sót: Binary Search Tree không hoạt động