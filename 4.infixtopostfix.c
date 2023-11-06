#include <stdio.h>
#include <ctype.h>
#define SIZE 50
char s[SIZE];
char top = -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':case '/':
        case '%':return 3;
        case '^':return 4;
    }
}

void main()
{
    char infx[50], pofx[50], ch, elem;
    int i = 0, k = 0;
    printf("\n\nRead the infix expression:");
    scanf("%s", infx);
    push('#');
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofx[k++] = ch;
            else if (ch == ')')
            {
                while (s[top] != '(')
                    pofx[k++] = pop();
                    elem = pop();
            }
            else
            {
                while (pr(s[top]) >= pr(ch))
                    pofx[k++] = pop();
                    push(ch);
            }
    }
    while(s[top] != '#')
        pofx[k++] = pop();
        pofx[k] = '\0';
        printf("\nGiven infix expn:%s \npostfix expn:%s\n", infx, pofx);
}
