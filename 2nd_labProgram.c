#include<stdio.h>
#define MAX 5
void push(int stack[],int *top,char ele){
    *top++;
    stack[*top] = ele;
}
void pop(int stack[],int *top){
    return stack[*top--];
}
int pr(int stack[],int *top,char op){
    switch(op){
        case '#': return 0;
                break;
        case '(': return 1;
        break;
        case '+': return 2;
        break;
        case '-': return 2;
        break;
        case '*': return 3;
        break;
        case '/': return 3;
        break;
        default: return 0;
        break;  
    }
}
int main(){
    char infix[MAX],postfix[MAX],stack[MAX],int top=0,char ch;
    int count=0;
    printf("Enter the infix expression:");
    scanf("%s",infix);
    push(stack[],&top,'#');
    int i;
    while(infix[i])
