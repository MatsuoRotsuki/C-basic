#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recurTriangle(int n, char ch){
    if (n == 0) return;
    else {
        int i;
        for (i = 0; i < n; i++)
            printf("%c",ch);
        printf("\n");
        recurTriangle(n-1, ch);
    }
}

int main (){
    recurTriangle(50,'1');
    return 0;
}
