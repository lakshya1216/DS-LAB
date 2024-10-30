#include<stdio.h>
#define MAX 5
int push(int stack[],int *top,int value){
    if(*top >= MAX - 1){
        printf("Stack Overflow");
        return 0;
    }
    else{
        (*top)++;
        stack[*top]=value;
        printf("Pushed the Value\n");
    }
}
int pop(int stack[],int*top){
    if(*top == -1){
        printf("Stack Underflow");
        return 0;
    }
    (*top)--;
    printf("popped the value\n");
}
void display(int stack[],int *top){
    if(*top==-1){
        printf("Stack Underflow");
        
        
    }
    for(int i=0;i<=*top;i++){
        printf("%d\n",stack[i]);
        
    }
}

int main()
{
    int stack[MAX];
    int top = -1;

    push(stack,&top,3);
    push(stack,&top,4);
    push(stack,&top,5);
    push(stack,&top,6);
    push(stack,&top,6);
    push(stack,&top,6);
    display(stack,&top);

    pop(stack,&top);
    pop(stack,&top);
    pop(stack,&top);
    pop(stack,&top);
    pop(stack,&top);
    pop(stack,&top); 
 
    display(stack,&top);
    return 0;
}