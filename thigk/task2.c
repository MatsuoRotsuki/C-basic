// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity *sizeof(int));
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}
 
// A utility function to check if
// the given character is operand
int isOperand(char c) { return (c >= '0' && c <= '9'); }
 
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
int infixToPostfix(char* exp)
{
    int i, k;
 
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression            
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) &&
                 Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
    while (!isEmpty(stack))
        exp[++k] = pop(stack );
 
    exp[++k] = '\0';
    printf( "%s", exp);
}

int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    int i;
 
    // See if stack was created successfully
    if (!stack) return -1;
 
    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
 
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char exp[50]; //"a+b*(c^d-e)^(f+g*h)-i";->abcd^e-fgh*+^*+i-
    printf("Enter infix expression(e.g 3+5*4): ");
    scanf("%s",&exp);
    printf("Postfix notation: ");
    infixToPostfix(exp);
    printf("\nEvaluation the expression: ");
    printf("%d",evaluatePostfix(exp));
    return 0;
}