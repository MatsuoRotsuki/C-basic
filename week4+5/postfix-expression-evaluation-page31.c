#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ITEM;
int N;
ITEM *s;

void Stack_init(int maxN){
    s = (ITEM *)malloc(maxN * sizeof(ITEM));
}

int Stack_empty()
{
    return (N == 0);
}

void Stack_push(ITEM x)
{
    s[N++] = x;
}

ITEM Stack_pop()
{
    return s[--N];
}

int main (int argc, char *argv[])
{
    char *a = argv[1];
    int i;
    N = strlen(a);
    printf("%d",N);
    Stack_init(N);
    for (i = 0; i < N; i++){
        if (a[i] == '+')
            Stack_push(Stack_pop() + Stack_pop());
        if (a[i] == '*')
            Stack_push(Stack_pop() * Stack_pop());
        if ((a[i] >= '0') && (a[i] <= '9'))
            Stack_push(10 * Stack_pop() + (a[i++]-'0'));
    }
    printf("%d\n", Stack_pop());
}