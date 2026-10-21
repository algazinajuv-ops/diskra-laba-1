#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int findvar(char *formula, char *var)
{
    int count=0;

    for (int i =0; formula[i] != '\0'; i++)
    {
        char c = formula[i];

        if (c >= 'a' && c<= 'z')
        {
            c = c-'a'+'A';
        }
        if (c >= 'A' && c<= 'Z')
        {
            int exist = 0;
            for (int j=0; j <count; j++)
            {
                if (var[j]==c)
                {
                    exist = 1;
                    token_var = 
                    break;
                }
            }

            if (!exist)
            {
                var[count] = c;
                count++;
            }
        }

    }
    return count;
}

typedef struct {
    char op[4];
    int is_operator;
    int value;
} Token;


typedef enum {
    token_var,
    token_cons,
    token_op,
    token_lparen,
    token_rparen
} TokenType;




Token op_stack[MAX_STACK];
int top = -1


void push_op(Token t){
    op_stack[++top] = t;
}

Token pop_op(){
    return op_stack[top--];
}
Token peek_op(){
    return op_stack[top];
}
int is_empty(){
    return top == -1;
}

int priority(char operator)
{
    if (operator == '!'){
        return 5;}
    if (operator == '*'){
        return 4;}
    if (operator =='^'){
        return 3;}
    if (operator == '+'){
        return 2;}
    if (operator == '='){
        return 1;}
    if (operator == '>' || operator == '<' || operator == '%'|| operator == '|'){
        return 1;
    }

    return 0;
}

int opn(char* infix, Token* opn_out, int* opn_count)
{
    *opn_count = 0;
    top = -1;
    for (int i =0; infix[i] != '\0'; i++){
        char c = infix[i];
        if (isspace(c)) continue;

        Token t;
        t.is_operator = 0
        t.value = -1;
        memset(t.op, 0, sizeof(t.op));

        if (isdigit(c)){
            t.value = c - '0';
            opn_out[(*opn_count)++] = t;

        } else if (c == '('){
            t.is_operator = 1
        }
    }

}

