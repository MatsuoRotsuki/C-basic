#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int a[11];
    int i;
    for (i = 0; i < 10; i++){
        scanf("%d",&a[i]);
    }
    int count = -1;
    scanf("%d",&a[10]);
    for (i = 0; i < 10; i++){
        if (a[i] == a[10]) {
            printf("\nindex = %d", i);
            count++;
        }
    }
    if (count == -1) printf("\n0");
    return 0;
}