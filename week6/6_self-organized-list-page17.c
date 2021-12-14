#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int *a[],int n, int key){
    int i, j;
    int tempr;
    for (i = 0; i <n-1 && *(a+i) != key; i++);
    if (key == *(a+i))
    {
        if (i > 0){
            tempr = *(a+i);
            for (j = i-1; j >= 0; j--){
                *(a+j+1) = *(a+j);
            } 
            *a = tempr;
        }
        return i;
    } else return -1;
}

int main (){
    int a[11];
    int i;
    for (i = 0; i < 10; i++){
        scanf("%d",&a[i]);
    }
    int count = -1;
    scanf("%d",&a[10]);
    printf("%d",search(&a,10,a[10]));
    return 0;
}