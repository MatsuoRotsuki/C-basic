// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
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
    struct Stack* stack = (struct Stack*)
           malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity *
                                   sizeof(int));
 
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

int value(char c) {  return (c - '0'); }
 
// This function evaluates simple expressions. It returns -1 if the
// given expression is invalid.
int evaluate(char *exp)
{
    // Base Case: Given expression is empty
    if (exp == '\0')  return -1;
 
    // The first character must be an operand, find its value
    int res = value(exp[0]);
 
    // Traverse the remaining characters in pairs
    for (int i = 1; exp[i]; i += 2)
    {
        // The next character must be an operator, and
        // next to next an operand
        char opr = exp[i], opd = exp[i+1];
 
        // If next to next character is not an operand
        if (!isOperand(opd))  return -1;
 
        // Update result according to the operator
        if (opr == '+')       res += value(opd);
        else if (opr == '-')  res -= value(opd);
        else if (opr == '*')  res *= value(opd);
        else if (opr == '/')  res /= value(opd);
 
        // If not a valid operator
        else return -1;
    }
    return res;
}

int main()
{
    char exp[50]; //"a+b*(c^d-e)^(f+g*h)-i";->abcd^e-fgh*+^*+i-
    printf("Enter infix expression: ");
    scanf("%s",&exp);
    printf("Postfix notation: ");
    infixToPostfix(exp);
    
    printf("\nEvaluation the expression: ");
    int res = evaluate(exp);
    printf("%d",res);
    return 0;
}