#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack-char.h"

void postconversion(char X[]){
//Giong ham main
}

int main (){
    int i;
    Stack *s = createStack();
    char x[20]="3+5*4";
    int n = strlen(x);
    for (i = 0; i < n; i++){
        if (x[i] >= '0' && x[i] <= '9'){
            printf("%c",x[i]);//Is operand
        }
        
        else if(x[i] == '(') push (s,x[i]);

        else if(x[i] == '+' || x[i] == '-')
        {
            
            push(s,x[i]);
        }

        else if (x[i] == '/' || x[i] == '*')
        {

            push(s,x[i]);
        }
    }
    while(!isEmpty(s)) printf("%c",pop(s));
    StackDestroy(s);
    return 0;
}