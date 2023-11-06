#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20

struct stack
{
    int top;
    int str[MAX];
} s;

char postfix[MAX];

void push(int);
int pop();
int isoperand(char);
int operate(int, int, char);

int main()
{
    int i = 0;
    printf("Enter Expression : ");
    scanf("%s", postfix);

    int ans, op1, op2;
    while (postfix[i] != '\0')
    {
        if (isoperand(postfix[i]))
            push(postfix[i] - 48);
        else
        {
            op1 = pop();
            op2 = pop();
            ans = operate(op1, op2, postfix[i]);
            push(ans);
            printf("%d %c %d = %d\n", op2, postfix[i], op1, ans);
        }
        i++;
    }
    printf("%d", s.str[s.top]);
    return 0;
}

int isoperand(char x)
{
    if(x>='0' && x<='9')
        return 1;
    else
        return 0;
}

void push(int x)
{
    if (s.top == MAX - 1)
        printf("Stack is full\nStack Overflow\n");
    else
    {
        s.top++;
        s.str[s.top] = x;
    }
}

int pop()
{
    if(s.top==-1)
    {
        printf("Stack is empty\nSTACK UNDERFLOW\n");
    }
    else
    {
        s.top--;
        return s.str[s.top+1];
    }
}

int operate(int op1,int op2,char a)
{
    switch (a)
    {
        case '+':
            return op2 + op1;
        case '-':
            return op2 - op1;
        case '*':
            return op2 * op1;
        case '/':
            return op2 / op1;
        case '^':
            return pow(op2, op1);
    }
}