#include<stdio.h>
#define MAX=5;
void push(int s[],int *top,int *item){
    if(*top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        s[++(*top)]=item;
    }
}
void pop(int s1[],int s2[],int*top1,int*top2){
    if(*top1==-1){
        printf("Stack Underflow\n");
    }
    else{
        (*top)--;
        if(*top==0){
            push(s2[],&top2,&top1);
            return *top1;
        }
    }
}
void display(int s[],int*top){
    if(*top==MAX-1){
        printf("Stack Overflow\n");
    }
    for(int i=0;i<*top;i++){
        printf("%d ",s[i]);
    }
}

int main(){
    int s[MAX],s2[MAX],top1=-1,top2=-1,item;
    
}